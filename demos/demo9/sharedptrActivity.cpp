#include <iostream>
#include <string>
#include <memory>

class Resource
{
    public:
        Resource(int v): value(v) {}
        ~Resource() { std::cout << "destroyed\n"; }
        int value;
};

int main() {
    // std::unique_ptr<Resource> res1 = std::make_unique<Resource>(10);
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>(10);
    
    if(res1) {
        res1->value = 25;
        std::cout << "resource value: " << res1->value << "\n";

        // 1. fix any issues here
        std::shared_ptr<Resource> res2 = res1;
        res2->value = 55;
        std::cout << "resource value: " << res2->value << "\n";

        // 2. print how many pointers are pointing to the Resource object at this point
        std::cout << "num pointing to resource object: " << res1.use_count() << "\n";
    }

    // 3. print how many pointers are pointing to the Resource object at this point
    std::cout << "num pointing to resource object: " << res1.use_count() << "\n";
    
    return 0;
}
