#include "button.hpp"
#include "reset_button.hpp"

ResetButton::ResetButton(int x, int y, double width, double height)
    : is_pressed(false) {
  shape.setPosition(x, y);
  shape.setSize(sf::Vector2f(width, height));
  shape.setFillColor(sf::Color(200, 200, 200));
  shape.setOutlineThickness(2);
  shape.setOutlineColor(sf::Color::Black);
}

bool ResetButton::IsMouseOver(const sf::Vector2i& mousePosition) const {
  return shape.getGlobalBounds().contains(
      static_cast<sf::Vector2f>(mousePosition));
}

void ResetButton::Draw(sf::RenderWindow& window) { window.draw(shape); }

void ResetButton::OnClick() {
  is_pressed = true;
  shape.setFillColor(sf::Color(100, 100, 100));
}

void ResetButton::ResetState() {
  is_pressed = false;
  shape.setFillColor(sf::Color(200, 200, 200));
}
