CXX = g++
CXXFLAGS = -Wall -std=c++23

TARGET = main

SRC = src/main.cpp src/TcpServer.cpp
OBJS = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: $(TARGET)
	./$(TARGET)


clean:
	rm -f src/*.o $(TARGET)