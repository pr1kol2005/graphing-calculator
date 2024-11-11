#include <SFML/Graphics.hpp>

#include "canvas.hpp"
#include "constants.hpp"
#include "input_field.hpp"
#include "bridge_controller.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          WINDOW_TITLE);

  BridgeController controller(std::make_unique<InputField>(10, 10, 200, 50),
                             std::make_unique<GraphImplementation>("1", WINDOW_WIDTH, 0.01),
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