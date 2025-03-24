# Compiler and flags
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and object files
SRCS  := $(wildcard *.cpp)
OBJS  := $(SRCS:.cpp=.o)
TARGET = inversion_counting

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	@echo "Cleaning up..."
	@if [ -f $(TARGET) ]; then rm -f $(TARGET); fi
	@rm -f $(OBJS)

.PHONY: all clean run
