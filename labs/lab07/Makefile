CXX=clang++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

test.exe: lab07Test.o tddFuncs.o WordCount.o
	${CXX} $^ -o $@
	# ${CXX} lab06Test.o tddFuncs.o WordCount.o -o test.exe

clean:
	rm -f *.exe *.o
