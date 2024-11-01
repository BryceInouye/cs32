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
	item1->addTopping("mochi");
	order1.addItem(item1);

	string expected = 
"Custom Size: small\n\
Toppings:\n\
mochi: 1 oz\n\
Price: $3.40\n\
-----\n\
Total: $3.40\n";

	ASSERT_EQUALS(expected,order1.printBill());
	delete item1;

	IceCreamOrder order2;
	CustomItem* item2 = new CustomItem("medium");
	item2->addTopping("gummi bears");
	item2->addTopping("gummi bears");
	order2.addItem(item2);

	expected =
"Custom Size: medium\n\
Toppings:\n\
gummi bears: 2 oz\n\
Price: $5.80\n\
-----\n\
Total: $5.80\n";

	ASSERT_EQUALS(expected,order2.printBill());
	delete item2;

	IceCreamOrder order3;
	CustomItem* item3 = new CustomItem("large");
	item3->addTopping("oreos");
	item3->addTopping("peanuts");
	item3->addTopping("peanuts");
	order3.addItem(item3);

	expected =
"Custom Size: large\n\
Toppings:\n\
oreos: 1 oz\n\
peanuts: 2 oz\n\
Price: $7.70\n\
-----\n\
Total: $7.70\n";
	
	ASSERT_EQUALS(expected,order3.printBill());
	delete item3;
}
