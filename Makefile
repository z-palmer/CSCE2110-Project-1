# Makefile for Driver Database Project

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Target executable
TARGET = driverDB

# Source files
SRCS = main.cpp \
       Driver.cpp \
       SearchDatabase.cpp \
       OrderedDatabase.cpp \
       InactiveDriverDatabase.cpp \
       Address.cpp \
       Date.cpp \
       Ticket.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run program
run: $(TARGET)
	./$(TARGET)