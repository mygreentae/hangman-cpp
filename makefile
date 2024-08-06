# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = hangman

# Source files
SRCS = main.cpp hangman.cpp

# Object files
OBJS = hangman.o main.o

# Default target
all: $(TARGET)

# Rule for linking the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule for compiling hangman.cpp to hangman.o
hangman.o: hangman.cpp hangman.h
	$(CXX) $(CXXFLAGS) -c hangman.cpp -o hangman.o

# Rule for compiling main.cpp to main.o
main.o: main.cpp hangman.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Clean target to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)
