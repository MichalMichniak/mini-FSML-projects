cmake_minimum_required(VERSION 3.15)

project(simulation)

set(CMAKE_CXX_STANDARD 23)

#add_compile_options(-Wall -Wextra)


set(SIM3D_SOURCES src/Vector.cpp src/Point.cpp)

find_package(SFML 2.5 COMPONENTS graphics window audio system REQUIRED)

add_executable(rotations3D src/normalized_plane.cpp ${SIM3D_SOURCES})
add_executable(one_direction_perspective src/spining_cube.cpp ${SIM3D_SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(rotations3D PUBLIC sfml-graphics sfml-window sfml-audio sfml-system)
target_link_libraries(one_direction_perspective PUBLIC sfml-graphics sfml-window sfml-audio sfml-system)