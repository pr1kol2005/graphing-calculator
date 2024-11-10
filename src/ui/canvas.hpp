#pragma once

#include <SFML/Graphics.hpp>

class Canvas {
 public:
  Canvas(double width, double height);

  void Draw(sf::RenderWindow& window);

 private:
  double width;
  double height;

  sf::Vertex x_axis[2];
  sf::Vertex y_axis[2];
  double scale;

  void DrawAxes(sf::RenderWindow& window);
  void DrawGrid(sf::RenderWindow& window);
};
