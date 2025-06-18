#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int convert_str_int(char str[]);

int main(int argc, char *argv[])
{
    // Assumes argv[1], which is the key, is valid by default 
    int is_arg_valid = 1;

    // where k is key
    // Since argv[1] must be a string we need to convert it into an integer.
    int k = convert_str_int(argv[1]);

    for (int i = 0, k_len = strlen(argv[1]); i < k_len; i++) 
        if (!isdigit(argv[1][i]))
            is_arg_valid = 0; // -> if it's not a digit then it's not valid
   
    if (argc == 1 || argc > 2) {
        printf("Number of arguments passed is to little or too much");
        return 1;
    } 

    //  TODO: This needs to be inside a loop tho.
    if (is_arg_valid == 0 || k < 0) {
        printf("Usage: ./caeser key\n");
    } 
   
    return 0;
}

// I could use the atoi (ascii to integer) function for this job
// but I thought it would be nice to manually implement this function.
int convert_str_int(char str[])
{
    int resolution = 0;

    // the key cannot be below zero.
    if (str[0] == '-') {
        resolution = -1;
        return resolution;
    } 
    
    for (int i = 0; str[i] != '\0'; i++) {
        // isdigit from the ctype library once again.
        // same as doing: str[i] >= '0' && str[i] <= 9
        if (isdigit(str[i])) {
            resolution = resolution * 10 + (str[i] - '0');            
            // Note that in C subctracting by '0' will convert 
            // a string number into a real digit number.
        } else {
            // the key cannot contain anything that is not a digit.
            resolution = -1;
            return resolution;
        } 
    }
    return resolution;
}









