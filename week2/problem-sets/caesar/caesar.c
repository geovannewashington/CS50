#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int convert_to_int(char *char_arr);

int main(int argc, char *argv[])
{
    int is_arg_valid = 1;
    
    for (int i = 0; i < argc; i++) {
        if (!isdigit(argv[1][i]))
            is_arg_valid = 0;
    }
    
    if (argc == 1 || argc > 2 || is_arg_valid == 0) {
        printf("Usage: ./caeser key\n");
        return 1;
    } 
    
    int k = convert_to_int(argv[1]);
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
