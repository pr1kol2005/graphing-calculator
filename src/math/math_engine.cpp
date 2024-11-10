#include <iostream>

#include "parser.hpp"

int main() {
  std::string input;
  std::cout << "Enter expression: ";
  std::getline(std::cin, input);
  double x = 0;
  std::cout << "Enter x: ";
  std::cin >> x;
  auto expression = GetExpressionFromPolishNotation(input);
  std::cout << "Result: " << expression->Calculate(x) << std::endl;
}