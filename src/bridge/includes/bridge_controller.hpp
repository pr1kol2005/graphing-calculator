#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "graph_implementation.hpp"
#include "parser.hpp"
#include "canvas.hpp"
#include "graph_view.hpp"
#include "input_field.hpp"
#include "reset_button.hpp"
#include "constants.hpp"

class BridgeController {
 public:
  BridgeController(std::unique_ptr<InputField> input_field,
                   std::unique_ptr<GraphImplementation> graph,
                   std::unique_ptr<Canvas> canvas,
                   std::unique_ptr<ResetButton> reset_button);

  void HandleEvent(const sf::Event& event);

  void Draw(sf::RenderWindow& window);

  void UpdateGraph();

 private:
  void ProcessInput();

  void AdjustScale(const sf::Event& event);

  void MoveWithKeyboard(const sf::Event& event);

  void StartDragging(const sf::Event& event);

  void StopDragging(const sf::Event& event);

  void DragMouse(const sf::Event& event);

  void ResetEverything();

  std::unique_ptr<InputField> input_field;
  std::unique_ptr<GraphImplementation> graph;
  std::unique_ptr<Canvas> canvas;
  std::unique_ptr<GraphView> graph_view;
  std::unique_ptr<ResetButton> reset_button;

  bool is_dragging;
  sf::Vector2i last_mouse_pos;
};
