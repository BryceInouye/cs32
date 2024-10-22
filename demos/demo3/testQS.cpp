#include "qs.h"
#include "tddFuncs.h"
#include<iostream>
#include<string>
#include<sstream>

int main() {
    std::cout << "Testing quickSort..." << std::endl;

    // test 1
    int arr1[]{4,10,8,7,6,5,3,12,14,2};
    int n1 = sizeof(arr1) / sizeof(int);
    quickSort(arr1, 0, n1-1);

    int arrExpected1[]{2,3,4,5,6,7,8,10,12,14};
    assertEquals("test1", arrExpected1, arr1 , n1);

    // test 2: Already Sorted Array
    int arr2[]{1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(int);
    quickSort(arr2, 0, n2-1);

    int arrExpected2[]{1, 2, 3, 4, 5};
    assertEquals("test2", arrExpected2, arr2 , n2);

    // test 3: empty array
    int arr3[]{};
    int n3 = sizeof(arr3) / sizeof(int);
    quickSort(arr3, 0, n3-1);

    int arrExpected3[]{};
    assertEquals("test3", arrExpected3, arr3 , n3);

    // test 4: single element array
    int arr4[]{5};
    int n4 = sizeof(arr4) / sizeof(int);
    quickSort(arr4, 0, n4-1);

    int arrExpected4[]{5};
    assertEquals("test4", arrExpected4, arr4 , n4);

    // test 4: array with duplicates
    int arr5[]{4, 2, 4, 3, 1, 2};
    int n5 = sizeof(arr5) / sizeof(int);
    quickSort(arr5, 0, n5-1);

    int arrExpected5[]{1, 2, 2, 3, 4, 4};
    assertEquals("test5", arrExpected5, arr5 , n5);

    return 0;
}