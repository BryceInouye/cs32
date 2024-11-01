#include "kart.h"
class StandardKart : public Kart {
public:
    StandardKart(const string& driver);

    void specialMove() override;
};