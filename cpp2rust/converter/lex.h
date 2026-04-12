#pragma once

// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

namespace cpp2rust {
namespace token {
inline constexpr const char *kOpenCurlyBracket = "{\n";
inline constexpr const char *kCloseCurlyBracket = "\n}\n";
inline constexpr const char *kOpenBracket = "[";
inline constexpr const char *kCloseBracket = "]";
inline constexpr const char *kSemiColon = ";\n";
inline constexpr const char *kComma = ",";
inline constexpr const char *kColon = ":";
inline constexpr const char *kDoubleColon = "::";
inline constexpr const char *kAssign = "=";
inline constexpr const char *kOpenParen = "(";
inline constexpr const char *kCloseParen = ")";
inline constexpr const char *kDot = ".";
inline constexpr const char *kNot = "!";
inline constexpr const char *kDiff = "!=";
inline constexpr const char *kZero = "0";
inline constexpr const char *kOne = "1";
inline constexpr const char *kRef = "&";
inline constexpr const char *kStar = "*";
inline constexpr const char *kArrow = "->";
inline constexpr const char *kHash = "#";
inline constexpr const char *kMinus = "-";
inline constexpr const char *kDiv = "/";
inline constexpr const char *kLt = "<";
inline constexpr const char *kGt = ">";
inline constexpr const char *kEmpty = "";
inline constexpr const char *kNewLine = "\n";
} // namespace token

namespace keyword {
inline constexpr const char *kAs = "as";
inline constexpr const char *kBreak = "break";
inline constexpr const char *kContinue = "continue";
inline constexpr const char *kConst = "const";
inline constexpr const char *kElse = "else";
inline constexpr const char *kFalse = "false";
inline constexpr const char *kFn = "fn";
inline constexpr const char *kIf = "if";
inline constexpr const char *kImpl = "impl";
inline constexpr const char *kLet = "let";
inline constexpr const char *kLoop = "loop";
inline constexpr const char *kPub = "pub";
inline constexpr const char *kModule = "mod";
inline constexpr const char *kReturn = "return";
inline constexpr const char *kSelfValue = "self";
inline constexpr const char *kStatic = "static";
inline constexpr const char *kStruct = "struct";
inline constexpr const char *kTrue = "true";
inline constexpr const char *kWhile = "while";
inline constexpr const char *kFor = "for";
inline constexpr const char *kIn = "in";
inline constexpr const char *kTrait = "trait";
inline constexpr const char *kDyn = "dyn";
} // namespace keyword
} // namespace cpp2rust
