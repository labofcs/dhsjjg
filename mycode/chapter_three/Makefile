# 编译器和工具
CC = gcc
RM = rm -rf
ifeq ($(OS),Windows_NT)
	MKDIR := mkdir
else
	MKDIR := mkdir -p
endif

# 目录定义
SRC_DIR = src
INC_DIR = inc
LIB_DIR = lib
TEST_DIR = test

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)\obj
BIN_DIR = $(BUILD_DIR)\bin

# 测试相关目录
TEST_BUILD_DIR = $(BUILD_DIR)\test
TEST_OBJ_DIR = $(TEST_BUILD_DIR)\obj
TEST_BIN_DIR = $(TEST_BUILD_DIR)\bin

# 文件集合
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d) # 自动生成的依赖关系文件

# 测试文件集合
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(TEST_OBJ_DIR)/%.o, $(TEST_SRCS))
TEST_DEPS = $(TEST_OBJS:.o=.d)	# 自动生成的依赖关系文件

# 可执行文件名称
TARGET = sq_list_main
EXECUTABLE = $(BIN_DIR)/$(TARGET)

TEST_TARGET = test_sq_list_main
TEST_EXECUTABLE = $(TEST_BIN_DIR)/$(TEST_TARGET)

# 编译选项
# CFLAGS = -Wall -Werror -pedantic -I$(INC_DIR)
CFLAGS = -Wall -I$(INC_DIR)
LDFLAGS = -L$(LIB_DIR)
# LDFLAGS = -L$(LIB_DIR) -lthird_party
# 测试编译选项
TEST_LDFLAGS = $(LDFLAGS) -lCUnit

# 调试模式开关
ifeq ($(DEBUG),1)
CFLAGS += -g -O0
else
CFLAGS += -O2
endif

# 默认目标
all: $(EXECUTABLE)

# 包含自动生成的依赖关系
-include $(DEPS)
-include $(TEST_DEPS)

# 链接目标文件生成可执行文件
$(EXECUTABLE): $(OBJS) | $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

# 编译.c文件并生成依赖
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# 创建目录（order-only prerequisites）
$(BUILD_DIR) $(OBJ_DIR) $(BIN_DIR) $(TEST_BUILD_DIR) $(TEST_OBJ_DIR) $(TEST_BIN_DIR):
	$(MKDIR) $@

# 测试目标（需要先编译主程序）
test: $(TEST_EXECUTABLE)
$(TEST_EXECUTABLE): $(TEST_OBJS) $(OBJS) | $(TEST_BIN_DIR)
	$(CC) $^ -o $@ $(TEST_LDFLAGS)

# 清理构建产物
clean:
	$(RM) $(BUILD_DIR)

# 伪目标声明
.PHONY: all clean test
