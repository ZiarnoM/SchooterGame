cmake_minimum_required(VERSION 3.21)
project(SchooterGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(SchooterGame main.cpp Game.cpp Game.h Game.cpp Game.h Player.cpp Player.h Bullet.cpp Bullet.h)

set(SFML_DIR ../../SFML-2.5.1/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)
include_directories(../..//SFML-2.5.1/include)
target_link_libraries(SchooterGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

