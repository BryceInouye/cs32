#ifndef ARRAYFUNCS_H
#define ARRAYFUNCS_H

#include <string>

// convert integer to string
std::string intToString(int i);

// convert array to string
std::string arrayToString(int *a, int size);

// indexOfMax
//  a: an array of ints  n: how many ints in array
//  Return the index of largest value.  
//  If more than one element has largest value, 
//   break tie by returning the smallest index that
//   corresponds to an element with the largest value.
//  You may assume size >= 1
int indexOfMax(int *a, int n);

// indexOfMin
//  a: an array of ints  n: how many ints in array
//  Return the index of smallest value.  
//  If more than one element has smallest value, 
//    break tie by returning the smallest index that
//    corresponds to an element with the smallest value.
//  You may assume size >= 1
int indexOfMin(int *a, int n);

// swap
//  a: an array of ints.  n: how many ints in array
//  swap the values of a[i] and a[j]
void swap(int *a, int i, int j);

#endif // ARRAYFUNCS_H
