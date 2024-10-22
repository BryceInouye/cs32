CXX=g++
CPPFLAGS=--std=c++17

mergeTest: testMerge
	./testMerge

qsTest: testQS
	./testQS

partitionTest: testPartition
	./testPartition


testMerge: testMerge.o tddFuncs.o ms.o
	${CXX} ${CPPFLAGS} -o testMerge testMerge.o tddFuncs.o ms.o

testQS: testQS.o tddFuncs.o qs.o
	${CXX} ${CPPFLAGS} -o testQS testQS.o tddFuncs.o qs.o

testPartition: testPartition.o tddFuncs.o qs.o
	${CXX} ${CPPFLAGS} -o testPartition testPartition.o tddFuncs.o qs.o

clean:
	/bin/rm -f testPartition testQS testMerge *.o
