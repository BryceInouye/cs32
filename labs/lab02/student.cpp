#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->setName("another stub");
}

int Student::getPerm() const {
  return -42;
}

const char * const Student::getName() const {
  return "stub";
}

void Student::setPerm(const int permNumber) {
}

void Student::setName(const char * const name) {
  this->name = new char[strlen("stub")+1];
  strcpy(this->name,"stub");
}


Student::Student(const Student &orig) {
  this->setName("yet another stub");
  this->setPerm(-42);
}

Student::~Student() {

}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  return "tostring stub";
}

