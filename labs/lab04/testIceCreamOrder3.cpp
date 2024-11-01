#include <iostream>
#include <string>

#include "IceCreamOrder.h"
#include "PreMadeItem.h"
#include "tddFuncs.h"

using namespace std;

int main() {
	cout << "Running tests from: " << __FILE__ << endl;

	IceCreamOrder order1;

	PreMadeItem* item1 = new PreMadeItem("Chewy Gooey", "small");
	order1.addItem(item1);

	string expected = 
"Pre-made Size: small\n\
Pre-made Item: Chewy Gooey\n\
Price: $4.00\n\
-----\n\
Total: $4.00\n";

	ASSERT_EQUALS(expected,order1.printBill());
	delete item1;

	IceCreamOrder order2;

	PreMadeItem* item2 = new PreMadeItem("Banana Slamma", "medium");
	order2.addItem(item2);

	expected = 
"Pre-made Size: medium\n\
Pre-made Item: Banana Slamma\n\
Price: $6.00\n\
-----\n\
Total: $6.00\n";

	ASSERT_EQUALS(expected,order2.printBill());
	delete item2;

	IceCreamOrder order3;

	PreMadeItem* item3 = new PreMadeItem("Sludge Fudge", "large");
	order3.addItem(item3);

	expected = 
"Pre-made Size: large\n\
Pre-made Item: Sludge Fudge\n\
Price: $7.50\n\
-----\n\
Total: $7.50\n";

	ASSERT_EQUALS(expected,order3.printBill());
	delete item3;
}
