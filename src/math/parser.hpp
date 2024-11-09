#pragma once

#include "errors.hpp"
#include "expressions.hpp"
#include "tokenize.hpp"

int CalculatePolishNotation(std::string_view input);

std::unique_ptr<IExpression> ParsePolishNotation(
    const std::vector<Token>& tokens, size_t& pos);

int CalculateUsualNotation(std::string_view input);

std::unique_ptr<IExpression> ParseUsualNotation(
    const std::vector<Token>& tokens, size_t& pos);

void SubstituteVariables(std::unique_ptr<IExpression>& expression);

void OptimizeExpression(std::unique_ptr<IExpression>& expression);