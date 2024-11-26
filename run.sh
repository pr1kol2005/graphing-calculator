sudo upt install g++
sudo upt install cmake

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