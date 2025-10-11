// phonebook.c

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Open TXT file
    FILE *file = fopen("./foo/bar/asdajkdjkas/index.md", "a");
    
    // Checks if file exists
    if (file == NULL) {
        fprintf(stderr, "fopen failed, file might not exists...\n");
        return EXIT_FAILURE;
    }

    // Get name and number
    const char *name = get_string("Name: ");
    const char *number = get_string("Number: ");
    
    // Append to file 
    fprintf(file, "%s\n%s", name, number);

    // Close file 
    fclose(file);
    return 0;
}
