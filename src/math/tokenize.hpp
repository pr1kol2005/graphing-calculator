#pragma once

#include <string>
#include <variant>
#include <vector>

struct NumberToken {
  double value;

  explicit NumberToken(double valuee) : value(valuee) {}
};

struct UnknownToken {
  std::string value;

  explicit UnknownToken(std::string value_) : value(value_) {}
};

struct PlusToken {};
struct MinusToken {};
struct MultiplyToken {};
struct DivideToken {};
struct MinToken {};
struct MaxToken {};
struct AbsToken {};
struct ResidualToken {};
struct OpeningBracketToken {};
struct ClosingBracketToken {};
struct VariableToken {};
struct PowerToken {};
struct SqrtToken {};
struct SinToken {};
struct CosToken {};
struct TanToken {};

using Token =
    std::variant<NumberToken, UnknownToken, PlusToken, MinusToken,
                 MultiplyToken, DivideToken, MinToken, MaxToken, AbsToken,
                 ResidualToken, OpeningBracketToken,
                 ClosingBracketToken, VariableToken, PowerToken, SqrtToken, SinToken, CosToken, TanToken>;

std::vector<Token> Tokenize(std::string_view str);
