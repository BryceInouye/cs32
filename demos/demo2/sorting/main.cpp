#include "sorting.h"
#include<string>
#include<iostream>
void printArray(std::string msg, int a[], int n)  {
    std::cout << msg <<" ";
    for(int i=0; i<n; i++) {
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}

int main() {
    int arr[]{7,3,8,1,2};
    int n = 5;

    printArray("before\t", arr, n);

    selectionSort(arr, n);

    printArray("after\t", arr, n);
    return 0;
}