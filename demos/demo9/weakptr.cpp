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

#include <iostream>
#include <memory> // For shared_ptr and weak_ptr

class Resource {
public:
    Resource(int v) : value(v) {}
    ~Resource() { std::cout << "destroyed\n"; }
    int value;
};

int main() {
    std::weak_ptr<Resource> wptr; // Weak pointer

    {
        std::shared_ptr<Resource> sptr = std::make_shared<Resource>(42);
        wptr = sptr; // wptr observes sptr

        std::cout << "Inside block: Resource value = " << sptr->value << std::endl;

        // Check if the weak_ptr is expired
        if (!wptr.expired()) {
            std::cout << "Inside block: Resource is still valid." << std::endl;
        }
    } // sptr goes out of scope here, and the Resource is destroyed

    // Check again after the shared_ptr is destroyed
    if (wptr.expired()) {
        std::cout << "Outside block: Resource has expired." << std::endl;
    } else {
        auto locked = wptr.lock(); // Lock the weak_ptr to create a shared_ptr
        std::cout << "Outside block: Resource value = " << locked->value << std::endl;
    }
    
    return 0;
}
