#include <SFML/Graphics.hpp>
#include <cmath>

#include "canvas.hpp"
#include "constants.hpp"
#include "graph_view.hpp"
#include "input_field.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          WINDOW_TITLE, sf::Style::Close);

  Canvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT);
  InputField input_field(10, 10, 200, 50);

  std::vector<double> xValues;
  std::vector<double> yValues;

  for (double x = -5; x <= 5; x += 0.01) {
    xValues.push_back(x);
    yValues.push_back(std::sin(1 / x));
  }

  GraphView graph(xValues, yValues, 0, 0, DEFAULT_GRID_STEP, sf::Color::Red);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      input_field.HandleEvent(event);
    }

    window.clear(sf::Color::White);

    canvas.Draw(window);
    input_field.Draw(window);
    graph.Draw(window);
    window.display();
  }
  return 0;
}