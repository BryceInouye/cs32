#include "student.h"

#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  const char * const name0="Phill Conrad";
  const char * const name1="Chris Gaucho";
  const char * const name2="Adam Twelve";

  Student s0(name0,1000000);
  Student s1(s0);
  s1.setName(name1); s1.setPerm(1111111);
  ASSERT_EQUALS(name1,s1.getName());   
  ASSERT_EQUALS(1111111,s1.getPerm());
  
  Student s2(s0);
  s2 = s1;
  ASSERT_EQUALS(s1.getName(),s2.getName());   
  ASSERT_EQUALS(s1.getPerm(),s2.getPerm());

  s2.setName(name2); s2.setPerm(2222222);

  ASSERT_EQUALS(name1,s1.getName());   
  ASSERT_EQUALS(1111111,s1.getPerm());
  ASSERT_EQUALS(name2,s2.getName());   
  ASSERT_EQUALS(2222222,s2.getPerm());

  Student s3=s2;

  ASSERT_EQUALS(s2.getName(),s3.getName());
  ASSERT_EQUALS(s2.getPerm(),s3.getPerm());

  return 0;
}
