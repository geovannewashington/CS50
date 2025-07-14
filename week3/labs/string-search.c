#include "cs50.h"
#include "stdio.h"
#include "string.h" 

#define ARR_TOTAL 6

// This is a <Linear Search> implementation.
int main(void)
{
    // An array of strings    
    char *strings[] = {"TposeProgrammer", "xTecna", "Fabio Caldas", "JGSM"};

    // Search for string
    string s = get_string("String:");
    for (int i = 0; i < ARR_TOTAL; i++) {
        if (strcmp(strings[i], s) == 0) {
            puts("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
