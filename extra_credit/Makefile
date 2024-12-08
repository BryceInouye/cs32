CXX = g++
CXXFLAGS = -std=c++17

# all: game 

# Compile and run game
game: game.o Person.o Item.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	./game

game.o: game.cpp
	$(CXX) $(CXXFLAGS) -c game.cpp
Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp
Item.o: Item.cpp
	$(CXX) $(CXXFLAGS) -c Item.cpp

# Clean up
clean:
	rm -f game *.o *.exe
