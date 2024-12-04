#pragma once

#include "button.hpp"
#include "canvas.hpp"

class ResetButton : public Button {
 public:
  ResetButton(int x, int y, double width, double height);

  bool IsMouseOver(const sf::Vector2i& mousePosition) const override;

  void Draw(sf::RenderWindow& window) override;

  void OnClick() override;

  void ResetState();

 private:
  bool is_pressed;
};
