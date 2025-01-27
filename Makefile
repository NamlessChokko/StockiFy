# Compiler 
CXX = g++                               # Compiler
CXXFLAGS = -std=c++17 -Wall -Iinclude   # Compiler Flags

# Dirs
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include/

# Executable
TARGET = StockiFy


# Source and object files 
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)   
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))   



all: $(TARGET)

$(TARGET): $(OBJ_FILES)
    @echo "Linking..."
    $(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(@D)
    @echo "Compiling $<..."
    $(CXX) $(CXXFLAGS) -c $< -o $@


clean:
    @echo "Cleaning build files..."
    rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean