#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/* CS50: The credit problem */

const int AMEX[] = {34, 37}; // AMEX -> American Express
const int MASTER[] = {22, 51, 52, 53, 54, 55};
const int VISA = 4;

void get_first_two_nums(int *first_two_digits_arr, char *arr);
char *discover_company(int *first_two_digits_arr, char *card_number_arr);
bool is_valid(char *card_number_arr); // -> Luhn's Algorithm
void convert_input_arr(long input, char *card_number_arr);

int main(void)
{
    int first_two_digits_arr[2] = {0};
    char card_number_arr[20] = {0};
    
    long card_number = get_long("Number: "); 
    convert_input_arr(card_number, card_number_arr);
    get_first_two_nums(first_two_digits_arr, card_number_arr);

    printf("%s", discover_company(first_two_digits_arr, card_number_arr));
    return 0;
}

bool is_valid(char *card_number_arr)
{
    int sum = 0, length = strlen(card_number_arr);
    bool double_digit = false; 

    for (int i = length - 1; i >= 0; i--) {
        int digit = card_number_arr[i] - '0';

        if (double_digit) {
            digit *= 2;
            
            if (digit > 9) digit -= 9;
        }

        sum += digit;
        double_digit = !double_digit;
    }
    return sum % 10 == 0;
}

char *discover_company(int *first_two_digits_arr, char *card_number_arr)
{
    int input_length = strlen(card_number_arr);
    int first_two_digits = (first_two_digits_arr[0] * 10) + first_two_digits_arr[1];
    
    if (!is_valid(card_number_arr)) return "INVALID\n";
    
    // 1. for AMEX -> American Express
    for (int i = 0; i < sizeof(AMEX) / sizeof(AMEX[0]); i++)
        if (first_two_digits == AMEX[i] && input_length == 15) return "AMEX\n";

    // 2. for MASTERCARD int master_length = (sizeof MASTER / MASTER[0]);
    for (int i = 0; i < sizeof(MASTER) / sizeof(MASTER[0]); i++)
        if (first_two_digits == MASTER[i] && input_length == 16) return "MASTERCARD\n";

    // 3. for VISA
    if (first_two_digits_arr[0] == VISA && (input_length == 13 || input_length == 16))
        return "VISA\n";

    return "INVALID\n";
}

void get_first_two_nums(int *first_two_digits_arr, char *arr)
{
    first_two_digits_arr[0] = arr[0] - '0';
    first_two_digits_arr[1] = arr[1] - '0';
}

void convert_input_arr(long input, char *card_number_arr)
{
    snprintf(card_number_arr, 20, "%ld", input);
}
