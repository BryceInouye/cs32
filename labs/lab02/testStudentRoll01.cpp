#include "student.h"
#include "studentRoll.h"

#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  Student s("Phill Conrad",1234567);

  ASSERT_EQUALS("Phill Conrad",s.getName());
  ASSERT_EQUALS(1234567,s.getPerm());

  StudentRoll sr;
  ASSERT_EQUALS("[]",sr.toString());

  sr.insertAtTail(s);

  ASSERT_EQUALS("[[Phill Conrad,1234567]]",sr.toString());

  s.setName("Chris Gaucho");
  s.setPerm(2222222);
  ASSERT_EQUALS("Chris Gaucho",s.getName());

  sr.insertAtTail(s);

  ASSERT_EQUALS("[[Phill Conrad,1234567],[Chris Gaucho,2222222]]",sr.toString());

  return 0;
}

