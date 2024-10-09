#include "Student.h"
#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Testing class Student..." << endl;

  Student s1(1234567,"Smith","Malory Logan");
  ASSERT_EQUALS(1234567,s1.getPerm());

  return 0;
}
