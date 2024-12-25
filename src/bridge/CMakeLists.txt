file(GLOB BRIDGE_SRC ./*.cpp)

add_library(bridge_lib ${BRIDGE_SRC})

target_include_directories(bridge_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/src/math/includes
    ${CMAKE_SOURCE_DIR}/src/ui/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)

target_sources(bridge_lib PRIVATE
  ../ui/graph_view.cpp
)

target_link_libraries(bridge_lib sfml-graphics sfml-window sfml-system)