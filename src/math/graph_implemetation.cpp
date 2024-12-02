#include <iostream>

#include "graph_implementation.hpp"

GraphImplementation::GraphImplementation(std::string_view expression,
                                         double left_span, double right_span,
                                         double points_number, double scale)
    : scale(scale) {
  UpdateSpan(left_span, right_span);
  UpdateStep(points_number);
  UpdateFormula(expression);
}

void GraphImplementation::UpdateSpan(double new_left_span,
                                     double new_right_span) {
  left_span = new_left_span;
  right_span = new_right_span;
}

void GraphImplementation::UpdateStep(double points_number) {
  step = (right_span + left_span) / points_number;
}

void GraphImplementation::AdjustSpan(double factor) {
  step *= factor;
  left_span *= factor;
  right_span *= factor;
  scale /= factor;
}

void GraphImplementation::Move(double x_delta) {
  right_span += x_delta;
  left_span -= x_delta;
}

double GraphImplementation::GetScale() const { return scale; }

void GraphImplementation::UpdateFormula(std::string_view expression) {
  try {
    formula = GetExpressionFromPolishNotation(expression);
  } catch (const std::exception &error) {
    std::cerr << "Error while updating formula: " << error.what() << std::endl;
    formula = nullptr;
  }
}

void GraphImplementation::CalculatePoints() {
  x_coords.clear();
  y_coords.clear();
  for (double x = -left_span; x <= right_span && formula; x += step) {
    double y = formula->Calculate(x);
    x_coords.push_back(x);
    y_coords.push_back(y);
  }
}

std::vector<double> GraphImplementation::GetXCoords() const { return x_coords; }

std::vector<double> GraphImplementation::GetYCoords() const { return y_coords; }