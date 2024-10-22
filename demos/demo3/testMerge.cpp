#include "ms.h"
#include "tddFuncs.h"
#include<iostream>
#include<string>
#include<sstream>

int main() {
    std::cout << "Testing merge..." << std::endl;

    // test 1
    int arr1[]{1, 3, 5, 2, 4, 6};
    int n1 = sizeof(arr1) / sizeof(int);
    merge(arr1, 0, 2, 5);

    int arrExpected1[]{1, 2, 3, 4, 5, 6};
    assertEquals("test1", arrExpected1, arr1 , n1);

    // test 2: One Half Larger than the Other
    int arr2[]{1, 4, 7, 2, 5};
    int n2 = sizeof(arr2) / sizeof(int);
    merge(arr2, 0, 2, 4);

    int arrExpected2[]{1, 2, 4, 5, 7};
    assertEquals("test2", arrExpected2, arr2 , n2);

    // test 3: Arrays with Duplicate Values
    int arr3[]{1, 3, 3, 2, 2, 4};
    int n3 = sizeof(arr3) / sizeof(int);
    merge(arr3, 0, 2, 4);

    int arrExpected3[]{1, 2, 2, 3, 3, 4};
    assertEquals("test3", arrExpected3, arr3 , n3);

    // test 4: Merge a Portion of the Array
    int arr4[]{5, 8, 3, 7, 1, 9, 4};
    int n4 = sizeof(arr4) / sizeof(int);
    merge(arr4, 2, 3, 5);

    int arrExpected4[]{5, 8, 1, 3, 7, 9, 4};
    assertEquals("test4", arrExpected4, arr4 , n4);

    // test 5: Merge the First Half of the Array
    int arr5[]{2, 10, 6, 8, 1, 4};
    int n5 = sizeof(arr5) / sizeof(int);
    merge(arr5, 0, 1, 3);

    int arrExpected5[]{2, 6, 8, 10, 1, 4};
    assertEquals("test5", arrExpected5, arr5 , n5);

    return 0;
}