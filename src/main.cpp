#include <SFML/Graphics.hpp>

#include "ui/constants.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          WINDOW_TITLE);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.display();
    window.clear();
  }
  return 0;
}