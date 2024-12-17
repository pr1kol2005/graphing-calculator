#!/bin/bash

clang-format -i --style=google src/*.cpp
clang-format -i --style=google src/*/*.cpp
clang-format -i --style=google src/*/*.hpp
clang-format -i --style=google src/*/*/*.hpp
# clang-format -i --style=google src/*.hpp