#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHA_LEN 26
#define FIRST_CAPITAL 65
#define FIRST_LOWER 97

int convert_str_int(char str[]);
void encrypt(char plaintext[], int key);

//  NOTE: to remember: the result of the equation: c_1 = (p_1 + k) % 26 is the position of
// the cipher character at the alphabet starting from zero, that is, a = 0, b = 1 and so on...
// also there is no need to use hash maps altought it could be done using it.

//  NOTE: for each p_i it's value in the alphabet == it's ascii value - 65 (for capital) or 
//  - 97 for lowercase

typedef struct {
    char letter;   
    int position;
} alpha_pos; 

alpha_pos lower_chars[ALPHA_LEN] = {
    {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3},   
}; 

int main(int argc, char *argv[])
{
    // Makes sure program was run with just one command-line argument.
    if (argc == 1 || argc > 2) {
        printf("Number of arguments passed is to little or too much");
        return 1;
    } 
    
    // Makes sure every character in argv[1] is a digit.

    int is_arg_valid = 1; // Assumes argv[1], which is the key, is valid by default 
    for (int i = 0, k_len = strlen(argv[1]); i < k_len; i++) 
        if (!isdigit(argv[1][i]))
            is_arg_valid = 0; // -> if it's not a digit then it's not valid
    // where k is key
    // Since argv[1] must be a string we need to convert it into an integer.
   
    // Convert argv[1] from a 'string' to an 'int'
    int k = convert_str_int(argv[1]);
   
    if (is_arg_valid == 0 || k < 0) {
        printf("Usage: ./caeser key\n");
        return 1;
    } 

    // Prompt user for plaintext. 
    string plaintext = get_string("plaintext  ");  

    encrypt(plaintext, k);
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

void encrypt(char plaintext[], int key) 
{
    char ciphertext[strlen(plaintext)];
    // for each character of plaintext:
        // rotate 'key' times if it's a letter;
        // if it's not a letter remain untouched

    //  NOTE: print: printf("%s %s\n", "ciphertext: ", ciphertext);
}







