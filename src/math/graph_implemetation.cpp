#include <iostream>

#include "graph_implementation.hpp"

GraphImplementation::GraphImplementation(std::string_view expression,
                                         double left_span, double right_span,
                                         int points_number, double grid_step)
    : grid_step(grid_step) {
  UpdateSpan(left_span, right_span);
  UpdateStep(points_number);
  UpdateFormula(expression);
}

void GraphImplementation::UpdateSpan(double new_left_span,
                                     double new_right_span) {
  left_span = new_left_span;
  right_span = new_right_span;
}

void GraphImplementation::UpdateStep(int points_number) {
  step = (right_span + left_span) / points_number;
}

void GraphImplementation::AdjustSpan(double factor) {
  step *= factor;
  left_span *= factor;
  right_span *= factor;
  grid_step /= factor;
}

void GraphImplementation::Reset() {
  grid_step = DEFAULT_GRID_STEP;
  UpdateSpan(DEFAULT_LEFT_SPAN, DEFAULT_RIGHT_SPAN);
  UpdateStep(GRAPH_POINTS_NUMBER);
}

void GraphImplementation::Move(double x_delta) {
  right_span -= (x_delta / grid_step);
  left_span += (x_delta / grid_step);
}

double GraphImplementation::GetGridStep() const { return grid_step; }

void GraphImplementation::UpdateFormula(std::string_view expression) {
  try {
    // formula = GetExpressionFromPolishNotation(expression);
    formula = GetExpressionFromUsualNotation(expression);
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