#ifndef TDDFUNCS_H
#define TDDFUNCS_H

#include <string>

void assertEquals(std::string testName,
      int expected[],
      int actual[],
      int n );

void assertEquals(std::string testName,
		  std::string expected, 
		  std::string actual);

void assertEquals(std::string testName,
		  int expected, 
		  int actual);		  

void assertTrue(std::string testName, bool expression);

#endif // TDDFUNCS_H
