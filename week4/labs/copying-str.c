// copying-str.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -- macros
#define KIB 1024

char mrtypo7_toupper(char c)
{
    if (c >= 'a' && c <= 'z') { // character is lowercase
        return c - ('a' - 'A');
    }
    return c; // not lowercase, not change needed.
}

int main(void)
{
    char buff[KIB];
    char *str = NULL;

    fgets(buff, KIB, stdin); 
    buff[strcspn(buff, "\n")] = 0;
    str = buff; 

    char *str_cpy = malloc(KIB);
    if (!str_cpy) {
        fprintf(stderr, "malloc failed");
        return EXIT_FAILURE;
    }
    strncpy(str_cpy, str, (size_t)KIB);
    
    // Brackets notation is doing exactly this
    *(str_cpy + 0) = mrtypo7_toupper(*(str_cpy + 0));
    
    puts("Output:");
    printf("%s\n", str);     // original string
    printf("%s\n", str_cpy); // capitalized string
    free(str_cpy);
    return EXIT_SUCCESS;
}
