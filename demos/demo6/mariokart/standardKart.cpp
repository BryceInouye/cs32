#include "kart.h"
#include "standardKart.h"

StandardKart::StandardKart(const string& driver)
        : Kart(driver, 150, 70.0) {}

void StandardKart::specialMove() {
    cout << driver << " performs a Mini-Turbo boost!" << endl;
    useFuel(10);  // Uses 10% fuel for the special move
}