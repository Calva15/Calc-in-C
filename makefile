# Compiler and flags
CC = gcc
CFLAGS = -Wall -lm

# Directories
SRC_DIR = src
OBJ_DIR = build/obj
BUILD_DIR = build

# Output executable name
TARGET = $(BUILD_DIR)/calculator

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c) # Automatically find all .c files in src/
HEADERS = $(wildcard $(SRC_DIR)/*.h) # Automatically find all .h files in src/

# Object files (convert .c files to .o files in OBJ_DIR)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default rule
all: setup $(TARGET)

# Create necessary directories if they don't exist
setup:
	mkdir -p $(OBJ_DIR) $(BUILD_DIR)

# Build the final executable by linking object files
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

# Rule for compiling .c files into .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean all compiled files and directories
clean:
	rm -rf $(BUILD_DIR)

# Clean only object files
clean-obj:
	rm -rf $(OBJ_DIR)/*.o

.PHONY: all setup clean clean-obj
