#pragma once

#include <vector>

#include "parser.hpp"

class GraphImplementation {
 public:
  GraphImplementation(std::string_view expression, double left_span,
                      double right_span, double points_number,
                      double grid_step);

  void UpdateFormula(std::string_view expression);

  void CalculatePoints();

  std::vector<double> GetXCoords() const;

  std::vector<double> GetYCoords() const;

  void UpdateSpan(double left_span, double right_span);

  void UpdateStep(double points_number);

  void AdjustSpan(double factor);

  void Move(double x_delta);

  double GetScale() const;

 private:
  std::unique_ptr<IExpression> formula;
  std::vector<double> x_coords;
  std::vector<double> y_coords;
  double left_span;
  double right_span;
  double step;
  double grid_step;
};