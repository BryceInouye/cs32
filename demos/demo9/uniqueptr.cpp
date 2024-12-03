#include <iostream>
#include <string>
#include <memory>

int main() {
    std::unique_ptr<int> p1(new int(10));
    // auto p1 = std::make_unique<int>(10);
    *p1 = 99;
    std::cout << "p1 dereferences to this value: " << *p1 << "\n";

    // is this okay to do?
    // std::unique_ptr<int> p2 = p1;
    // std::cout << "p2 dereferences to this value: " << *p2 << "\n";

    return 0;
}
