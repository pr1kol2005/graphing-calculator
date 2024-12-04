#pragma once

#include "button.hpp"
#include "canvas.hpp"

class ResetButton : public Button {
 public:
  ResetButton(int x, int y, double width, double height);

  bool IsMouseOver(int mouse_x, int mouse_y) const override;

  void Draw(sf::RenderWindow& window) override;

  void OnClick() override;

  void ResetState();

 private:
  bool is_pressed;
};
