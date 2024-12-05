#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "constants.hpp"

class Canvas {
 public:
  Canvas(int width, int height);

  void Draw(sf::RenderWindow &window);

  sf::Vector2i GetCenter() const;

  int GetGridStep() const;

  int GetXOffset() const;

  int GetYOffset() const;

  void AdjustScale(double factor);

  void Move(int x_delta, int y_delta);

  void Reset();

 private:
  int width;
  int height;
  sf::Vector2i center;

  double scale;
  int zoom_level;

  sf::Vertex x_axis[2];
  sf::Vertex y_axis[2];
  int grid_step;
  int x_offset;
  int y_offset;

  void DrawAxes(sf::RenderWindow &window);
  void DrawGrid(sf::RenderWindow &window);
  void DrawNumbers(sf::RenderWindow &window);
};
