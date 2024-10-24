#include "student.h"

#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  Student s("Phill Conrad",1234567);

  ASSERT_EQUALS("Phill Conrad",s.getName());
  ASSERT_EQUALS(1234567,s.getPerm());
  ASSERT_EQUALS("[Phill Conrad,1234567]",s.toString());

  return 0;
}
