CXX=g++
CFLAGS=-g -fsanitize=address -fsanitize=leak -fsanitize=undefined
SRC=$(wildcard *.cpp)
TARGET=$(patsubst %.cpp, %, $(SRC))

all: $(TARGET)

%: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)
