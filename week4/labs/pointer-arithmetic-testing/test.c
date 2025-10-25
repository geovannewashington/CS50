// test.c 

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF 10

int main()
{
    char *string = malloc(MAX_BUFF); // allocate 4 bytes to string
    char buff[MAX_BUFF];
    
    if (string == NULL) {
        fprintf(stderr, "Malloc failed to allocate memory.\n");
        return EXIT_FAILURE;
    }
    
    // scanf with field width
    printf("Enter some text: ");
    scanf("%9[^\n]s", buff);
    buff[MAX_BUFF - 1] = '\0'; // MAX_BUFF - 1 is the last index
    
    string = buff; // pointer strings gets assigned the address of buff
    free(string);
    printf("You entered the following: %s\n", string);
    
    
    return 0;
}

