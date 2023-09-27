# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRC = SimpleVM.cpp
SRC_READ = ReadBin.cpp

# Output executable
OUT = simpleVM
OUT_READ = readBin

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

read: $(OUT_READ)

$(OUT_READ): $(SRC_READ)
	$(CXX) $(CXXFLAGS) -o $(OUT_READ) $(SRC_READ)

clean:
	rm -f $(OUT) $(OUT_READ)