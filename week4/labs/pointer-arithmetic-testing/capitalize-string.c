// Capitalizes a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");
    
    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1); // Since strlen doesn't count the null charater we add 1 here...
    
    if (t == NULL) {
        // malloc failed to allocate memory
        fprintf(stderr, "something went wrong :(\n)");
        return EXIT_FAILURE;
    }
    
    // Copy string into memory, including '\0'
    // for (int i = 0, n = strlen(s); i <= n; i++) { // Note that we use <= so we also copy the null character...
    //     t[i] = s[i];
    // }
    strcpy(t, s);
    
    // Capitalize copy
    if (strlen(t) > 0) { // string t exists
        t[0] = toupper(t[0]); // Since t is now a trully copy, only this string will be capitalized
    }

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    
    // Free memory
    free(t);
    return 0;
}
