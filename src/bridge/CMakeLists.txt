file(GLOB BRIDGE_SRC ./*.cpp)

add_library(bridge_lib ${BRIDGE_SRC})

target_link_libraries(bridge_lib sfml-graphics)