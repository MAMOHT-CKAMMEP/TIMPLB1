CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = cipher_app
SRCS = main.cpp routecipher.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run