#include "tddFuncs.h"
#include <iostream>
using std::cout;
using std::endl;

bool areArraysEqual(int arr1[], int arr2[], int size) {
    // Compare elements one by one
    for (int i = 0; i < size; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;  // Return false if any element differs
        }
    }
    // If all elements match, return true
    return true;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }
}

void assertEquals(std::string testName,
      int expected[],
      int actual[],
      int n ) {
    if (areArraysEqual(expected, actual, n)) {
      cout << "PASSED: " << testName << endl;;
    } else {
      cout << "   FAILED: " << testName << endl;
      cout << "     Expected: ";
      printArray(expected, n);
      cout<<"\n";
      cout << "     Actual: " ; 
      printArray(actual, n);
      cout<<"\n";
    }     
}

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

