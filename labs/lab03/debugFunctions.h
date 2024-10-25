#ifndef DEBUGFUNCTIONS_H
#define DEBUGFUNCTIONS_H
#include <string>
// use echo "1232" >co MYFAVOWIREFILE
// to create a file named MYFAVOWIREFILE
// use cat MYFAVOWIREFILE to print the contents of it aka "1232"
void debugFunction1(std::string a);
void debugFunction2(int a);
void recursiveFunction(int a);
void watchPointTest(int idx, int value, int a);
void segFunction(int idx, int value);
void dataLost(int alloc,bool free);
int uninitialized(int idx);
void badFree();
void badAlloc();

extern int watchdata[1024];
extern int watchsomevalue;

#endif
