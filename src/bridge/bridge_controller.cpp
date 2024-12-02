#include "bridge_controller.hpp"

BridgeController::BridgeController(std::unique_ptr<InputField> input_field,
                                   std::unique_ptr<GraphImplementation> graph,
                                   std::unique_ptr<Canvas> canvas)
    : input_field(std::move(input_field)),
      graph(std::move(graph)),
      canvas(std::move(canvas)) {
  UpdateGraph();
}

void BridgeController::Draw(sf::RenderWindow& window) {
  canvas->Draw(window);

  input_field->Draw(window);

  graph_view->Draw(window);
}

void BridgeController::HandleEvent(const sf::Event& event) {
  input_field->HandleEvent(event);

  if (event.type == sf::Event::KeyPressed &&
      event.key.code == sf::Keyboard::Enter) {
    ProcessInput();
  }

  if (event.type == sf::Event::MouseWheelScrolled) {
    AdjustScale(event);
  }

  if (event.type == sf::Event::KeyPressed) {
    Move(event);
  }
}

void BridgeController::Move(const sf::Event& event) {
  double x_delta = 0;
  double y_delta = 0;
  if (event.key.code == sf::Keyboard::Left) {
    x_delta = -10;
    y_delta = 0;
  } else if (event.key.code == sf::Keyboard::Right) {
    x_delta = 10;
    y_delta = 0;
  } else if (event.key.code == sf::Keyboard::Up) {
    x_delta = 0;
    y_delta = 10;
  } else if (event.key.code == sf::Keyboard::Down) {
    x_delta = 0;
    y_delta = -10;
  }
  graph->Move(x_delta);
  // TODO : Grid move
  UpdateGraph();
}

void BridgeController::AdjustScale(const sf::Event& event) {
  double factor = 1;
  double delta = event.mouseWheelScroll.delta / 120.0;
  factor = std::max(0.1, std::min(10.0, factor + delta));
  canvas->AdjustScale(factor);
  graph->AdjustSpan(factor);
  UpdateGraph();
}

void BridgeController::ProcessInput() {
  std::string expression_string = input_field->GetText();

  try {
    graph->UpdateFormula(expression_string);
    UpdateGraph();
  } catch (const std::exception& error) {
    std::cerr << "Ошибка при парсинге выражения: " << error.what() << std::endl;
  }
}

void BridgeController::UpdateGraph() {
  try {
    graph->CalculatePoints();
    graph_view =
        std::make_unique<GraphView>(graph->GetXCoords(), graph->GetYCoords(), 0,
                                    0, graph->GetScale(), sf::Color::Red);
  } catch (const std::exception& error) {
    std::cerr << "Error while updating graph: " << error.what() << std::endl;
  }
  std::cerr << "Graph updated" << std::endl;
}
