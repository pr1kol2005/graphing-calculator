#include "tokenize.hpp"

std::vector<std::string_view> Separation(std::string_view input_str) {
  std::vector<std::string_view> separated;
  std::string delimiter = " ";
  size_t begin = 0;
  auto end = input_str.find(delimiter, 0);
  size_t space = 0;

  while (begin < input_str.size()) {
    if (begin < end) {
      if (end == input_str.size()) {
        space = end;
      } else {
        space = end - begin;
      }
      separated.emplace_back(input_str.substr(begin, space));
    }
    begin = (end >= input_str.size() ? end : end + delimiter.size());
    end = input_str.find(delimiter, begin);
  }

  return separated;
}

bool IsNumber(std::string_view token) {
  if (token[0] != '+' and token[0] != '-' and !isdigit(token[0]) and
      token[0] != '.') {
    return false;
  }
  if (token == "+" or token == "-" or token == ".") {
    return false;
  }
  size_t floating_point_count = 0;
  size_t begin = 1;
  if (std::isdigit(token[0])) {
    --begin;
  }
  while (begin < token.size()) {
    if (token[begin] == '.') {
      ++floating_point_count;
    } else if (!std::isdigit(token[begin])) {
      return false;
    }
    ++begin;
  }
  return (begin == token.size() and floating_point_count <= 1);
}

Token StrToToken(std::string_view token) {
  if (token == "+") {
    return PlusToken();
  }
  if (token == "-") {
    return MinusToken();
  }
  if (token == "*") {
    return MultiplyToken();
  }
  if (token == "/") {
    return DivideToken();
  }
  if (token == "min") {
    return MinToken();
  }
  if (token == "max") {
    return MaxToken();
  }
  if (token == "abs") {
    return AbsToken();
  }
  if (token == "%") {
    return ResidualToken();
  }
  if (token == "sqrt") {
    return SqrtToken();
  }
  if (token == "pow") {
    return PowerToken();
  }
  if (token == "sin") {
    return SinToken();
  }
  if (token == "cos") {
    return CosToken();
  }
  if (token == "tan") {
    return TanToken();
  }
  if (token == "(") {
    return OpeningBracketToken();
  }
  if (token == ")") {
    return ClosingBracketToken();
  }
  if (token == "x") {
    return VariableToken();
  }
  if (IsNumber(token)) {
    return NumberToken(std::stod(token.begin()));
  }
  return UnknownToken(std::string(token));
}

std::vector<Token> Tokenize(std::string_view str) {
  std::vector<std::string_view> separated = Separation(str);
  std::vector<Token> result;
  result.reserve(separated.size());

  for (const auto& substr : separated) {
    result.emplace_back(StrToToken(substr));
  }

  return result;
}