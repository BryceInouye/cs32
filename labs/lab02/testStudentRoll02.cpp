#include "student.h"
#include "studentRoll.h"

#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  const char * const name1="One One";
  const char * const name2="Two Two";
  const char * const name3="Tre Tre";
  
  Student s1(name1,1111111);
  Student s2(name2,2222222);
  Student s3(name3,3333333);


  StudentRoll sr0;
  StudentRoll sr1(sr0);
  sr1.insertAtTail(s1);
  StudentRoll sr2(sr1);
  sr2.insertAtTail(s2);
  StudentRoll sr3;
  sr3.insertAtTail(s1);
  sr3 = sr2;
  sr3.insertAtTail(s3);

  ASSERT_EQUALS("[]",sr0.toString()); 
  ASSERT_EQUALS("[[One One,1111111]]",sr1.toString()); 
  ASSERT_EQUALS("[[One One,1111111],[Two Two,2222222]]",sr2.toString());
  ASSERT_EQUALS("[[One One,1111111],[Two Two,2222222],[Tre Tre,3333333]]",sr3.toString()); 

  return 0;
}

