# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -O2 

# Directories
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include

# Include paths
INCLUDE_PATHS := $(shell find $(INCLUDE_DIR) -type d)
CXXFLAGS += $(addprefix -I, $(INCLUDE_PATHS))

# Find all source files
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
# Generate object file paths
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
# Executable name
TARGET := main

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lX11

# Rule for building object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -lX11

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
