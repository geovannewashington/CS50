#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "tpose"; // len => 5
    // for (int i = 0, len = strlen(str); i < len; i++) 
    //     printf("%c\n", *(str + i)); // Pointer Arithmetic
    // Expected Output:
    // t 
    // p 
    // o 
    // s 
    // e 
    
    for (int i = 0, len = strlen(str); i < len; i++) 
        printf("%p\n", (str + i)); // The memory addresses
    return 0;
}
