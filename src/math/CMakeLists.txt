
file(GLOB MATH_ENGINE_SRC ./*.cpp)

add_library(math_engine_lib ${MATH_ENGINE_SRC})

add_executable(math math_engine.cpp)
target_link_libraries(math math_engine_lib)