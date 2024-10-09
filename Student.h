#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {

 public:
  Student(int perm, 
	  std::string lastName, 
	  std::string firstAndMiddleNames);

  int getPerm() const;

  std::string getLastName() const;
  std::string getFirstAndMiddleNames() const;
  std::string getFullName() const;
  std::string toString() const; // e.g. [12345,Smith,Malory Logan]

 private:
  int perm;
  std::string lastName;
  std::string firstAndMiddleNames;
};

#endif // STUDENT_H
