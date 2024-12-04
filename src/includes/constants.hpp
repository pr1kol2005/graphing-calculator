#pragma once

#include <string>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int WINDOW_CENTER_X = WINDOW_WIDTH / 2;
const int WINDOW_CENTER_Y = WINDOW_HEIGHT / 2;

const int GRID_SPACING = WINDOW_WIDTH / 10;

const double GRAPH_POINTS_NUMBER = 1000;
const std::string GRAPH_DEFAULT_FORMULA = "";

const double DEFAULT_SCALE = GRID_SPACING;
const double DEFAULT_X_OFFSET = 0;
const double DEFAULT_Y_OFFSET = 0;
const double DEFAULT_LEFT_SPAN = 5;
const double DEFAULT_RIGHT_SPAN = 5;
const sf::Color DEFAULT_COLOR = sf::Color::Blue;

const int INPUT_FIELD_WIDTH = 200;
const int INPUT_FIELD_HEIGHT = 50;
const int INPUT_FIELD_X = 10;
const int INPUT_FIELD_Y = 10;

const std::string WINDOW_TITLE = "My Desmos";