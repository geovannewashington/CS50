// Implements a phone book without structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Arrays of strings.
    char *names[] = {"albq", "nych", "felipog"};
    char *numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};
    
    int quant_numbers = sizeof(names) / sizeof(names[0]); // 3;
    // Search for name
    char *name = get_string("Name: ");
    for (int i = 0; i < quant_numbers; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 0;
}
