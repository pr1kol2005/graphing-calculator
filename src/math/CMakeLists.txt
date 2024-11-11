file(GLOB MATH_ENGINE_SRC ./*.cpp)

add_library(math_lib ${MATH_ENGINE_SRC})

add_executable(math_test math_test.cpp)
target_link_libraries(math_test math_lib)