# Linux_bit 项目主CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(Linux_bit VERSION 1.0 LANGUAGES C CXX)

# 设置C和C++标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加子目录 - 包含C源文件的lesson
add_subdirectory(lesson2)
add_subdirectory(lesson6)
add_subdirectory(lesson7_gcc)
# add_subdirectory(lesson8)
# add_subdirectory(lesson9)
# add_subdirectory(lesson10_gdb+操作系统)
# add_subdirectory(lesson11_进程概念)
# add_subdirectory(lesson12_进程状态)
# add_subdirectory(lesson13_Linux进程)
# add_subdirectory(lesson14_环境变量)
# add_subdirectory(lesson15_进程地址空间)
# add_subdirectory(lesson16_进程地址空间)
# add_subdirectory(lesson17_进程终止)
# add_subdirectory(lesson18_进程等待)
# add_subdirectory(lesson19_进程替换)
# add_subdirectory(lesson20_myshell_IO)
# add_subdirectory(lesson21_file_fd)
# add_subdirectory(lesson22_重定向)
# add_subdirectory(lesson23_buffer)
# add_subdirectory(lesson24_file)

# 打印配置信息
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")