#include "Student.h"
#include <iostream>
#include "tddFuncs.h"

int main() {
  std::cout << "Testing class Student..." << std::endl;

  Student s1(1234567,"Smith","Malory Logan");
  ASSERT_EQUALS("Smith",s1.getLastName());
  ASSERT_EQUALS("Malory Logan",s1.getFirstAndMiddleNames());

  return 0;
}
