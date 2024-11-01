#include <iostream>
#include <string>

#include "IceCreamOrder.h"
#include "CustomItem.h"
#include "tddFuncs.h"

using namespace std;

int main() {
	cout << "Running tests from: " << __FILE__ << endl;

	IceCreamOrder order1;

	CustomItem* item1 = new CustomItem("small");
	order1.addItem(item1);

	string expected = 
"Custom Size: small\n\
Toppings:\n\
Price: $3.00\n\
-----\n\
Total: $3.00\n";

	ASSERT_EQUALS(expected,order1.printBill());
	delete item1;

	IceCreamOrder order2;
	CustomItem* item2 = new CustomItem("medium");
	order2.addItem(item2);

	expected =
"Custom Size: medium\n\
Toppings:\n\
Price: $5.00\n\
-----\n\
Total: $5.00\n";

	ASSERT_EQUALS(expected,order2.printBill());
	delete item2;

	IceCreamOrder order3;
	CustomItem* item3 = new CustomItem("large");
	order3.addItem(item3);

	expected =
"Custom Size: large\n\
Toppings:\n\
Price: $6.50\n\
-----\n\
Total: $6.50\n";
	
	ASSERT_EQUALS(expected,order3.printBill());
	delete item3;
}
