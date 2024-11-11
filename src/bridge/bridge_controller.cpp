#include "bridge_controller.hpp"

BridgeController::BridgeController(std::unique_ptr<InputField> input_field,
                                   std::unique_ptr<GraphImplementation> graph,
                                   std::unique_ptr<Canvas> canvas)
    : input_field(std::move(input_field)),
      graph(std::move(graph)),
      canvas(std::move(canvas)) {
    UpdateGraph();    
  }

void BridgeController::HandleEvent(const sf::Event& event) {
  input_field->HandleEvent(event);

  if (event.type == sf::Event::KeyPressed &&
      event.key.code == sf::Keyboard::Enter) {
    ProcessInput();
  }
}

void BridgeController::Draw(sf::RenderWindow& window) {
  canvas->Draw(window);

  input_field->Draw(window);

  graph_view->Draw(window);
}

void BridgeController::ProcessInput() {
  std::string expression_string = input_field->GetText();

  if (expression_string.empty()) {
    return;
  }

  try {
    graph->UpdateFormula(expression_string);
    UpdateGraph();
  } catch (const std::exception& error) {
    std::cerr << "Ошибка при парсинге выражения: " << error.what() << std::endl;
  }
}

void BridgeController::UpdateGraph() {
  graph->CalculatePoints();
  graph_view = std::make_unique<GraphView>(graph->GetXCoords(), graph->GetYCoords(), canvas->GetCenter(),
                sf::Color::Red, 50);
  std::cerr << "Graph updated" << std::endl;
}
