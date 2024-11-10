#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class GraphView {
 public:
  GraphView(const std::vector<double>& x_coords,
            const std::vector<double>& y_coords, sf::Vector2f center,
            sf::Color color = sf::Color::Blue, double scale = 1);

  void Draw(sf::RenderWindow& window);

 private:
  std::vector<double> x_coords;
  std::vector<double> y_coords;
  sf::Color color;
  sf::Vector2f center;

  double scale;
};
