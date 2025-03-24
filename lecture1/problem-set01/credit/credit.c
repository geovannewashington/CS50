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
    int even_arr[20];
    int odd_arr[20];
    printf("INPUT LENGTH: %d\n", input_length);

    for (int i = 0; i < input_length; ++i) {
        if (i % 2 == 0) {
            even_arr[i] = (input[i] - '0') * 2;      
        } else {
            odd_arr[i] = (input[i] - '0');      
        }
    }
     
    for (int i = 0; i < 16; i++) {
        if (i % 2 == 0) 
            printf("even: %d\n", even_arr[i]);
        else 
            printf("odd: %d\n", odd_arr[i]);

    }

    // we can first call this function 
    // and then use it's boolean return value on discover_company
    return is_legit;
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

