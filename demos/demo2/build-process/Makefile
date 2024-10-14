# Makefile
CXX=g++
CPPFLAGS=--std=c++17

main: func.o main.o
	${CXX} ${CPPFLAGS} -o main func.o main.o

# omitting target for each *.o file, as they will be generated from the implicit rule
# check the Tip box in lab00.pdf (pg. 14)

clean:
	rm -f *.o main
