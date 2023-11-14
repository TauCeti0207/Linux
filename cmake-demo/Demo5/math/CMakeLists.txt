# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 指定生成 MathFunctions 链接库
add_library (MathFunctions ${DIR_LIB_SRCS})

# 指定 MathFunctions 库的安装路径
install (TARGETS MathFunctions DESTINATION lib)#MathFunctions库的目标文件（TARGETS）应该被安装到lib目录下。这里的lib是指系统库的安装目录，通常是在安装根目录下的/lib或/usr/lib等。
install (FILES MathFunctions.h DESTINATION include)#MathFunctions.h头文件应该被安装到include目录下。这里的include是指系统头文件的安装目录，通常是在安装根目录下的/include或/usr/include等。
