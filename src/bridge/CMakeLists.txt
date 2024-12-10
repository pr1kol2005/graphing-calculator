file(GLOB BRIDGE_SRC ./*.cpp)

add_library(bridge_lib ${BRIDGE_SRC})

target_sources(bridge_lib PRIVATE
  ../ui/graph_view.cpp
)

target_link_libraries(bridge_lib sfml-graphics sfml-window sfml-system)