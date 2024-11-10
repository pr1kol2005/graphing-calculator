#include "graph_view.hpp"

GraphView::GraphView(const std::vector<double>& x_coords,
                     const std::vector<double>& y_coords, sf::Vector2f center,
                     sf::Color color, double scale)
    : x_coords(x_coords),
      y_coords(y_coords),
      center(center),
      color(color),
      scale(scale) {}

void GraphView::Draw(sf::RenderWindow& window) {
  if (x_coords.size() != y_coords.size() || x_coords.empty()) {
    return;
  }

  std::vector<sf::Vertex> points;
  for (size_t i = 0; i < x_coords.size(); ++i) {
    double x_canvas_coord = center.x + x_coords[i] * scale;
    double y_canvas_coord = center.y - y_coords[i] * scale;

    points.emplace_back(sf::Vector2f(x_canvas_coord, y_canvas_coord), color);
  }

  window.draw(&points[0], points.size(), sf::LinesStrip);
}
