# Compiler and flags
CXX = clang
CXXFLAGS = -Wall -Wextra -std=c11 -g

# Raylib and system libraries
# -lcs50      -> CS50 library

LIBS = -lcs50 

# Source and output 
SRC = tideman.c 
OUT = tideman 

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)
