#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* Third version: convert case program (now using the ctype header file)*/
void convert_case(char string[]);

int main(int argc, char *agrv[])
{
    string rand_str = get_string("inser any text here ");
    convert_case(rand_str);

    printf("%s\n", rand_str);
    return 0;
}

void convert_case(char string[])
{
    for (int i = 0, length = strlen(string); i < length; i++) {
        // check if input is lowercase
        if (islower(string[i])) {
            string[i] = toupper(string[i]);
            continue;
        } 
        
        // check if input is uppercase
        if (isupper(string[i])) {
            string[i] = tolower(string[i]);
        } 
    }
}

