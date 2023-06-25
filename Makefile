# Git version
GIT_VERSION := "$(shell git describe --abbrev=4 --dirty --always --tags)"

# compiler
CXX = g++
# compiler flags
CXXFLAGS = -std=c++23 -Wall -DVERSION=\"$(GIT_VERSION)\"

# directory of header files
INCLUDES = -I. -I../Utilities

# sources and objectsC
SOURCES = ./*.cpp ../
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
