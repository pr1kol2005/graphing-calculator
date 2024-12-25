file(GLOB USER_INTERFACE_SRC ./*.cpp)

add_library(ui_lib ${USER_INTERFACE_SRC})

target_link_libraries(ui_lib sfml-graphics sfml-window sfml-system)

target_include_directories(ui_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)

add_executable(ui_test ui_test.cpp)
target_link_libraries(ui_test ui_lib sfml-graphics sfml-window sfml-system)