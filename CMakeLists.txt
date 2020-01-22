cmake_minimum_required(VERSION 3.7)

project(SnakeGame CXX)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 14)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(${PROJECT_NAME} src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/snake.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
