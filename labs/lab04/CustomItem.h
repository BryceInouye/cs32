#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include "IceCreamItem.h"
#include <map> // pair string to price
using namespace std;

class CustomItem : public IceCreamItem {
    public:
        CustomItem(const string& size);
        virtual ~CustomItem();
        virtual string composeItem();
        virtual double getPrice();
        void addTopping(string topping);
    private:
        map<string, double> sizes = {
            {"small", 3.00},
            {"medium", 5.00},
            {"large", 6.50}
        };
        map<string, int> toppings;
};

#endif // CUSTOMITEM_H