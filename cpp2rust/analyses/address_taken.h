#pragma once

// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/ASTConsumers.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Tooling/Tooling.h>

#include <unordered_set>

namespace cpp2rust {
struct AddressTakenState {
  /// A set of local variables whose address was taken.
  std::unordered_set<const clang::VarDecl *> taken;

  /// A set of local array variables that have decayed to pointers.
  std::unordered_set<const clang::VarDecl *> decayed;

  /// A set of member variables whose address was taken.
  std::unordered_set<const clang::ValueDecl *> members;
};

/// A basic analysis that, for each local variable, determines
/// whether its address was taken or not. This may be due to
/// the variable being used as a reference or the address
/// being taken explicitly.
class AddressTakenVisitor
    : public clang::RecursiveASTVisitor<AddressTakenVisitor> {
public:
  /// Constructs the visitor with a state pointer.
  ///
  /// \param State The state of the analysis.
  /// \param Context The current AST context.
  explicit AddressTakenVisitor(AddressTakenState *State,
                               clang::ASTContext *Context)
      : State(State), Context(Context) {}

  /// Curbs the analysis in order to avoid false positives.
  ///
  /// \param Expr The expression that may take the address of the local
  /// variable.
  bool TraverseInitListExpr(clang::InitListExpr *Expr);

  /// Curbs the analysis in order to avoid false positives.
  ///
  /// \param Expr The expression that may take the address of the local
  /// variable.
  bool TraverseCXXMemberCallExpr(clang::CXXMemberCallExpr *Expr);

  /// Curbs the analysis in order to avoid false positives.
  ///
  /// \param Expr The expression that may take the address of the local
  /// variable.
  bool TraverseCXXOperatorCallExpr(clang::CXXOperatorCallExpr *Expr);

  /// Curbs the analysis in order to avoid false positives.
  ///
  /// \param Expr The expression that may take the address of the local
  /// variable.
  bool TraverseBinaryOperator(clang::BinaryOperator *Expr);

  /// Handles the cases where a member variable is used as a reference.
  ///
  /// \param Expr The expression that may take the address of the member
  /// variable.
  bool TraverseMemberExpr(clang::MemberExpr *Expr);

  /// Curbs the analysis in order to avoid false positives.
  ///
  /// \param Expr The expression that may take the address of the local
  /// variable.
  bool TraverseImplicitCastExpr(clang::ImplicitCastExpr *Expr);

  /// Handles the case where a local variable is used as a reference.
  ///
  /// \param Expr The expression that may take the address of the local
  bool VisitDeclRefExpr(clang::DeclRefExpr *Expr);

private:
  /// The current state of the analysis.
  AddressTakenState *State;
  /// The current AST context.
  /// This field is not used, but it is useful for printing source locations.
  [[maybe_unused]] clang::ASTContext *Context;
};

class AddressTakenASTConsumer : public clang::ASTConsumer {
public:
  /// Constructs the AST consumer with a state pointer.
  ///
  /// \param State The state of the analysis.
  explicit AddressTakenASTConsumer(AddressTakenState *State) : State(State) {}

  /// Handles the translation unit.
  ///
  /// \param Ctx The current AST context.
  void HandleTranslationUnit([[maybe_unused]] clang::ASTContext &Ctx) override {
    AddressTakenVisitor Visitor(State, &Ctx);
    Visitor.TraverseDecl(Ctx.getTranslationUnitDecl());
  }

private:
  /// The current state of the analysis.
  AddressTakenState *State;
};

class AddressTakenAction : public clang::ASTFrontendAction {
public:
  /// Constructs the action with a state pointer.
  ///
  /// \param State The state of the analysis.
  explicit AddressTakenAction(AddressTakenState *State) : State(State) {}

  /// Creates the AST consumer.
  ///
  /// \param CI The current compiler instance.
  /// \param InFile The current input file.
  std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer([[maybe_unused]] clang::CompilerInstance &CI,
                    [[maybe_unused]] llvm::StringRef InFile) override {
    return std::make_unique<AddressTakenASTConsumer>(State);
  }

private:
  /// The current state of the analysis.
  AddressTakenState *State;
};

class AddressTakenActionFactory : public clang::tooling::FrontendActionFactory {
public:
  /// Constructs the factory with a state pointer.
  ///
  /// \param State The state of the analysis.
  explicit AddressTakenActionFactory(AddressTakenState *State) : State(State) {}

  /// Creates the frontend action.
  ///
  /// \return The frontend action.
  std::unique_ptr<clang::FrontendAction> create() override {
    return std::make_unique<AddressTakenAction>(State);
  }

private:
  /// The current state of the analysis.
  AddressTakenState *State;
};
} // namespace cpp2rust
