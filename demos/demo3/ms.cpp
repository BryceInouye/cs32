/**
 * Function to merge two halves of the array
 * arr: input array
 * assume two sorted halves: [left, mid] and (mid, right]
 */

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;     // Size of the right half

    // Create temporary arrays to hold the two halves
    int L[n1], R[n2];

    // Copy data into temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the two halves back into arr[]
    // initialize i, j, k
    int i = 0, j = 0, k = left;
    // compare and copy
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
            k++;
    }

    // Copy any remaining elements of L[] (if any)

    // while (i < n1) {
    //     arr[k] = L[i];
    //     i++, k++;
    // }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[] (if any)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Recursive Merge Sort function
 */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;  
        // note: (left + right) / 2 might lead to integer overflow for large integers

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

