#include <memory> 
#include <iostream> 
#include <string> 
using namespace std; 
struct Node { 
    shared_ptr<Node> next; 
    string value; ~Node() { cout << "destroyed object with value " << value << endl; } 
}; 

int main(){ 
    shared_ptr<Node> a = make_shared<Node>(); 
    shared_ptr<Node> b = make_shared<Node>(); 
    shared_ptr<Node> c = make_shared<Node>(); 
    a->value = "a"; 
    b->value = "b"; 
    c->value = "c"; 
    a->next = b;  
    b->next = c;  
    c->next = a;  
    a->next = nullptr;  
    b->next = nullptr;  
    c->next = nullptr;  
    // cout << c.use_count();
    cout << "Done!\n"; 
} 