// main.cpp
#include <iostream>
#include "person.h"
#include "student.h"
using namespace std;

int main() {
    
// Basic Use:
    cout << "EXAMPLE OF BASIC USE:" << endl;

    Student me("Gus Anderson", 22, 12345);
    cout << me.getName() << endl;
    cout << me.getAge() << endl;
    cout << me.getStudentId() << endl;




// Inheritance Types
    Person  p1("Maggie Williams", 21);
    Student s1("Alex Yang", 22, 12345678);
    Person p2 = s1;
    // Student s2 = p1;





// Memory Slicing Example:
//      You can assign a Student object to a Person object, 
//      but anything "extra" that was in the Student object will be
//      "sliced" off in memory.

    cout << "\nEXAMPLE OF MEMORY SLICING:" << endl;
    // Let's use p1, p2, s1 from before...
    cout << p2.getName() << endl; // OK – this works
    cout << p2.getAge() << endl; // OK – this works too
    //cout << p2.getStudentId() << endl;  // THIS WON'T WORK!!


// Pointer Rules:
//      Base can point to derived, but not vice-versa

    cout << "\nEXAMPLE OF USE OF POINTERS:" << endl;
    Person* pr1 = new Person("Californian", 30);
    Student* st1 = new Student("Gill", 21, 4567890);
    Person* pr2 = st1; // OK to do!

    cout << pr2->getName() << endl;
    cout << pr2->getAge() << endl;
    //cout << pr2->getStudentId() << endl;   // THIS WON'T COMPILE!!
    cout << st1->getStudentId() << endl;


// Destructor Use:
//      Always call on derived desctructor first, then on base destructor

    cout << "\nEXAMPLE OF USE OF DESTRUCTORS:" << endl;
    cout << "\nWe defined pr1 and st1 pointers earlier. Now we'll delete pr1:" << endl;
    
    delete pr1;
    
    cout << "\nNow we'll delete st1 (note how it will also call the Person destructor automatically):" << endl;
    
    delete st1;

    // The following won't work!!!
    //cout << "\nNow we'll delete pr2 (which was defined earlier as pr2 = st1):" << endl;
    //delete pr2;   // Should cause run-time error! Why?

    Person* pr3 = new Student("Student", 25,7654321);
    cout << "\nDefined new pr3 pointer. Now we'll delete pr3:" << endl;

    delete pr3;

    cout << "---- We just deleted p3 and are about to quit program.\n";
    cout << "What's gonna happen next??" << endl;

    return 0;
}
