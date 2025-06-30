#include <cs50.h> 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cipher(char plaintext[], char key[], int key_length);

int main(int argc, char *argv[])
{
    // accepts a single command-line argument, the key. (26 character string)
    // the key should be case-insensitive (upper or lower shouldn't change behavior of program)
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // [FLAG]: assumes key valid by default.  
    int is_key_valid = 1;
    
    // if the key is invalid (not containing 26 chars, containing a char that is not an alphabetic)
    int key_length = strlen(argv[1]);
    
    if (key_length != 26) 
        is_key_valid = 0;

    // TODO: change this logic
    int j = 0;
    for (int i = 0; i < key_length; i++) {
        // set flag as false and skips 
        if (!(isalpha(argv[1][i]))) {
            is_key_valid = 0;
            continue;
        }
        // verify that key contains each letter of alphabet at least once.
        j += tolower(argv[1][i]);
    }
    if (j != 2847)
        is_key_valid = 0;
    
    // if program is executed without any arguments or with more than just a single one
    // print an error message with printf and return 1 
    if (!is_key_valid) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // print 'plaintext: ' without a newline a prompt the user for a string using get_string
    string plaintext = get_string("plaintext: ");
    
    cipher(plaintext, argv[1], key_length);

    // output: ciphertext: 
    // non-alphabetical characters should remain unchanged
    // after outputing ciphertext, the program should print a newline.   
    // NOTE: the output must preserve case.
    return 0;
}

void cipher(char plaintext[], char key[], int key_length) 
{
    int plain_length = strlen(plaintext) + 1; 
    char cipher[plain_length];

    int i;
    for (i = 0; i < plain_length; i++) { 
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                // printf("%c\n", toupper(key[plaintext[i] - 'A']));
                cipher[i] = toupper(key[plaintext[i] - 'A']);
            } else {
                // printf("%c\n", tolower(key[plaintext[i] - 'a']));
                cipher[i] = tolower(key[plaintext[i] - 'a']);
            }
        } else {
            // change nothing.
            cipher[i] = plaintext[i];
        }
    }
    cipher[i + 1] = '\0';
//    printf("ciphertext: %c\n", cipher[0]); 
    printf("ciphertext: %s\n", cipher); 
}





