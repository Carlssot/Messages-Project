#Compiler
CXX := g++

#Compiler flags
CXXFLAGS := -std=c++11 -Wall -g

TARGET := myprog

SRCS := message.cpp messageList.cpp main.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
