# 定义编译器
CC := gcc
# 定义编译选项
CFLAGS := -Wall -g

# 源文件和目标文件
SRC = mytest.c
OBJ = $(SRC:.c=.o) #这是一个模式替换表达式，它会对SRC变量中的每个.c扩展名进行替换，将其变为.o
TARGET = mytest

# 默认目标
all: $(TARGET)

# 显式规则: 预处理

# $@是一个特殊的自动变量，它代表当前规则的左边的目标文件名。在这个例子中，如果预处理规则的目标是test.i，那么$@就会被替换为test.i。
$(SRC:.c=.i): $(SRC)
	@echo "预处理阶段:"
	@echo "----------------"
	$(CC) $(CFLAGS) -E $(SRC) -o $@ 
	@echo "----------------"

# 显式规则: 汇编
$(SRC:.c=.s): $(SRC:.c=.i)
	@echo "汇编阶段:"
	@echo "----------------"
	$(CC) $(CFLAGS) -S $(SRC:.c=.i) -o $@
	@echo "----------------"

# 显式规则: 编译（从汇编生成目标文件）
$(OBJ): $(SRC:.c=.s)
	@echo "编译阶段:"
	@echo "----------------"
	$(CC) $(CFLAGS) -c $(SRC:.c=.s) -o $@
	@echo "----------------"

# 隐式规则: 链接
$(TARGET): $(OBJ)
	@echo "链接阶段:"
	@echo "----------------"
	$(CC) $(OBJ) -o $@
	@echo "----------------"

# 清理目标
.PHONY: clean
clean:
	@echo "清理阶段:"
	@echo "----------------"
	rm -f $(OBJ) $(TARGET) $(SRC:.c=.i) $(SRC:.c=.s)
	@echo "----------------"