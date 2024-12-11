# Makefile format from https://www.geeksforgeeks.org/makefile-in-c-and-its-applications/

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = main

# For deleting the target (using rm for Unix-like systems)
TARGET_DEL = main

# Source files
SRCS = main.cpp user_interface.cpp parser.cpp calculator.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files (using rm for Unix-like systems)
clean:
	rm -f $(TARGET_DEL) $(OBJS)
