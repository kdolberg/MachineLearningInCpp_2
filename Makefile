# compiler
CXX = g++
# compiler flags
CXXFLAGS = -std=c++23 -Wall

# directory of header files
INCLUDES = -I. -I../Utilities

# sources and objects
SOURCES = ANN.cpp main_test.cpp propagation.cpp activation_functions.cpp memory_allocation.cpp overloads.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# target executable
TARGET = out

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
