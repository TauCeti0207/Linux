# lesson14_环境变量 CMakeLists.txt
add_executable(lesson14_01test 01test.c)
add_executable(lesson14_02test 02test.c)
add_executable(lesson14_03test 03test.c)
add_executable(lesson14_04test 04test.c)
add_executable(lesson14_05test 05test.c)
add_executable(lesson14_mytest mytest.c)

# 添加子目录
add_subdirectory(ex1)
add_subdirectory(ex2)
add_subdirectory(ex3)
add_subdirectory(ex4)
add_subdirectory(ex5)
add_subdirectory(ex6)
add_subdirectory(ex7)