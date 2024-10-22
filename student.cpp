#include "student.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

Student::Student(const char * const name, int perm) : name(nullptr) {
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return this->name;
}

void Student::setPerm(const int permNumber) {
  perm = permNumber;
}

void Student::setName(const char * const name) {
  delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}


Student::Student(const Student &orig) {
  if (orig.name) {
    this->name = new char[strlen(orig.name) + 1];
    strcpy(this->name, orig.name);
  }
  this->setPerm(orig.perm);
}

Student::~Student() {
  // no other member variables were explicitly created on the heap besides name using 'new'
  delete[] this->name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // create a deep copy of the name
  delete[] this->name;

  if (right.name) {
    this->name = new char[strlen(right.name) + 1];
    strcpy(this->name, right.name);
  } else {
    this->name = nullptr;
  }

  // copy over the perm number
  this->perm = right.perm;


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss;
  oss << "[" << this->name
      << "," << this->perm
      << "]";
  return oss.str();
}

