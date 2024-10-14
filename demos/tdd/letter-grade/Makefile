CXX=g++
CPPFLAGS=--std=c++17

BINARIES=testGrade

all: ${BINARIES}

tests: ${BINARIES}
	./testGrade

testGrade: testGrade.o tddFuncs.o grade.o
	${CXX} ${CPPFLAGS} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
