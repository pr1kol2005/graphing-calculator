#include <stdexcept>
#include <string>

class UnknownSymbolError : public std::runtime_error {
 public:
  explicit UnknownSymbolError(const std::string& symbol = "")
      : std::runtime_error("UnknownSymbolError: " + symbol) {}
};

class WrongExpressionError : public std::runtime_error {
 public:
  explicit WrongExpressionError(const std::string& msg = "")
      : std::runtime_error("WrongExpressionError: " + msg) {}
};

class UnsubstitutedVariablesError : public std::runtime_error {
 public:
  explicit UnsubstitutedVariablesError()
      : std::runtime_error(
            "Forgot to substitute variables before calculating expression") {}
};