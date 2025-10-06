// memory.c
#include <stdio.h>
#include <stdlib.h> // So we can use malloc

int main(void)
{
    int *x = malloc(3 * sizeof(int)); // On my machine: 3 * 4 bytes == 12 bytes
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    
    // for (int i = 0; i < 3; i++) {
    //     printf("%c", x[i]);
    // }
    // putchar('\n');

    // free(x);
    return 0;
}
