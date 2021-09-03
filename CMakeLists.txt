cmake_minimum_required(VERSION 3.21)
project(testSFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(testSFML main.cpp clases/auto.cpp clases/Mapa.cpp clases/Mapa.h)
target_link_libraries(testSFML sfml-graphics sfml-audio sfml-system sfml-window)
