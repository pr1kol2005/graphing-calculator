#pragma once

#include <vector>

#include "constants.hpp"
#include "parser.hpp"

class GraphImplementation {
 public:
  GraphImplementation(std::string_view expression, double left_span,
                      double right_span, int points_number, double grid_step);

  void UpdateFormula(std::string_view expression);

  void CalculatePoints();

  std::vector<double> GetXCoords() const;

  std::vector<double> GetYCoords() const;

  void UpdateSpan(double left_span, double right_span);

  void UpdateStep(int points_number);

  void AdjustSpan(double factor);

  void Move(double x_delta);

  double GetGridStep() const;

  void Reset();

 private:
  std::unique_ptr<IExpression> formula;
  std::vector<double> x_coords;
  std::vector<double> y_coords;
  double left_span;
  double right_span;
  double step;
  double grid_step;
};