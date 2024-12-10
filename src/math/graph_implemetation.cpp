#include "graph_implementation.hpp"

#include <iostream>

GraphImplementation::GraphImplementation(std::string_view expression,
                                         double width_view, double step) {
  UpdateScale(width_view, step);
  UpdateFormula(expression);
}

void GraphImplementation::UpdateScale(double width_view, double step) {
  this->width_view = width_view;
  this->step = step;
}

void GraphImplementation::UpdateFormula(std::string_view expression) {
  try {
    formula = GetExpressionFromPolishNotation(expression);
  } catch (const std::exception& error) {
    std::cerr << "Error while updating formula: " << error.what() << std::endl;
    formula = nullptr;
  }
}

void GraphImplementation::CalculatePoints() {
  x_coords.clear();
  y_coords.clear();
  for (double x = -width_view; x <= width_view && formula; x += step) {
    x_coords.push_back(x);
    y_coords.push_back(formula->Calculate(x));
  }
}

std::vector<double> GraphImplementation::GetXCoords() const { return x_coords; }

std::vector<double> GraphImplementation::GetYCoords() const { return y_coords; }