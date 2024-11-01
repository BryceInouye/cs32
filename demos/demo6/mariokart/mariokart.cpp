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
    Kart* kart = new Bike("Peach");
    kart->displayStats();
    // this will segfault, fix Bike::specialMove() to fix it
    kart->specialMove();

    // is this delete operation clearing the memory properly?
    delete kart;

    return 0;
}
