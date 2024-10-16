#ifndef STUDENTROLL_H
#define STUDENTROLL_H 

#include <string>
#include "student.h"

class StudentRoll {

 public:
  StudentRoll();
  void insertAtTail(const Student &s);
  std::string toString() const;

  StudentRoll(const StudentRoll &orig);
  ~StudentRoll();
  StudentRoll & operator=(const StudentRoll &right);

 private:
  struct Node {
    Student *s;
    Node *next;
  };
  Node *head;
  Node *tail;
};


#endif
