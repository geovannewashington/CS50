#include <cs50.h> 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//  TODO: implement my own sorting alogrithm with quicksort.
void cipher(char plaintext[], char key[], int key_length);
void quick_sort(char key[], int low, int high);
void copy(char to[], char from[]);
void swap(char* a, char* b);
int partition(char key[], int low, int high);

int main(int argc, char *argv[])
{
    // accepts a single command-line argument, the key. (26 character string)
    // the key should be case-insensitive (upper or lower shouldn't change behavior of program)
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // [FLAG]: assumes key valid by default.  
    bool is_key_valid = true;
    
    // if the key is invalid (not containing 26 chars, containing a char that is not an alphabetic)
    int key_length = strlen(argv[1]);
    
    if (key_length != 26) 
        is_key_valid = false;

    // TODO: change this logic
    for (int i = 0; i < key_length; i++) {
        // set flag as false and skips 
        if (!(isalpha(argv[1][i]))) 
            is_key_valid = false;
    }
    // verify that key contains each letter of alphabet at least once.
    char key_copy[key_length];
    copy(argv[1], key_copy); 
    quick_sort(key_copy, 0, key_length - 1); 
    for (int i = 0; i < key_length; i++) {
        if (key_copy[i] == key_copy[i + 1]) 
            is_key_valid = false;
    } 
    // if program is executed without any arguments or with more than just a single one
    // print an error message with printf and return 2 
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

void copy(char to[], char from[]) 
{
    int i = 0;
    while ((from[i] = to[i]) != '\0')
        i++;
}

void swap(char* a, char* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char key[], int low, int high)  
{
    int pivot = key[high]; // -> our pivot in this case is the last element
    int i = low - 1; // initially 'i' == -1;

    for (int j = low; j <= high - 1; j++) {
        if (key[j] < pivot) {
            i++;
            swap(&key[i], &key[j]);
        }
    }

    swap(&key[i + 1], &key[high]);
    return i + 1;
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

// TODO: finish this function, study: sorting algorithm
void quick_sort(char key[], int low, int high) {
    if (low < high) {
        int pi = partition(key, low, high);        

        quick_sort(key, low, pi - 1);
        quick_sort(key, pi + 1, high);
    }
}



