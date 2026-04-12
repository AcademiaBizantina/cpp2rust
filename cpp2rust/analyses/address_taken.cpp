// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include "address_taken.h"

#include <clang/AST/Expr.h>
#include <clang/AST/OperationKinds.h>

namespace cpp2rust {
bool AddressTakenVisitor::TraverseInitListExpr(clang::InitListExpr *Expr) {
  for (auto *Init : Expr->inits()) {
    const auto *ImplicitCast = clang::dyn_cast<clang::ImplicitCastExpr>(Init);
    if ((ImplicitCast != nullptr) &&
        (ImplicitCast->getCastKind() == clang::CK_LValueToRValue)) {
      // If the initializer is an implicit cast of kind CK_LValueToRValue, we
      // skip visiting the subexpression.

      continue;
    }
    TraverseStmt(Init);
  }

  return true;
}

bool AddressTakenVisitor::TraverseCXXMemberCallExpr(
    clang::CXXMemberCallExpr *Expr) {
  if (auto *BaseExpr = Expr->getImplicitObjectArgument()) {
    if (dyn_cast<clang::DeclRefExpr>(BaseExpr->IgnoreParenImpCasts())) {
      // If the base of the member call is a DeclRefExpr, skip traversing it
      // but visit its arguments

      for (auto *Arg : Expr->arguments()) {
        TraverseStmt(Arg);
      }

      return true;
    }
  }

  return RecursiveASTVisitor::TraverseCXXMemberCallExpr(Expr);
}

bool AddressTakenVisitor::TraverseCXXOperatorCallExpr(
    clang::CXXOperatorCallExpr *Expr) {
  if (Expr->isAssignmentOp() && Expr->getNumArgs() == 2) {
    const auto *DeclRef = clang::dyn_cast<clang::DeclRefExpr>(Expr->getArg(0));
    if (DeclRef != nullptr) {
      // If the left-hand side of an assignment is a DeclRefExpr, we skip
      // visiting the left-hand side.
      RecursiveASTVisitor::TraverseStmt(Expr->getArg(1));

      return true;
    }

    const auto *ArraySubscript =
        clang::dyn_cast<clang::ArraySubscriptExpr>(Expr->getArg(0));
    if (ArraySubscript != nullptr) {
      // If the left-hand side of an assignment is an ArraySubscriptExpr, we
      // skip visiting the left-hand side.
      RecursiveASTVisitor::TraverseStmt(Expr->getArg(1));

      return true;
    }

    return true;
  } else if (Expr->getOperator() == clang::OO_Star ||
             Expr->getOperator() == clang::OO_Subscript) {
    if (Expr->getNumArgs() > 0) {
      auto *BaseExpr = Expr->getArg(0);
      if (clang::dyn_cast<clang::DeclRefExpr>(
              BaseExpr->IgnoreParenImpCasts())) {
        // If the base of the operator call is a DeclRefExpr, skip traversing it
        // but visit its other arguments (if any).

        for (size_t i = 1; i < Expr->getNumArgs(); ++i) {
          TraverseStmt(Expr->getArg(i));
        }

        return true;
      }
    }
  }

  return RecursiveASTVisitor::TraverseCXXOperatorCallExpr(Expr);
}

bool AddressTakenVisitor::TraverseBinaryOperator(clang::BinaryOperator *Expr) {
  if (Expr->isAssignmentOp()) {
    const auto *DeclRef = clang::dyn_cast<clang::DeclRefExpr>(Expr->getLHS());
    if (DeclRef != nullptr) {
      // If the left-hand side of an assignment is a DeclRefExpr, we skip
      // visiting the left-hand side.
      RecursiveASTVisitor::TraverseStmt(Expr->getRHS());

      return true;
    }

    const auto *ArraySubscript =
        clang::dyn_cast<clang::ArraySubscriptExpr>(Expr->getLHS());
    if (ArraySubscript != nullptr) {
      // If the left-hand side of an assignment is an ArraySubscriptExpr, we
      // skip visiting the left-hand side.
      RecursiveASTVisitor::TraverseStmt(Expr->getRHS());

      return true;
    }

    return true;
  }

  return RecursiveASTVisitor::TraverseBinaryOperator(Expr);
}

bool AddressTakenVisitor::TraverseMemberExpr(clang::MemberExpr *Expr) {
  const auto *ValueDecl = Expr->getMemberDecl();
  /* llvm::errs() << "Address taken in field: " << ValueDecl->getNameAsString()
            << " at "
            << Expr->getBeginLoc().printToString(Context->getSourceManager())
            << '\n'; */
  State->members.insert(ValueDecl);

  auto *ArraySubscript =
      clang::dyn_cast<clang::ArraySubscriptExpr>(Expr->getBase());
  if (ArraySubscript != nullptr) {
    const auto *ImplicitCast =
        clang::dyn_cast<clang::ImplicitCastExpr>(ArraySubscript->getBase());
    if (ImplicitCast != nullptr) {
      if (clang::isa<clang::DeclRefExpr>(ImplicitCast->getSubExpr())) {
        // Don't visit the base of an array subscript expression
        // if the parent expression is a a MemberExpr. We do this since
        // we aim to escape the member itself and not the whole base expression.
        RecursiveASTVisitor::TraverseStmt(ArraySubscript->getIdx());

        return true;
      }
    }
  }

  return RecursiveASTVisitor::TraverseMemberExpr(Expr);
}

bool AddressTakenVisitor::TraverseImplicitCastExpr(
    clang::ImplicitCastExpr *Expr) {
  const auto *DeclRef = clang::dyn_cast<clang::DeclRefExpr>(Expr->getSubExpr());
  if ((DeclRef != nullptr) && Expr->getCastKind() == clang::CK_LValueToRValue) {
    // Don't visit the subexpression of an implicit cast of kind
    // CK_LValueToRValue if the subexpression is a DeclRefExpr.

    return true;
  }

  if ((DeclRef != nullptr) &&
      (Expr->getCastKind() == clang::CK_ArrayToPointerDecay)) {
    // If the subexpression of an implicit cast is a DeclRefExpr, we mark the
    // corresponding VarDecl as decayed.

    const clang::ValueDecl *Decl = DeclRef->getDecl();
    if (const auto *VarDecl = clang::dyn_cast<clang::VarDecl>(Decl)) {
      /* llvm::errs() << "Decayed array address: " << VarDecl->getNameAsString()
                << " at "
                << Expr->getBeginLoc().printToString(
                       Context->getSourceManager())
                << '\n'; */
      State->decayed.insert(VarDecl);
    }

    return true;
  }

  const auto *MemberExpr =
      clang::dyn_cast<clang::MemberExpr>(Expr->getSubExpr());
  if ((MemberExpr != nullptr) &&
      Expr->getCastKind() == clang::CK_LValueToRValue) {
    // Only visit the base of a member expression when the
    // expression is implicitly cast to an rvalue.

    return RecursiveASTVisitor::VisitExpr(MemberExpr->getBase());
  }

  auto *ArraySubscript =
      clang::dyn_cast<clang::ArraySubscriptExpr>(Expr->getSubExpr());
  if ((ArraySubscript != nullptr) &&
      Expr->getCastKind() == clang::CK_LValueToRValue) {
    // Only visit the index of an array subscript expression when the
    // expression is implicitly cast to an rvalue.

    return RecursiveASTVisitor::VisitExpr(ArraySubscript->getIdx());
  }

  return RecursiveASTVisitor::TraverseImplicitCastExpr(Expr);
}

bool AddressTakenVisitor::VisitDeclRefExpr(clang::DeclRefExpr *Expr) {
  if (const auto *VarDecl = clang::dyn_cast<clang::VarDecl>(Expr->getDecl())) {
    // Everytime we see a DeclRefExpr, we mark the corresponding VarDecl as
    // taken.
    /* llvm::errs() << "Taken address local: " << VarDecl->getNameAsString() <<
       " at "
              << Expr->getLocation().printToString(Context->getSourceManager())
              << '\n'; */
    State->taken.insert(VarDecl);
  }

  return true;
}
} // namespace cpp2rust
