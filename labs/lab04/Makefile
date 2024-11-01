# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES=testIceCreamOrder1 testIceCreamOrder2 testIceCreamOrder3 testIceCreamOrder4

all: ${BINARIES}

testIceCreamOrder1: testIceCreamOrder1.o IceCreamOrder.o IceCreamItem.o CustomItem.o PreMadeItem.o tddFuncs.o
	${CXX} $^ -o $@

testIceCreamOrder2: testIceCreamOrder2.o IceCreamOrder.o IceCreamItem.o CustomItem.o PreMadeItem.o tddFuncs.o
	${CXX} $^ -o $@

testIceCreamOrder3: testIceCreamOrder3.o IceCreamOrder.o IceCreamItem.o CustomItem.o PreMadeItem.o tddFuncs.o
	${CXX} $^ -o $@

testIceCreamOrder4: testIceCreamOrder4.o IceCreamOrder.o IceCreamItem.o CustomItem.o PreMadeItem.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testIceCreamOrder1
	./testIceCreamOrder2
	./testIceCreamOrder3
	./testIceCreamOrder4

clean:
	/bin/rm -f ${BINARIES} *.o
