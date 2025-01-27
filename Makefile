# Compiler 
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Ilib/nlohmann

# Dirs
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TEST_DIR = test

# Executable
TARGET = StockiFy
TEST_TARGET = test_bin.out

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)   
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))   

TEST_FILES = $(wildcard $(TEST_DIR)/**/*.cpp $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_FILES))

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@


test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ_FILES) $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^
	mv $(TEST_TARGET) $(TEST_DIR)/$(TEST_TARGET)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@;


clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

.PHONY: all clean tests
