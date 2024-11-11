#include "input_field.hpp"

InputField::InputField(double x, double y, double width, double height, std::string_view text)
    : input_text(text), is_focused(false) {
  box.setPosition(x, y);
  box.setSize(sf::Vector2f(width, height));
  box.setFillColor(sf::Color::White);
  box.setOutlineColor(sf::Color::Black);
  box.setOutlineThickness(2);

  if (!font.loadFromFile("fonts/arial.ttf")) {
    throw std::runtime_error("Не удалось загрузить шрифт");
  }

  shown_text.setFont(font);
  shown_text.setFillColor(sf::Color::Black);
  shown_text.setCharacterSize(24);
  shown_text.setPosition(x + 5, y + 5);
  shown_text.setString(input_text);
}

void InputField::Draw(sf::RenderWindow& window) {
  window.draw(box);
  window.draw(shown_text);

  box.setOutlineColor(is_focused ? sf::Color::Blue : sf::Color::Black);
}

void InputField::HandleEvent(sf::Event event) {
  if (event.type == sf::Event::MouseButtonPressed) {
    sf::FloatRect bounders = box.getGlobalBounds();
    if (bounders.contains(event.mouseButton.x, event.mouseButton.y)) {
      SetFocused(true);
    } else {
      SetFocused(false);
    }
  }

  if (is_focused && event.key.code == sf::Keyboard::Enter) {
    SetFocused(false);
  }

  if (is_focused && event.type == sf::Event::TextEntered) {
    if (event.text.unicode == '\b' && !input_text.empty()) {
      input_text.pop_back();
    } else if (event.text.unicode < 128) {
      input_text += static_cast<char>(event.text.unicode);
    }
    shown_text.setString(input_text);
  }
}

std::string InputField::GetText() const { return input_text; }

void InputField::SetFocused(bool state) { is_focused = state; }
