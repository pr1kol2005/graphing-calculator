#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "../math/graph_implementation.hpp"
#include "../math/parser.hpp"
#include "../ui/canvas.hpp"
#include "../ui/graph_view.hpp"
#include "../ui/input_field.hpp"

class BridgeController {
 public:
  BridgeController(std::unique_ptr<InputField> input_field,
                   std::unique_ptr<GraphImplementation> graph,
                   std::unique_ptr<Canvas> canvas);

  void HandleEvent(const sf::Event& event);

  void Draw(sf::RenderWindow& window);

  void UpdateGraph();

 private:
  void ProcessInput();

  std::unique_ptr<InputField> input_field;
  std::unique_ptr<GraphImplementation> graph;
  std::unique_ptr<Canvas> canvas;

  std::unique_ptr<GraphView> graph_view;
};
