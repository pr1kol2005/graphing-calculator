#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Desmos");

  while (window.isOpen()) {
    sf::Event event;
    if (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.display();
    window.clear();
  }
  return 0;
}