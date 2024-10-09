# Makefile
CXX=g++
CPPFLAGS=--std=c++17

cs32kart: aimove.o graphics.o cs32kart.o 
	${CXX} ${CPPFLAGS} -o cs32kart aimove.o graphics.o cs32kart.o 

# omitting target for each *.o file, as they will be generated from the implicit rule
# check the Tip box in lab00.pdf (pg. 14)

cs32kart2: aimove2.o graphics.o cs32kart.o 
	${CXX} ${CPPFLAGS} -o cs32kart2 aimove2.o graphics.o cs32kart.o 

clean:
	rm -f *.o cs32kart cs32kart2
