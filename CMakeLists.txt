cmake_minimum_required(VERSION 3.28)
project(graphing_calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL
  SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(graph_calc src/main.cpp)
target_link_libraries(graph_calc math_lib ui_lib bridge_lib)
target_include_directories(graph_calc PRIVATE src/math src/ui src/bridge)

add_subdirectory(src/math math)
add_subdirectory(src/ui ui)
add_subdirectory(src/bridge bridge)

if(WIN32)
  add_custom_command(
    TARGET main
    COMMENT "Copy OpenAL DLL"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
    VERBATIM)
endif()
