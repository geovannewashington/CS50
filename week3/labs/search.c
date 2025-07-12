#include "cs50.h"
#include "stdio.h"

#define ARR_TOTAL 7

// This is a <Linear Search> implementation.
int main(void)
{
    // An array of integers    
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Search for number
    int user_num = get_int("What number are you looking for? ");
    for (int i = 0; i < ARR_TOTAL; i++) {
        if (numbers[i] == user_num) {
            puts("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 0;
}
