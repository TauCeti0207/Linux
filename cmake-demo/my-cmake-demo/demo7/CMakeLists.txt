# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.0)

#project name
project(SOLIDER)

#head file path 绝对路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# append compile options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -Wall")

#add executable file  
add_executable(my_cmake_main main.cpp src/Gun.cpp src/Solider.cpp)

