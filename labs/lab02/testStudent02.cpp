#include "student.h"

#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  const char * const origName="Phill Conrad";

  Student s(origName,1234567);

  ASSERT_EQUALS(origName,s.getName());
  ASSERT_EQUALS(1234567,s.getPerm());

  const char * const name1="Chris Gaucho";
  const char * const name2="Adam Twelve";
  const char * const name3="Betty Boop";

  Student s1(s);
  Student s2(s);
  Student s3(s);

  s.setName(name1);
  ASSERT_EQUALS(name1,s.getName());

  s2.setName(name2);
  ASSERT_EQUALS(name2,s2.getName());

  s3.setName(name3);
  ASSERT_EQUALS(name3,s3.getName());

  ASSERT_EQUALS(origName,s1.getName());

  return 0;
}
