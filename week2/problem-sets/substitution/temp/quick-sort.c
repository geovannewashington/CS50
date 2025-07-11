#include <stdio.h>

void swap(int* a, int* b);

// Partition function
int partition(int arr[], int low, int high) {
    // Choose the pivot - the last element
    int pivot = arr[high];
    
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1; // initially -1 

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
        
    // TODO: understand better this part
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(int arr[], int low, int high) {
    // This verification assures that we don't run into a infinite loop
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // TODO: understand better this part
        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // the array size, in this case: 6
    
    // NOTE: we send the third argument as n - 1
    // since the array is zero-indexed

    quickSort(arr, 0, n - 1);

    // This is only for printing
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n'); 
    return 0;
}

