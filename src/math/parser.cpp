#include "parser.hpp"

#include <iostream>

template <typename VariableFactory, typename NumberFactory,
          typename UnaryFactory, typename BinaryFactoryLeft,
          typename BinaryFactoryRight>
std::unique_ptr<IExpression> HandleToken(
    const Token& token, size_t& pos, const std::vector<Token>& tokens,
    const VariableFactory& variable_factory,
    const NumberFactory& number_factory, const UnaryFactory& unary_factory,
    const BinaryFactoryLeft& binary_factory_left,
    const BinaryFactoryRight& binary_factory_right) {
  if constexpr (!std::is_same_v<VariableFactory, std::nullptr_t>) {
    if (std::holds_alternative<VariableToken>(token)) {
      return std::make_unique<Variable>(variable_factory(tokens, pos));
    }
  }

  if constexpr (!std::is_same_v<NumberFactory, std::nullptr_t>) {
    if (std::holds_alternative<NumberToken>(token)) {
      return std::make_unique<Constant>(number_factory(tokens, pos));
    }
  }

  if constexpr (!std::is_same_v<UnaryFactory, std::nullptr_t>) {
    if (std::holds_alternative<AbsToken>(token)) {
      return std::make_unique<AbsoluteValue>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<SqrtToken>(token)) {
      return std::make_unique<SquareRoot>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<SinToken>(token)) {
      return std::make_unique<Sin>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<CosToken>(token)) {
      return std::make_unique<Cos>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<TanToken>(token)) {
      return std::make_unique<Tan>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<AsinToken>(token)) {
      return std::make_unique<Asin>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<AcosToken>(token)) {
      return std::make_unique<Acos>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<AtanToken>(token)) {
      return std::make_unique<Atan>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<SinhToken>(token)) {
      return std::make_unique<Sinh>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<CoshToken>(token)) {
      return std::make_unique<Cosh>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<TanhToken>(token)) {
      return std::make_unique<Tanh>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<AsinhToken>(token)) {
      return std::make_unique<Asinh>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<AcoshToken>(token)) {
      return std::make_unique<Acosh>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<AtanhToken>(token)) {
      return std::make_unique<Atanh>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<LnToken>(token)) {
      return std::make_unique<LogBaseE>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<LgToken>(token)) {  
      return std::make_unique<LogBaseTen>(unary_factory(tokens, pos));
    }
    if (std::holds_alternative<Log2Token>(token)) {
      return std::make_unique<LogBaseTwo>(unary_factory(tokens, pos));
    }
  }

  if constexpr (!(std::is_same_v<BinaryFactoryLeft, std::nullptr_t> &&
                  std::is_same_v<BinaryFactoryRight, std::nullptr_t>)) {
    if (std::holds_alternative<PlusToken>(token)) {
      return std::make_unique<Sum>(binary_factory_left(tokens, pos),
                                   binary_factory_right(tokens, pos));
    }
    if (std::holds_alternative<MinusToken>(token)) {
      return std::make_unique<Subtract>(binary_factory_left(tokens, pos),
                                        binary_factory_right(tokens, pos));
    }
    if (std::holds_alternative<MultiplyToken>(token)) {
      return std::make_unique<Multiply>(binary_factory_left(tokens, pos),
                                        binary_factory_right(tokens, pos));
    }
    if (std::holds_alternative<DivideToken>(token)) {
      return std::make_unique<Divide>(binary_factory_left(tokens, pos),
                                      binary_factory_right(tokens, pos));
    }
    if (std::holds_alternative<PowerToken>(token)) {
      return std::make_unique<Power>(binary_factory_left(tokens, pos),
                                     binary_factory_right(tokens, pos));
    }
  }

  throw WrongExpressionError("Unexpected token");
}

std::unique_ptr<IExpression> ParsePolishNotation(
    const std::vector<Token>& tokens, size_t& pos) {
  if (pos >= tokens.size()) {
    throw WrongExpressionError("Invalid expression");
  }
  Token token = tokens[pos++];

  static auto variable_factory = [&](const std::vector<Token>&,
                                     size_t&) -> Variable {
    return Variable{};
  };

  static auto number_factory = [&](const std::vector<Token>& t,
                                   size_t& p) -> double {
    return std::get<NumberToken>(t[p - 1]).value;
  };

  static auto unary_factory = [&](const std::vector<Token>& t,
                                  size_t& p) -> std::unique_ptr<IExpression> {
    return ParsePolishNotation(t, p);
  };

  static auto binary_factory = [&](const std::vector<Token>& t,
                                   size_t& p) -> std::unique_ptr<IExpression> {
    return ParsePolishNotation(t, p);
  };

  return HandleToken(token, pos, tokens, variable_factory, number_factory,
                     unary_factory, binary_factory, binary_factory);
}

std::unique_ptr<IExpression> GetExpressionFromPolishNotation(
    std::string_view input) {
  std::vector<Token> tokens = Tokenize(input);
  size_t pos = 0;
  auto expression = ParsePolishNotation(tokens, pos);

  if (pos != tokens.size()) {
    throw WrongExpressionError("Incorrect operands number");
  }

  return expression;
}

int GetPriority(const Token& token) {
  if (std::holds_alternative<PlusToken>(token)) {
    return 1;
  }
  if (std::holds_alternative<MinusToken>(token)) {
    return 1;
  }
  if (std::holds_alternative<MultiplyToken>(token)) {
    return 2;
  }
  if (std::holds_alternative<DivideToken>(token)) {
    return 2;
  }
  if (std::holds_alternative<PowerToken>(token)) {
    return 3;
  }
  return 0;
}

std::unique_ptr<IExpression> ParsePrimary(const std::vector<Token>& tokens,
                                          size_t& pos) {
  if (pos >= tokens.size()) {
    throw WrongExpressionError("Unexpected end of expression");
  }

  auto variable_factory = [&](const std::vector<Token>&,
                                     size_t&) -> Variable {
    return Variable{};
  };

  auto number_factory = [&](const std::vector<Token>& t,
                                   size_t& p) -> double {
    return std::get<NumberToken>(t[p - 1]).value;
  };

  auto unary_factory = [&](const std::vector<Token>& t,
                                  size_t& p) -> std::unique_ptr<IExpression> {
    return ParsePrimary(t, p);
  };

  const Token& token = tokens[pos];

  if (std::holds_alternative<OpeningBracketToken>(token)) {
    ++pos;
    auto expr = ParseUsualNotation(tokens, pos);
    if (pos >= tokens.size() ||
        !std::holds_alternative<ClosingBracketToken>(tokens[pos])) {
      throw WrongExpressionError("Mismatched brackets");
    }
    ++pos;
    return expr;
  } else {
    ++pos;
  }

  return HandleToken(token, pos, tokens, variable_factory, number_factory,
                     unary_factory, nullptr, nullptr);
}

std::unique_ptr<IExpression> ParseBinary(const std::vector<Token>& tokens,
                                         size_t& pos, int min_priotity) {
  auto left = ParsePrimary(tokens, pos);

  while (pos < tokens.size()) {
    const Token& token = tokens[pos];

    int priority = GetPriority(token);

    if (priority < min_priotity || priority == 0) {
      break;
    }

    ++pos;

    auto right = ParseBinary(tokens, pos, priority + 1);

    auto binary_factory_left = [&](const std::vector<Token>&, size_t&)
        -> std::unique_ptr<IExpression> { return std::move(left); };

    auto binary_factory_right = [&](const std::vector<Token>&, size_t&)
        -> std::unique_ptr<IExpression> { return std::move(right); };

    left = HandleToken(token, pos, tokens, nullptr, nullptr, nullptr,
                       binary_factory_left, binary_factory_right);
  }

  return left;
}

std::unique_ptr<IExpression> ParseUsualNotation(
    const std::vector<Token>& tokens, size_t& pos) {
  return ParseBinary(tokens, pos, 0);
}

std::unique_ptr<IExpression> GetExpressionFromUsualNotation(
    std::string_view input) {
  std::vector<Token> tokens = Tokenize(input);
  size_t pos = 0;
  auto expression = ParseUsualNotation(tokens, pos);

  return expression;
}
