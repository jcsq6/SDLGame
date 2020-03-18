cmake_minimum_required(VERSION 3.7)

project(WalkingGame)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(WalkingGame src/main.cpp src/objects.cpp src/texture.cpp src/eventHandler.cpp)
target_link_libraries(WalkingGame ${SDL2_LIBRARIES})