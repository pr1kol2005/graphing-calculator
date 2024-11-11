#pragma once

#include <vector>

#include "parser.hpp"

class GraphImplementation {
 public:
  GraphImplementation(std::string_view expression, double width_view, double step);

  void UpdateScale(double width_view, double step);

  void UpdateFormula(std::string_view expression);

  void CalculatePoints();

  std::vector<double> GetXCoords() const;

  std::vector<double> GetYCoords() const;

 private:
  std::unique_ptr<IExpression> formula;
  std::vector<double> x_coords;
  std::vector<double> y_coords;
  double width_view;
  double step;
};