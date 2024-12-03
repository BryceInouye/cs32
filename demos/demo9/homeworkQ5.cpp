#include <iostream> 
using namespace std; 
int val = 10; 
int foo(int num) { 
    num += val;  
    return num; 
} 

int main() { 
    int result = foo(5 + 3);  
    cout << result << endl; 
    int mynum = 3; 
    result = foo(mynum);  
    cout << result << endl; 
}