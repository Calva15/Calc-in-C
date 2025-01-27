# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Directories
SRC_DIR = src
OBJ_DIR = build/obj
BUILD_DIR = build

# Target executable
TARGET = $(BUILD_DIR)/calculator

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/operations.c $(SRC_DIR)/ui.c $(SRC_DIR)/history.c

# Object files
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/operations.o $(OBJ_DIR)/ui.o $(OBJ_DIR)/history.o

# Default rule
all: setup $(TARGET)

# Create directories if they don't exist
setup:
	mkdir -p $(OBJ_DIR) $(BUILD_DIR)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Clean only object files
clean-obj:
	rm -rf $(OBJ_DIR)/*.o

.PHONY: all setup clean clean-obj
