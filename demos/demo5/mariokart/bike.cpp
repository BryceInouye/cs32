#include "kart.h"
#include "bike.h"

Bike::Bike(const string& driver)
        : Kart(driver, 160, 50.0) {}

void Bike::specialMove() {
    cout << driver << " performs a Wheelie for extra speed!" << endl;
    useFuel(5);  // Uses 5% fuel for the special move
}
