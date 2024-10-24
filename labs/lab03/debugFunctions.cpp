#include "debugFunctions.h"
#include <iostream>

void debugFunction1(std::string a)
{
//  std::cout << a << std::endl;
}



void debugFunction2(int a)
{
  recursiveFunction(a);
}


int watchdata[1024] = {0};
int watchsomevalue  = 0;


void segFunction(int idx, int value)
{
  int *array[1024] = {0};

  *array[idx] = value;
}

void dataLost(int size, bool free)
{
  int *ptr = new int[size];

  if(free)
    delete [] ptr;
}

int uninitialized(int idx)
{
  int data[1024];
  if(data[idx])
   return 1; 
  return 0;
}

void badFree()
{
  int *array = new int[128];
  free(array);
}

void badAlloc()
{
  // int *array = (int *) malloc(-3);

}
