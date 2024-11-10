file(GLOB USER_INTERFACE_SRC ./*.cpp)

add_library(ui_lib ${USER_INTERFACE_SRC})

add_executable(ui ui_contoller.cpp)
target_link_libraries(ui ui_lib)