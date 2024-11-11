#include <SFML/Graphics.hpp>

#include "canvas.hpp"
#include "constants.hpp"
#include "input_field.hpp"
#include "bridge_controller.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          WINDOW_TITLE);

  BridgeController controller(std::make_unique<InputField>(INPUT_FIELD_X, INPUT_FIELD_Y, INPUT_FIELD_WIDTH, INPUT_FIELD_HEIGHT, GRAPH_DEFAULT_FORMULA),
                             std::make_unique<GraphImplementation>(GRAPH_DEFAULT_FORMULA, WINDOW_WIDTH, GRAPH_DOTS_STEP),
                             std::make_unique<Canvas>(WINDOW_WIDTH, WINDOW_HEIGHT));

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      controller.HandleEvent(event);
    }

    window.clear(sf::Color::White);

    controller.Draw(window);
    window.display();
  }
  return 0;
}