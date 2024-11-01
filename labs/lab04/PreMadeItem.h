#ifndef PREMADEITEM_H
#define PREMADEITEM_H

#include "IceCreamItem.h"
#include <unordered_map>
#include <vector>

class PreMadeItem : public IceCreamItem {
    public:
        PreMadeItem(std::string name, std::string size);
        virtual ~PreMadeItem();
        virtual std::string composeItem();
        virtual double getPrice();
    private:
        std::unordered_map<std::string, double> prices = {
            {"small", 4.00},
            {"medium", 6.00},
            {"large", 7.50}
        };
        std::string name;
        std::unordered_map<std::string, int> toppings;
        std::vector<std::string> toppingOrder;
};

#endif // PREMADEITEM_H