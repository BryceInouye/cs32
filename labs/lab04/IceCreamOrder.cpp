#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "IceCreamOrder.h"
#include "IceCreamItem.h"

using namespace std;

string IceCreamOrder::printBill() const {
	double totalPrice = 0;
	string out = "";

	for (size_t i = 0; i < items.size(); i++) {
		totalPrice += items[i]->getPrice();
		out += items[i]->composeItem();
		out += "-----\n";
	}
	stringstream stream;
	stream << fixed << setprecision(2) << totalPrice;
	out += "Total: $" + stream.str() + "\n";
	return out;
}

void IceCreamOrder::addItem(IceCreamItem* item) {
	items.push_back(item);
}
