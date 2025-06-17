#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//  TODO: change this char array pointer to string array since we're importing cs50.h
int convert_to_int(char *char_arr);

int main(int argc, char *argv[])
{
    // Assumes argv[1], which is the key, is valid by default 
    int is_arg_valid = 1;

    // where k is key
    int k = convert_to_int(argv[1]);

    for (int i = 0, k_len = strlen(argv[1]); i < k_len; i++) 
        if (!isdigit(argv[1][i]))
            is_arg_valid = 0; // -> if it's not a digit then it's not valid
    
    if (argc == 1 || argc > 2 || is_arg_valid == 0) {
        printf("Usage: ./caeser key\n");
        return 1;
    } 
    
    printf("%d\n", k);
    return 0;
}

int convert_to_int(char *char_arr)
{
    int result = 0, factor =  pow(10, strlen(char_arr - 1)); 
    printf("%d\n", factor);
    for (int i = 0, len = strlen(char_arr); i < len; i++) {
        // printf("%d\n", result);
        result += (char_arr[i] - '0') * factor;          
        factor /= 10;
    }
    return result;
}
