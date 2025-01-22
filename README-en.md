## Available languages

1. [Russian](README.md)
2. [English](README-en.md)

## Brief Description

Graphical calculator and graph plotter.

UML diagrams for the project are stored in the [images](images) directory.

The file [constants.h](src/ui/constants.h) contains the constants `WINDOW_WIDTH` and `WINDOW_HEIGHT`, which define the window's width and height.

## Build and Run Instructions

#### If you are using Linux, skip steps 1-5 and simply run the script [run.sh](run.sh).

1) Ensure that Homebrew is installed, then execute the following commands:

  ```sh
  brew install g++;
  brew install cmake;
  ```

2) Clone the remote repository (make sure you have Git installed):

  ```sh
  git clone git@gitlab.com:fakepr1kol2005/graphing-calculator.git
  ```

3) Build the project:

  ```sh
  cmake -B build;
  cmake --build build --target graph_calc
  ```

5) Run the calculator:
  ```sh
  bin/graph_calc
  ```