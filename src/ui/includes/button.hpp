#pragma once

#include <SFML/Graphics.hpp>

class Button {
 public:
  virtual ~Button() = default;

  virtual bool IsMouseOver(int mouse_x, int mouse_y) const = 0;

  virtual void Draw(sf::RenderWindow& window) = 0;

  virtual void OnClick() = 0;

 protected:
  sf::RectangleShape shape;
};
