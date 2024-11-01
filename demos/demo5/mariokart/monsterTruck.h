#include "kart.h"
class MonsterTruck : public Kart {
public:
    MonsterTruck(const string& driver);

    virtual void specialMove();
};