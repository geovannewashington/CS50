#include <stdio.h>
#include <stdlib.h>

// --
// 0. Function Prototypes
// --
int simple_printf(const char *str);

int main(void) 
{
    // --
    // 1. Those two are equivalent, the first version is shorter shorter, the compiler automatically
    // does the job.
    // --
    const char *my_string = "hello";
    const char my_string2[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    
    // --
    // 2. printing stuff in the screen
    // Observation: the name of an array in C, automatically decays to a pointer of its first element
    // --
    printf("%s\n", my_string);
    printf("%s\n", my_string2);

    // --
    // 3. Using our simple printf function implementation
    // --
    
    int return_counter = simple_printf("tpose\n"); // return_counter should be 6
    printf("Number of characters succesfully printed by our simple printf function: %i\n"
            , return_counter); 
    return EXIT_SUCCESS;
}

// Should return the amount of succesfully printed characters.
// We can levare pointer arithmetic 
int simple_printf(const char *str)
{
    if (str = NULL) {
        fprintf(stderr, "Invalid string\n");
        return -1; // We could return any non-zero integer value or use exit(-1) to finish the program
                   // through this function.
    }

    int i = 0;  
    while (*(str + i) != '\0') { putchar(*(str + i)); i++; };
    return i;
}
