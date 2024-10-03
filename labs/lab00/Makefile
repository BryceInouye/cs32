# Makefile for lab00, BRYCE INOUYE, CS32, F24

CXX=clang++
#CXX=g++

lab00Test: lab00Test.o tddFuncs.o arrayFuncs.o
	${CXX} lab00Test.o tddFuncs.o arrayFuncs.o -o lab00Test

helloWorld: helloWorld.o
	${CXX} helloWorld.o -o helloWorld

clean:
	/bin/rm -f *.o helloWorld lab00Test
