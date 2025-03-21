# Makefile for compiling and testing svp.cpp using gcc

# Compiler settings
CC = gcc
CXXFLAGS = -Wall -Wextra -O2 -pg
LDFLAGS = -lstdc++  # Link against the C++ standard library

# Target executable name
TARGET = runme

# Source files
SOURCES = svp.cpp

# Build rules
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS) -lm

# Clean rule for Windows
clean:
	rm -f $(TARGET)

# Test rule
test:
	./$(TARGET) [1.0 0.0 0.0] [0.0 1.0 0.0] [0.0 0.0 1.0]
	@echo "Running test 1 "
	@grep "1" result.txt >nul && (echo "Test passed") || (echo "Test failed")

	./$(TARGET) [1 2 3 4 5 6 7 8 9 10] [6 7 8 4 5 6 7 8 9 10] [2 5 7 4 5 6 7 8 9 10] [2 5 0 1 2 3 4 5 6 7] [0 9 8 7 6 5 4 3 2 1] [1 2 3 4 5 6 7 8 9 10] [1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 10.10] [1 1 1 1 1 1 1 1 1 1] [ 2 2 2 2 2 2 2 2 2 2] [3 4 5 6 7 1 2 3 4 5]
	@echo "Running est 2"
	@grep "3.16228" result.txt >nul && (echo "Test passed") || (echo "Test failed")

	./$(TARGET) [1 2 3] [6 7 8] [2 5 7]
	@echo "Running test 3 ..."
	@grep "3.74166" result.txt >nul && (echo "Test passed") || (echo "Test failed")
