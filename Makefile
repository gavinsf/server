CXX = g++
CXXFLAGS = -Wall -std=c++23

TARGET = main

SRC = src/main.cpp src/TcpServer.cpp
OBJDIR = build
BINDIR = bin
OBJS = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRC))

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*