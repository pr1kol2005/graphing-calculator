#pragma once

#include <memory>

#include "errors.hpp"
#include "expressions.hpp"
#include "tokenize.hpp"

std::unique_ptr<IExpression> GetExpressionFromPolishNotation(
    std::string_view input);

std::unique_ptr<IExpression> ParsePolishNotation(
    const std::vector<Token> &tokens, size_t &pos);

std::unique_ptr<IExpression> GetExpressionFromUsualNotation(
    std::string_view input);

std::unique_ptr<IExpression> ParseUsualNotation(
    const std::vector<Token> &tokens, size_t &pos);

int GetPriority(const Token &token);

// TODO : add tree optimization