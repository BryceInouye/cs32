#include "tddFuncs.h"
#include <iostream>
using std::cout;
using std::endl;

void assertEquals(std::string testName,
      std::string expected, 
		  std::string actual) {
  if (expected==actual) {
    cout << "PASSED: " << testName << endl;;
  } else {
    cout << "   FAILED: " << testName << endl 
	 << "     Expected: " << expected << " Actual: " << actual << endl; 
  }
}

void assertEquals(std::string testName,
      int expected, 
		  int actual) {
  if (expected==actual) {
    cout << "PASSED: " << testName << endl;;
  } else {
    cout << "   FAILED: " << testName << endl 
	 << "     Expected: " << expected << " Actual: " << actual << endl; 
  }
}

void assertTrue(std::string testName,
      bool expression) {
  if (expression) {
    cout << "PASSED: " << testName << endl;;
  } else {
    cout << "   FAILED: " << testName << endl 
	 << "     Expected true, but was false " << endl;
  }
}

