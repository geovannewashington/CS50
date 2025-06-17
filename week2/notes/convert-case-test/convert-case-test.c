#include <cs50.h>
#include <stdio.h>
#include <string.h>

/* Second version: convert case program */
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
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
            continue;
        } 
        
        // check if input is uppercase
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        } 
    }
}

