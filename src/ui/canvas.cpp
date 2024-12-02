#include "canvas.hpp"

Canvas::Canvas(double width, double height)
    : width(width),
      height(height),
      grid_step(GRID_SPACING),
      center(width / 2, height / 2) {
  x_axis[0] = sf::Vertex(sf::Vector2f(0, height / 2), sf::Color::Black);
  x_axis[1] = sf::Vertex(sf::Vector2f(width, height / 2), sf::Color::Black);

  y_axis[0] = sf::Vertex(sf::Vector2f(width / 2, 0), sf::Color::Black);
  y_axis[1] = sf::Vertex(sf::Vector2f(width / 2, height), sf::Color::Black);
}

void Canvas::Draw(sf::RenderWindow &window) {
  DrawGrid(window);
  DrawAxes(window);
}

void Canvas::DrawAxes(sf::RenderWindow &window) {
  window.draw(x_axis, 2, sf::Lines);
  window.draw(y_axis, 2, sf::Lines);
}

void Canvas::DrawGrid(sf::RenderWindow &window) {
  sf::Color grid_color(200, 200, 200);

  if (grid_step < GRID_SPACING / 2) {
    grid_step = GRID_SPACING;
  }
  if (grid_step > GRID_SPACING * 2) {
    grid_step = GRID_SPACING;
  }

  for (double x = width / 2; x < width; x += grid_step) {
    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x, 0), grid_color),
                         sf::Vertex(sf::Vector2f(x, height), grid_color)};
    window.draw(line, 2, sf::Lines);
  }
  for (double x = width / 2; x > 0; x -= grid_step) {
    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x, 0), grid_color),
                         sf::Vertex(sf::Vector2f(x, height), grid_color)};
    window.draw(line, 2, sf::Lines);
  }

  for (double y = height / 2; y < height; y += grid_step) {
    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(0, y), grid_color),
                         sf::Vertex(sf::Vector2f(width, y), grid_color)};
    window.draw(line, 2, sf::Lines);
  }
  for (double y = height / 2; y > 0; y -= grid_step) {
    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(0, y), grid_color),
                         sf::Vertex(sf::Vector2f(width, y), grid_color)};
    window.draw(line, 2, sf::Lines);
  }
}

sf::Vector2f Canvas::GetCenter() const { return center; }

double Canvas::GetScale() const { return grid_step; }

void Canvas::AdjustScale(double factor) { grid_step /= factor; }
