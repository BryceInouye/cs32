// Shared Pointers
#include <iostream>
#include <string>
#include <memory>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(42);
    
    // You can also do this declaration instead (but make_shared is preferred):
    //shared_ptr<int> p1(new int(42));

    std::cout << "p1 deferences to this value: " << *p1 << std::endl;
    std::cout << "p1 use count = " << p1.use_count() << std::endl;

    std::shared_ptr<int> p2 = p1;
    std::cout << "p1 use count = " << p1.use_count() << std::endl;


    if (true) {
        // Whatever we do here with a shared_ptr,
        // it is ONLY valid within the defined block
        std::shared_ptr<int> p3 = p1;
        std::cout << "(inside if block) p1 use count = " << p1.use_count() << std::endl;
    }

    std::cout << "p1 use count = " << p1.use_count() << std::endl;

    p2 = nullptr;

    std::cout << "p1 use count after p2=nullptr = " << p1.use_count() << std::endl;

    std::cout << "\nThis program is finished!\n";
    return 0;
}
