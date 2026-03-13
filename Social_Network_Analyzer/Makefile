CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = social_network
SRCS = main.cpp graph.cpp storage.cpp commands.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
