#pragma once

#include <cmath>

#include "errors.hpp"
#include "expressions.hpp"
#include "tokenize.hpp"

class IExpression {
 public:
  virtual double Calculate(double x = 0) const = 0;

  virtual ~IExpression() = default;
};

class Constant : public IExpression {
 protected:
  double value_;

 public:
  Constant(double value) : value_(value) {}

  double Calculate(double x = 0) const override { return value_; }
};

class Variable : public IExpression {
 public:
  Variable() {}

  double Calculate(double x = 0) const override { return x; }
};

class IUnaryOperation : public IExpression {
 protected:
  std::unique_ptr<IExpression> operand_;

 public:
  IUnaryOperation(std::unique_ptr<IExpression> operand)
      : operand_(std::move(operand)) {}

  virtual double Operation(double operand) const = 0;

  double Calculate(double x = 0) const override {
    return Operation(operand_->Calculate(x));
  }
};

class IBinaryOperation : public IExpression {
 protected:
  std::unique_ptr<IExpression> lhs_;
  std::unique_ptr<IExpression> rhs_;

 public:
  IBinaryOperation(std::unique_ptr<IExpression> lhs,
                   std::unique_ptr<IExpression> rhs)
      : lhs_(std::move(lhs)), rhs_(std::move(rhs)) {}

  virtual double Operation(double lhs, double rhs) const = 0;

  double Calculate(double x = 0) const override {
    return Operation(lhs_->Calculate(x), rhs_->Calculate(x));
  }
};

class AbsoluteValue : public IUnaryOperation {
 public:
  using IUnaryOperation::IUnaryOperation;

 protected:
  double Operation(double operand) const override { return std::abs(operand); }
};

class SquareRoot : public IUnaryOperation {
 public:
  using IUnaryOperation::IUnaryOperation;

 protected:
  double Operation(double operand) const override { return std::sqrt(operand); }
};

class Sin : public IUnaryOperation {
 public:
  using IUnaryOperation::IUnaryOperation;

 protected:
  double Operation(double operand) const override { return std::sin(operand); }
};

class Cos : public IUnaryOperation {
 public:
  using IUnaryOperation::IUnaryOperation;

 protected:
  double Operation(double operand) const override { return std::cos(operand); }
};

class Tan : public IUnaryOperation {
 public:
  using IUnaryOperation::IUnaryOperation;

 protected:
  double Operation(double operand) const override { return std::tan(operand); }
};

class Sum : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override { return lhs + rhs; }
};

class Subtract : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override { return lhs - rhs; }
};

class Multiply : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override { return lhs * rhs; }
};

class Divide : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override { return lhs / rhs; }
};

class Residual : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override {
    return std::fmod(lhs, rhs);
  }
};

class Minimum : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override {
    return std::min(lhs, rhs);
  }
};

class Maximum : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override {
    return std::max(lhs, rhs);
  }
};

class Power : public IBinaryOperation {
 public:
  using IBinaryOperation::IBinaryOperation;

 protected:
  double Operation(double lhs, double rhs) const override {
    return std::pow(lhs, rhs);
  }
};