#include "bridge_controller.hpp"

BridgeController::BridgeController(std::unique_ptr<InputField> input_field,
                                   std::unique_ptr<GraphImplementation> graph,
                                   std::unique_ptr<Canvas> canvas,
                                   std::unique_ptr<ResetButton> reset_button)
    : input_field(std::move(input_field)),
      graph(std::move(graph)),
      canvas(std::move(canvas)),
      reset_button(std::move(reset_button)) {
  UpdateGraph();
}

void BridgeController::Draw(sf::RenderWindow& window) {
  try {
    canvas->Draw(window);

    input_field->Draw(window);

    graph_view->Draw(window);

    reset_button->Draw(window);
  } catch (const std::exception& e) {
    std::cerr << "Error while drawing: " << e.what() << std::endl;
  }
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
    MoveWithKeyboard(event);
  }

  if (event.type == sf::Event::MouseButtonPressed) {
    StartDragging(event);
  }

  if (event.type == sf::Event::MouseButtonReleased) {
    StopDragging(event);
  }

  if (event.type == sf::Event::MouseMoved) {
    DragMouse(event);
  }

  if (event.type == sf::Event::MouseButtonPressed) {
    if (reset_button->IsMouseOver(event.mouseButton.x, event.mouseButton.y)) {
      reset_button->OnClick();
      ResetEverything();
    }
  }

  if (event.type == sf::Event::MouseButtonReleased) {
    reset_button->ResetState();
  }

  // TODO : Reset button
}

void BridgeController::ResetEverything() {
  graph->Reset();
  canvas->Reset();
  UpdateGraph();
}

void BridgeController::StartDragging(const sf::Event& event) {
  if (event.mouseButton.button == sf::Mouse::Left) {
    is_dragging = true;
    last_mouse_pos = sf::Mouse::getPosition();
  }
}

void BridgeController::StopDragging(const sf::Event& event) {
  if (event.mouseButton.button == sf::Mouse::Left) {
    is_dragging = false;
  }
}

void BridgeController::DragMouse(const sf::Event& event) {
  if (is_dragging) {
    sf::Vector2i current_mouse_pos = sf::Mouse::getPosition();
    sf::Vector2i delta = current_mouse_pos - last_mouse_pos;
    last_mouse_pos = current_mouse_pos;

    double x_delta = delta.x;
    double y_delta = delta.y;
    graph->Move(x_delta);
    canvas->Move(x_delta, -y_delta);
    UpdateGraph();
  }
}

void BridgeController::MoveWithKeyboard(const sf::Event& event) {
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
  canvas->Move(x_delta, y_delta);
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
    std::cerr << "Graph formula updated" << std::endl;
    UpdateGraph();
  } catch (const std::exception& error) {
    std::cerr << "Ошибка при парсинге выражения: " << error.what() << std::endl;
  }
}

void BridgeController::UpdateGraph() {
  try {
    graph->CalculatePoints();
    graph_view = std::make_unique<GraphView>(
        graph->GetXCoords(), graph->GetYCoords(), canvas->GetXOffset(),
        canvas->GetYOffset(), graph->GetGridStep(), sf::Color::Red);
  } catch (const std::exception& error) {
    std::cerr << "Error while updating graph: " << error.what() << std::endl;
  }
}
