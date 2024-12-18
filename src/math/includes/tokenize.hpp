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

struct VariableToken {};

struct OpeningBracketToken {};
struct ClosingBracketToken {};

struct PlusToken {};
struct MinusToken {};
struct MultiplyToken {};
struct DivideToken {};
struct PowerToken {};

struct AbsToken {};
struct SqrtToken {};
struct SinToken {};
struct CosToken {};
struct TanToken {};
struct AsinToken {};
struct AcosToken {};
struct AtanToken {};
struct SinhToken {};
struct CoshToken {};
struct TanhToken {};
struct AsinhToken {};
struct AcoshToken {};
struct AtanhToken {};
struct LnToken {};
struct LgToken {};
struct Log2Token {};

using Token =
    std::variant<NumberToken, UnknownToken, VariableToken, OpeningBracketToken,
                 ClosingBracketToken, PlusToken, MinusToken, MultiplyToken,
                 DivideToken, PowerToken, AbsToken, SqrtToken, SinToken,
                 CosToken, TanToken, AsinToken, AcosToken, AtanToken, SinhToken,
                 CoshToken, TanhToken, AsinhToken, AcoshToken, AtanhToken,
                 LnToken, LgToken, Log2Token>;

std::vector<Token> Tokenize(std::string_view str);
