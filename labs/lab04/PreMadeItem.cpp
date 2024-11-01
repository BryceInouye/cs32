#include "PreMadeItem.h"
#include <iomanip>
#include <sstream>

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(name, size), name(name) {
    price = prices.at(size);
}

PreMadeItem::~PreMadeItem(){
}

std::string PreMadeItem::composeItem(){
    std::ostringstream oss;
    oss << "Pre-made Size: " << size
        << "\nPre-made Item: " << name
        << "\nPrice: $" << std::fixed << std::setprecision(2) << price << "\n";
    return oss.str();
}

double PreMadeItem::getPrice(){
    return price;
}