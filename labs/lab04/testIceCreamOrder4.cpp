#include <iostream>
#include <string>

#include "IceCreamOrder.h"
#include "PreMadeItem.h"
#include "CustomItem.h"
#include "tddFuncs.h"

using namespace std;

int main() {
	cout << "Running tests from: " << __FILE__ << endl;

	IceCreamOrder order1;

	PreMadeItem* item1 = new PreMadeItem("Chewy Gooey", "small");
	order1.addItem(item1);
	CustomItem* item2 = new CustomItem("small");
	item2->addTopping("mochi");
	order1.addItem(item2);

	string expected = 
"Pre-made Size: small\n\
Pre-made Item: Chewy Gooey\n\
Price: $4.00\n\
-----\n\
Custom Size: small\n\
Toppings:\n\
mochi: 1 oz\n\
Price: $3.40\n\
-----\n\
Total: $7.40\n";

 	ASSERT_EQUALS(expected,order1.printBill());
 	delete item1;
 	delete item2;

 	IceCreamOrder order2;
 	CustomItem* item3 = new CustomItem("large");
 	item3->addTopping("almonds");
 	item3->addTopping("granola");
 	item3->addTopping("walnuts");
 	order2.addItem(item3);
 	CustomItem* item4 = new CustomItem("medium");
 	item4->addTopping("snickers");
 	item4->addTopping("snickers");
 	item4->addTopping("snickers");
 	order2.addItem(item4);

 	expected =
"Custom Size: large\n\
Toppings:\n\
almonds: 1 oz\n\
granola: 1 oz\n\
walnuts: 1 oz\n\
Price: $7.70\n\
-----\n\
Custom Size: medium\n\
Toppings:\n\
snickers: 3 oz\n\
Price: $6.20\n\
-----\n\
Total: $13.90\n";

 	ASSERT_EQUALS(expected,order2.printBill());
 	delete item3;
 	delete item4;

	IceCreamOrder order3;
	PreMadeItem* item5 = new PreMadeItem("Sludge Fudge", "large");
	order3.addItem(item5);
	PreMadeItem* item6 = new PreMadeItem("Banana Slamma", "medium");
	order3.addItem(item6);
	CustomItem* item7 = new CustomItem("medium");
	item7->addTopping("cherries");
	item7->addTopping("sprinkles");
	item7->addTopping("sprinkles");
	order3.addItem(item7);

	expected = 
"Pre-made Size: large\n\
Pre-made Item: Sludge Fudge\n\
Price: $7.50\n\
-----\n\
Pre-made Size: medium\n\
Pre-made Item: Banana Slamma\n\
Price: $6.00\n\
-----\n\
Custom Size: medium\n\
Toppings:\n\
cherries: 1 oz\n\
sprinkles: 2 oz\n\
Price: $6.20\n\
-----\n\
Total: $19.70\n";

	ASSERT_EQUALS(expected,order3.printBill());
	delete item5;
	delete item6;
	delete item7;
}
