#include <string>
#include "studentRoll.h"
#include <sstream>
#include <iostream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* student = new Node;
  student->s = new Student(s);
  student->next = nullptr;

  if (head == nullptr) {
    head = student;
    tail = student;
  } else {
    tail->next = student;
    tail = student;
  }
}

std::string StudentRoll::toString() const {
  // todo: iterate through linked list, printing each student 
  std::ostringstream oss;
  oss << "[";
  Node* temp = head;
  while (temp != tail) {
    oss << temp->s->toString() << ",";
    temp = temp->next;
  }
  if (temp != nullptr) oss << temp->s->toString();
  oss << "]";
  return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = nullptr;
  if (orig.head == nullptr) {
    return;
  }
  Node* temp = orig.head;
  while (temp != nullptr) {
    this->insertAtTail(*(temp->s));
    temp = temp->next;
  }

}

StudentRoll::~StudentRoll() {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp->s;
    delete temp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  // first delete every student in the current student roll
  this->~StudentRoll();
  // then create a new student for each student in the passed student roll
  Node* temp = right.head;
  while (temp != nullptr) {
    this->insertAtTail(*(temp->s));
    temp = temp->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





