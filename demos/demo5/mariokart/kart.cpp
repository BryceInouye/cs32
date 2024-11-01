#include "kart.h"

Kart::Kart(const string& driver, int maxSpeed, float weight)
                : driver(driver)
                , maxSpeed(maxSpeed)
                , weight(weight)
                , fuel(100) // Fuel is initialized to 100%
        {}  

void Kart::displayStats() {
    cout << "Driver: " << driver << endl;
    cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    cout << "Weight: " << weight << " kg" << "\n\n";
}

void Kart::specialMove() {
    cout << driver << " has NO special move!" << endl;
}

void Kart::useFuel(int amount) {
    if (fuel >= amount) {
        fuel -= amount;
        cout << driver << " used " << amount << "% fuel. Remaining fuel: " << fuel << "%" << "\n\n";
    } else {
        cout << driver << " is out of fuel!" << endl;
    }
}

Kart::~Kart() {
}
