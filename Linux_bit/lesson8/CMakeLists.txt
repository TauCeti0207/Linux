# lesson8 CMakeLists.txt
add_executable(lesson8_main main.c test.c)
add_executable(lesson8_mytest mytest.c)

# 添加子目录
add_subdirectory(ex2)
add_subdirectory(ex3)
add_subdirectory(ex4)