#include "kart.h"
class MonsterTruck : public Kart {
public:
    MonsterTruck(const string& driver);

    void specialMove() override;
};