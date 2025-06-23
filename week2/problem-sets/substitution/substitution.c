#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // accepts a single command-line argument, the key. (26 character string)
    // the key should be case-insensitive (upper or lower shouldn't change behavior of program)
    
    // [FLAG]: assumes key valid by default.  
    int is_key_valid = 1;
    
    // if the key is invalid (not containing 26 chars, containing a char that is not an alphabetic)
    int key_length = strlen(argv[0]);
    
    if (key_length != 26) 
        is_key_valid = 0;

    for (int i = 0; i < key_length; i++)
        if (!(isalpha(argv[0][i]))) 
            is_key_valid = 0;
    
    // TODO: THIS 👉 // not containing each letter once
      
    // if program is executed without any arguments or with more than just a single one
    // print an error message with printf and return 1 
    if (argc != 2 || !is_key_valid) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // printf an error message and return 1
    
    // print 'plaintext: ' without a newline a prompt the user for a string using get_string
    
    // output: ciphertext: 
    // non-alphabetical characters should remain unchanged
    // after outputing ciphertext, the program should print a newline.   
    // NOTE: the output must preserve case.
    return 0;
}
