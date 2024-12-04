#include "graph_view.hpp"

GraphView::GraphView(const std::vector<double> &x_coords,
                     const std::vector<double> &y_coords, double x_offset,
                     double y_offset, double grid_step, sf::Color color)
    : x_coords(x_coords),
      y_coords(y_coords),
      x_offset(x_offset),
      y_offset(y_offset),
      grid_step(grid_step),
      color(color) {}

bool GraphView::IsDiscontinuous(double y_1, double y_2) {
  return std::fabs(y_1 - y_2) > WINDOW_HEIGHT;
}

void GraphView::Draw(sf::RenderWindow &window) {
  if (x_coords.size() != y_coords.size() || x_coords.empty()) {
    return;
  }

  std::vector<sf::Vertex> points;
  std::vector<size_t> break_indexes = {0};

  for (size_t i = 0; i < x_coords.size(); ++i) {
    double x_canvas_coord = WINDOW_CENTER_X + (x_coords[i] * grid_step) + x_offset;
    double y_canvas_coord = WINDOW_CENTER_Y + (y_coords[i] * grid_step) + y_offset;

    y_canvas_coord = WINDOW_HEIGHT - y_canvas_coord;

    if (!points.empty()) {
      if (IsDiscontinuous(points.back().position.y, y_canvas_coord)) {
        break_indexes.push_back(i);
      }
    }
    points.emplace_back(sf::Vector2f(x_canvas_coord, y_canvas_coord), color);
  }

  break_indexes.push_back(points.size());

  for (size_t i = 0; i < break_indexes.size() - 1; ++i) {
    window.draw(&points[break_indexes[i]],
                break_indexes[i + 1] - break_indexes[i], sf::LinesStrip);
  }
}
