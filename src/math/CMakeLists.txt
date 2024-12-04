file(GLOB MATH_ENGINE_SRC ./*.cpp)

add_library(math_lib ${MATH_ENGINE_SRC})

target_include_directories(math_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)

add_executable(math_test math_test.cpp)
target_link_libraries(math_test math_lib)