# 设置CMake最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(lesson2 VERSION 1.0)

# 设置C标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(lesson2_test test.c)

# 可选：设置编译选项
target_compile_options(lesson2_test PRIVATE -Wall -Wextra)

# 可选：设置输出目录
set_target_properties(lesson2_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)