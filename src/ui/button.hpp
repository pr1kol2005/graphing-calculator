#pragma once

#include <SFML/Graphics.hpp>

class Button {
 public:
  virtual ~Button() = default;

  virtual bool IsMouseOver(const sf::Vector2i& mousePosition) const = 0;

  virtual void Draw(sf::RenderWindow& window) = 0;

  virtual void OnClick() = 0;

 protected:
  sf::RectangleShape shape;
};
