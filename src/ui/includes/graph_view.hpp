#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "constants.hpp"

class GraphView {
 public:
  GraphView() = default;

  GraphView(const std::vector<double> &x_coords,
            const std::vector<double> &y_coords,
            double x_offset = DEFAULT_X_OFFSET,
            double y_offset = DEFAULT_Y_OFFSET, double scale = DEFAULT_SCALE,
            sf::Color color = DEFAULT_COLOR);

  bool IsDiscontinuous(double y_1, double y_2);

  void Draw(sf::RenderWindow &window);

 private:
  std::vector<double> x_coords;
  std::vector<double> y_coords;
  double x_offset;
  double y_offset;
  double scale;
  sf::Color color;
};
