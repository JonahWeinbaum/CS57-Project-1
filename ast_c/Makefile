CXX := clang++-10
CXXFLAGS := -g -O0 -march=native
CC := clang-10

test2: test2.o ast.o
	$(CXX) $(CXXFLAGS) -o test2 $^

test2.o: test2.c
	$(CXX) $(CXXFLAGS) -c test2.c
ast.o: ast.c ast.h
	$(CXX) $(CXXFLAGS) -c ast.c -o ast.o

.PHONY: clean
clean:
	rm -f *.o test2
