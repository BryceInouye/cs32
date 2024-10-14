CXX=g++
CPPFLAGS=--std=c++17

BINARIES=testBankAccount

all: ${BINARIES}

tests: ${BINARIES}
	./testBankAccount

testBankAccount: testBankAccount.o tddFuncs.o bankAccount.o
	${CXX} ${CPPFLAGS} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
