// Implements a phone book without structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char *name;
    char *number;
} person;

int main(int argc, char *argv[])
{
    
    // Arrays of strings.
    // char *names[] = {"albq", "nych", "felipog"};
    // char *numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};
    person people[3];
    
    people[0].name = "albq";
    people[0].number = "+1-617-495-1000";

    people[1].name = "nych";
    people[1].number = "+1-617-495-1000";
    
    people[2].name = "felipog";
    people[2].number = "+1-949-468-2750";
    
    // Search for name
    char *name = get_string("Name: ");
    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 0;
}
