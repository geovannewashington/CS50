#include <stdio.h>
#include <stdlib.h>

// Selection Sort implementation

void selection_sort(int *arr);

int main(void)
{
    int numbers[] = {1, 2, 0, 5, 4, 7};
    selection_sort(&numbers);
    exit(EXIT_SUCCESS);
}

void selection_sort(int arr[])
{
    // calculate arr lenght
    int n = sizeof(arr) / sizeof(arr[0]);
   
    int min_index; // smaller value seen so far

    // iterate over the array
    for (int i = 0; i < n - 1; i++) {
        min_index = arr[i];         

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i])
                min_index = j;
        }

        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
