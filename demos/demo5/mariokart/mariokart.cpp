#include <iostream>
#include <string>
#include <vector>
#include "kart.h"
#include "standardKart.h"
#include "bike.h"
#include "monsterTruck.h"
using namespace std;

void testKart(Kart* kart) {
    kart->displayStats();
    kart->specialMove();
}


// Main function
int main() {
    // step 1: create a MonsterTruck object
    MonsterTruck truck("bob");

    // step 2: display the stats for the MonsterTruck you created
    truck.displayStats();

    // step 3: perform the special move for the MonsterTruck
    truck.specialMove();

    // step 4: create a MonsterTruck* pointer and point it to the MonsterTruck object
    // display the stats and perform special move using this MonsterTruck* pointer
    // MonsterTruck
    MonsterTruck* mt = &truck;
    mt->displayStats();
    mt->specialMove();
    // step 5: create a Kart* (base class pointer) and point it to the MonsterTruck object
    // display the stats and perform special move using this Kart* pointer
    Kart* kart = mt;
    kart->displayStats();
    kart->specialMove();

    // (don't do this during 1st Activity) step 6: create a vector that can hold Kart* objects 
    // add 3 different types of derived Kart objects to the vector
    vector<Kart*>karts;
    StandardKart kart1("A");
    MonsterTruck kart2("B");
    Bike kart3("C");
    karts.push_back(&kart1);
    karts.push_back(&kart2);
    karts.push_back(&kart3);
    // step 7: iterate through the vector and call the testKart() function for each "Kart"
    for (Kart* kart : karts) {
        // testKart(kart);
        kart->displayStats();
        kart->specialMove();
    }

    return 0;
}
