# Compiler and flags
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and object files
SRCS  := $(wildcard src/*.cpp)
OBJS  := $(SRCS:.cpp=.o)
TARGET = stack_allocator_test

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

# this took too long to figure out and just went with a simple rule instead
clean:
	@echo Cleaning up...
	-@del /Q src\*.o >nul 2>&1
	-@del /Q *.exe >nul 2>&1
