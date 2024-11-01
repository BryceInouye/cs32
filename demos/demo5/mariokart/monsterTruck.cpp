#include "kart.h"
#include "monsterTruck.h"

MonsterTruck::MonsterTruck(const string& driver)
        : Kart(driver, 140, 120.0) {}

void MonsterTruck::specialMove() {
    cout << driver << " crushes through obstacles effortlessly!" << "\n";
    useFuel(15);  // Uses 15% fuel for the special move
}
