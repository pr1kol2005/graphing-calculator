#pragma once

#include <SFML/Graphics.hpp>

#include "constants.hpp"

class Canvas {
 public:
  Canvas(double width, double height);

  void Draw(sf::RenderWindow &window);

  sf::Vector2f GetCenter() const;

  double GetScale() const;

  double GetXOffset() const;

  double GetYOffset() const;

  void AdjustScale(double factor);

  void Move(double x_delta, double y_delta);

 private:
  double width;
  double height;
  sf::Vector2f center;

  sf::Vertex x_axis[2];
  sf::Vertex y_axis[2];
  double grid_step;

  double x_offset;
  double y_offset;

  void DrawAxes(sf::RenderWindow &window);
  void DrawGrid(sf::RenderWindow &window);
};
