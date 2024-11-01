#include "IceCreamItem.h"
#include "CustomItem.h"
#include <iomanip>
#include <sstream> // oss

#include <iostream>

CustomItem::CustomItem(const string& size) : IceCreamItem("", size) {
    price = sizes.at(size);
}

CustomItem::~CustomItem() {
    // stub
}

std::string CustomItem::composeItem() {
    std::ostringstream oss;
    oss << "Custom Size: " << size
        << "\nToppings:";

    for (const auto& topping : toppings) {
        oss << "\n" << topping.first << ": "
            << topping.second << " oz";
    }

    oss << std::fixed << std::setprecision(2) << "\nPrice: $" << price << "\n";
    return oss.str();
}

double CustomItem::getPrice() {
    return price;
}

void CustomItem::addTopping (string topping) {
    // if topping doesn't exist, add it, else increment
    if (toppings.find(topping) == toppings.end()) {
        toppings.insert({topping, 1});
    } else {
        toppings.at(topping)++;
    }
    price += 0.4;
}