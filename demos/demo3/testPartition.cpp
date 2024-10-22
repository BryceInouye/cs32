#include "qs.h"
#include "tddFuncs.h"
#include<iostream>
#include<string>
#include<sstream>

int main() {
    std::cout << "Testing quickSort..." << std::endl;

    // test 1
    int arr1[]{4,10,8,7,6,5,3,12,14,2};
    int n = sizeof(arr1) / sizeof(int);
    partition(arr1, 0, n-1);

    int arrExpected1[]{2,10,8,7,6,5,3,12,14,4};
    assertEquals("test1", arrExpected1, arr1 , n);

    // test 2
    int arr2[]{2,10,8,7,6,5,3,12,14,4};
    partition(arr2, 1, n-1);

    int arrExpected2[]{2,3,4,7,6,5,10,12,14,8};
    assertEquals("test2", arrExpected2, arr2, n);

    // test 3
    int arr3[]{2,3,4,7,6,5,10,12,14,8};
    partition(arr3, 3, n-1);

    int arrExpected3[]{2,3,4,7,6,5,8,12,14,10};
    assertEquals("test3", arrExpected3, arr3, n);

    // test 4
    int arr4[]{2,3,4,7,6,5,8,12,14,10};
    partition(arr4, 7, n-1);

    int arrExpected4[]{2,3,4,7,6,5,8,10,14,12};
    assertEquals("test4", arrExpected4, arr4, n);

    return 0;
}