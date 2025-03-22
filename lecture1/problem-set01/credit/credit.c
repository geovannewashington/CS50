#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
/* CS50: The credit problem */

const int AMEX[] = {34, 37}; // AMEX -> American Express
const int MASTER[] = {51, 52, 53, 54, 55};
const int VISA = 4; //probably won't need this

void get_first_two_nums(int *digits, float *arr);
char* discover_company(int *digits);
bool is_valid(char *input, int input_length); // -> Luhn's Algorithm
void convert_input_arr(long int input, char *credit_Arr);
int get_str_length(char *input);

int main(void)
{
    long int testing = get_long("Number: "); // -> I need somehow turn this into an array
    int digits[2];
    char credit_Arr[20]; 
    convert_input_arr(testing, credit_Arr);
    int str_length = get_str_length(credit_Arr); 
    //printf("Quantity of numbers inserted: %d\n", str_length);

    is_valid(credit_Arr, str_length);
    return 0;
}

bool is_valid(char *input, int input_length)
{
    bool is_legit = false;
    int sum_arr[20];
    int j = 0;
    //printf("%d\n", input[input_length - 2] - '0'); 
    // this is printing 49 when it should be 1
    // becuase it's actually a character

    for (int i = 2; i <= input_length; i += 2) {
        // NOTE: we are not getting the first number input[0]
        // printf("TEST: %d\n", (input[input_length - i] - '0') * 2);
        sum_arr[j] += (input[input_length - i] - '0') * 2;
        j++;
        // printf("%d\n", sum);
    }
    
    for (int i = 0; i < 16; i++)
        printf("%d", sum_arr[i]);

    //printf("%d\n", sum); 
    // we can first call this function 
    // and then use it's boolean return value on discover_company
    //return is_legit;
}
//TODO: credit number NEEDS to pass both validations, that is, function: is_valid AND discover_company

char* discover_company(int *digits)
{
    // we need to verify if the array digits[2] is equal to one of the elements on the global arrays
    int first_two_digits = (digits[0] * 10) + digits[1];

    // 1.400360000000001i for AMEX -> American Express
    int amex_length = (sizeof AMEX / AMEX[0]);
    for (int i = 0; i < amex_length; i++) {
        if (first_two_digits == AMEX[i])
            return "AMEX"; 
    } 

    // 2. for MASTERCARD int master_length = (sizeof MASTER / MASTER[0]); for (int i = 0; i < master_length; i++) {
    int master_length = (sizeof MASTER / MASTER[0]);
    for (int i = 0; i < master_length; i++) {
        if (first_two_digits == MASTER[i])
            return "MASTERCARD"; 
    }

    // 3. for VISA
    if (digits[0] == VISA)
        return "VISA"; 

    // 4. what if it's none of those three? do I simply return INVALID\n ?
    return "INVALID"; 
}

void get_first_two_nums(int *digits, float *arr)
{
    for (int i = 0; i < 2; ++i)
        digits[i] = arr[i];
}

void convert_input_arr(long int input, char *credit_Arr)
{
    sprintf(credit_Arr, "%ld", input);
}

int get_str_length(char *input) 
{
    int length = 0;
    
    while (input[length] != '\0') {
        length++;
    }
    return length;
}

