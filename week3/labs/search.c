#include "cs50.h"
#include "stdio.h"
#include <stdbool.h>

// #define ARR_TOTAL 7

// This is a <Linear Search> implementation.
int main(void)
{
    // An array of integers    
    // bool flag = false;
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int num_size = sizeof(numbers) / sizeof(numbers[0]);
    // Search for number
    int user_num = get_int("What number are you looking for? ");
    for (int i = 0; i < num_size; i++) {
        if (numbers[i] == user_num) {
            puts("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 0;
}
