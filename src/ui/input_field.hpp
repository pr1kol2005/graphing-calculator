#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class InputField {
 public:
  InputField(double x, double y, double width, double height);

  void Draw(sf::RenderWindow& window);
  void HandleEvent(sf::Event event);
  std::string GetText() const;

 private:
  void SetFocused(bool state);

  sf::RectangleShape box;
  sf::Text shown_text;
  sf::Font font;
  std::string input_text;
  bool is_focused;
};