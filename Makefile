CXX=g++

CXXFLAGS= -std=c++17 -Wall -g

BINARIES=testStudent00 testStudent01 testStudent02 testStudent03 \
	testStudentRoll00 	testStudentRoll01 testStudentRoll02

all: ${BINARIES}

tests: ${BINARIES}
	./testStudent00
	./testStudent01
	./testStudent02
	./testStudent03
	./testStudentRoll00
	./testStudentRoll01
	./testStudentRoll02

lts00: testStudent00
	- valgrind -q --leak-check=full ./testStudent00

lts01: testStudent01
	- valgrind -q --leak-check=full ./testStudent01

lts02: testStudent02
	- valgrind -q --leak-check=full ./testStudent02

lts03: testStudent03
	- valgrind -q --leak-check=full ./testStudent03

ltsr00: testStudentRoll00
	- valgrind -q --leak-check=full ./testStudentRoll00

ltsr01: testStudentRoll01
	- valgrind -q --leak-check=full ./testStudentRoll01

ltsr02: testStudentRoll02
	- valgrind -q --leak-check=full ./testStudentRoll02

leaktests: lts00 lts01 lts02 lts03 ltsr00 ltsr01 ltsr02

clean:
	/bin/rm -f *.o ${BINARIES}

testStudent00: testStudent00.o student.o tddFuncs.o
	${CXX} $^ -o $@

testStudent01: testStudent01.o student.o tddFuncs.o
	${CXX} $^ -o $@

testStudent02: testStudent02.o student.o tddFuncs.o
	${CXX} $^ -o $@

testStudent03: testStudent03.o student.o tddFuncs.o
	${CXX} $^ -o $@

testStudentRoll00: testStudentRoll00.o student.o studentRoll.o tddFuncs.o
	${CXX} $^ -o $@

testStudentRoll01: testStudentRoll01.o student.o studentRoll.o tddFuncs.o
	${CXX} $^ -o $@

testStudentRoll02: testStudentRoll02.o student.o studentRoll.o tddFuncs.o
	${CXX} $^ -o $@



