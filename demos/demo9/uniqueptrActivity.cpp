#include <iostream>
#include <string>
#include <memory> // smart pointer

class Resource
{
    public:
        Resource(int v): value(v) {}
        ~Resource() { std::cout << "destroyed\n"; }
        int value;
};

int main() {
    // Resource* res = new Resource(10);

    std::unique_ptr<Resource> res(new Resource(10));


    auto res = std::make_unique<Resource>(10); // recommended
    std::unique_ptr<Resource> res = std::make_unique<Resource>(10);
    
    if(res) {
        res->value = 25;
        std::cout << "resource value: " << res->value << "\n";
    }
    
    return 0;
}
