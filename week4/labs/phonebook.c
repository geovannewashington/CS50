// #include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Macros
#define BUFSIZE 1024 // 1KiB

// Our own custom get_string function
char *get_string(const char *prompt)
{
    int bufsize = BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "get_string: allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    printf("%s", prompt);
    while (1) {
        // Read a single character
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } 
        buffer[position++] = c;

        if (position >= bufsize - 1) { // input didn't end yet and bufsize needs to increase
            bufsize += BUFSIZE;
            char *tmp = realloc(buffer, bufsize);
            if (!tmp) {
                fprintf(stderr, "get_string: allocation error\n");
                free(buffer);
                exit(EXIT_FAILURE);
            }
            buffer = tmp;
        }
    }
}

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    // fopen opens the file "phonebook.csv", the second argument specifies in which 'mode' to open. 
    // a stands for append, that is, open to append (writing at the end of file), getting created if 
    // it doesn't exit. 
    // It returns a file pointer, otherwise NULL is returned and errno is set to indicate the error. 
    
    // Prompt user for a string
    char *name = get_string("name: ");
    char *number = get_string("number: ");
    
    fprintf(file, "%s, %s\n", name, number);
    fclose(file);
    return EXIT_SUCCESS;
}

