SRC = $(file_name)
OUT = a.out

CXX = g++
CXXFLAGS = -std=c++23 -Wall

all: $(OUT)

$(OUT): $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
