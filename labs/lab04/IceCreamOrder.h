#ifndef ICECREAMORDER_H
#define ICECREAMORDER_H

#include <vector>
#include <string>
#include "IceCreamItem.h"

class IceCreamOrder {
public:
	std::string printBill() const;
	void addItem(IceCreamItem* item);
private:
	std::vector<IceCreamItem*> items;
};

#endif

