#!/bin/bash

sudo apt install g++
sudo apt install cmake
sudo apt install make

sudo apt update
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libfreetype-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev

cd graphing-calculator

cmake -B build;
cmake --build build --target graph_calc

bin/graph_calc