#include <iostream>
#include <memory>
using namespace std;

class Player { 
    public:
	    weak_ptr<Player> companion; 
	    ~Player() {cout << "~Player\n"; } 
}; 

int main() { 
	shared_ptr<Player> nancy = make_shared<Player>();
	shared_ptr<Player> oliver = make_shared<Player>();

    cout << "for nancy:: " << nancy.use_count() << endl;
    cout << "for oliver: " << oliver.use_count() << endl;

    nancy->companion = oliver;
	oliver->companion = nancy;

    cout << "\nUse Count After Cyclical Links:\n";
    cout << "for nancy:: " << nancy.use_count() << endl;
    cout << "for oliver: " << oliver.use_count() << endl;
}
