// creates a sorted list from the right to the left side
// swap every pair of values until making it to the end
void bubbleSort(int a[], int n) {
    for(int i=n-1; i>0; i--) {
        for(int j=0; j<i; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
// create a sorted list from the left to the right side
// acts as a window that increases in size
void insertionSort(int a[], int n) {
    for(int i=1; i<n; i++) {
        int elemToInsert = a[i];

        // insert a[i] in correct position in the left side (0 to i-1)
        int j=i-1;
        while(j>=0 && a[j] > elemToInsert) {
            a[j+1] = a[j]; // push a[j] to the front (i.e., to j+1) to make space
            j--;
        }
        a[j+1] = elemToInsert;
    }
}

// create a sorted list from the left to the right side
// by swapping the element at i with the minimum element of the list
void selectionSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int indexOfNextSmallest = i;
        for(int j = i;  j < n; j++) {
            if( a[j] > a[indexOfNextSmallest]) {
                indexOfNextSmallest = j;
            }
        }
        int temp = a[i];
        a[i] = a[indexOfNextSmallest];
        a[indexOfNextSmallest] = temp;
    }
}