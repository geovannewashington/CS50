#include <cs50.h>
#include <stdio.h>

/* CS50: The credit problem */

const int AMEX[] = {34, 37};
const int MASTER[] = {51, 52, 53, 54, 55};
const int VISA = 4; //probably won't need this

void get_first_two_nums(int *digits, float *arr);
void check_company();
void is_valid(); // -> Luhn's Algorithm
void convert_input_arr(long int input, char *credit_Arr);
int get_str_length(char *input);

int main(void)
{
    long int testing = get_long("Number: "); // -> I need somehow turn this into an array
    int digits[2];
    char credit_Arr[20]; 
    convert_input_arr(testing, credit_Arr);
    int str_length = get_str_length(credit_Arr); 
    printf("Quantity of numbers inserted: %d\n", str_length);

    for (int i = 0; i < str_length; i++)
        printf("%c", credit_Arr[i]);
    // get_first_two_nums(digits, credit);
    
    for (int i = 0; i < 2; ++i) 
        // printf("%d", digits[i]);

    return 0;
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

