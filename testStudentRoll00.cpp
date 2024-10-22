#include "student.h"
#include "studentRoll.h"

#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  StudentRoll sr;
  ASSERT_EQUALS("[]",sr.toString());

  return 0;
}
