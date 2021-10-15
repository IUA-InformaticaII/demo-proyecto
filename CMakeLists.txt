cmake_minimum_required(VERSION 3.21)
project(testSFML)

set(CMAKE_CXX_STANDARD 14)


#
# Install TMXLITE if not installed
#
find_package(TMXLITE QUIET)

if (NOT ${TMXLITE_FOUND})
    message(STATUS "tmxlite not found, fetching from github...")
    include(FetchContent)
    FetchContent_Declare(
            tmxlite
            GIT_REPOSITORY https://github.com/fallahn/tmxlite
            GIT_TAG v1.2.1
    )
    FetchContent_MakeAvailable(tmxlite)
    add_subdirectory(${tmxlite_SOURCE_DIR}/tmxlite)
    set(TMXLITE_LIBRARIES tmxlite)
    set(TMXLITE_INCLUDE_DIR ${tmxlite_SOURCE_DIR}/tmxlite/include)
endif ()
include_directories(${TMXLITE_INCLUDE_DIR})

add_executable(testSFML
        main.cpp
        clases/auto.cpp
        clases/Mapa.cpp
        clases/Bala.cpp
        )
target_link_libraries(testSFML
        sfml-graphics
        sfml-audio
        sfml-system
        sfml-window
        ${TMXLITE_LIBRARIES}
        )
