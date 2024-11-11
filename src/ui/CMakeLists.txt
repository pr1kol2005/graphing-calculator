file(GLOB USER_INTERFACE_SRC ./*.cpp)

add_library(ui_lib ${USER_INTERFACE_SRC})

target_link_libraries(ui_lib sfml-graphics)

add_executable(ui_test ui_test.cpp)
target_link_libraries(ui_test ui_lib sfml-graphics)