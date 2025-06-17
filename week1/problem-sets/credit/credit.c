#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
/* CS50: The credit problem */

const int AMEX[] = {34, 37}; // AMEX -> American Express
const int MASTER[] = {22, 51, 52, 53, 54, 55};
const int VISA = 4;

void get_first_two_nums(int *first_two_digits_arr, char *arr);
char *discover_company(int *first_two_digits_arr, char *card_number_arr);
bool is_valid(char *card_number_arr); // -> Luhn's Algorithm
void convert_input_arr(long int input, char *card_number_arr);
int get_str_length(char *input);
void print_result(char *result_arr);

int main(void)
{
    // this array will contain the first two digits of the input for purposes of comparing later
    int first_two_digits_arr[2] = {0};
    // this array contains the input credit card number converted into characters
    char card_number_arr[20] = {0};
    // getting input from user (credit card number).
    long int card_number = get_long("Number: "); // -> I need to turn this into an array
    // convert_input_arr: converts input from long int to an array of characters
    convert_input_arr(card_number, card_number_arr);
    // [function]get_first_two_nums gets the first two digits of input into an separate array
    get_first_two_nums(first_two_digits_arr, card_number_arr);

    print_result(discover_company(first_two_digits_arr, card_number_arr));
    return 0;
}

void print_result(char *result_arr)
{
    int j = 0;
    char c;
    while ((c = result_arr[j]) != '\0')
    {
        printf("%c", result_arr[j]);
        j++;
    }
}

bool is_valid(char *card_number_arr)
{
    // getting the length of given credit card number.
    int input_length = get_str_length(card_number_arr);
    // PASSED: printf("%d\n", input_length); // should be 16 for my input //PASSED

    bool is_legit = false;
    int even_arr[20] = {0};
    int odd_arr[20] = {0};
    int single_digits_arr[40] = {0};

    int index_even_arr = 0;
    int index_odd_arr = 0;

    // this loop populates even_arr
    for (int i = input_length - 2; i >= 0; i -= 2)
    {
        even_arr[index_even_arr] = (card_number_arr[i] - '0') * 2;
        index_even_arr++;
    }
    // this loop populates odd_arr
    for (int i = input_length - 1; i >= 0; i -= 2)
    {
        odd_arr[index_odd_arr] = (card_number_arr[i] - '0');
        index_odd_arr++;
    }
    /* PASSED
    for (int i; i < index_even_arr; i++)
        printf("even: %d\n", even_arr[i]);
    for (int i; i < index_odd_arr; i++)
        printf("odd: %d\n", odd_arr[i]);
    */

    int even_arr_length, odd_arr_length;
    int j = 0;

    if (input_length % 2 == 0)
    {
        even_arr_length = input_length / 2;
        odd_arr_length = input_length / 2;
    }
    else
    {
        even_arr_length = (input_length / 2) + 1;
        odd_arr_length = (input_length / 2) + 2;
    }
    // now it's correctly nine but still returning INVALID\n

    for (int i = 0; i < even_arr_length; ++i)
    {
        if (even_arr[i] >= 10)
        {
            single_digits_arr[j] = even_arr[i] / 10;
            single_digits_arr[j + 1] = even_arr[i] % 10;
            j += 2;
        }
        else
        {
            single_digits_arr[j] = even_arr[i];
            j++;
        }
    }
    /*PASSED
    for (int i = 0; i < j; i++) {
        printf("%d\n", single_digits_arr[i]);
    }
    */
    int added_products = 0;
    j = (input_length % 2 == 0) ? j : j + 1;
    for (int i = 0; i < j; i++)
    {
        added_products += single_digits_arr[i];
    }
    // printf("added products: %d\n", added_products); // should be -> 13
    int last_digit = added_products;
    for (int i = 0; i < odd_arr_length; ++i)
    {
        last_digit += odd_arr[i];
    }
    // TEST PASSED! printf("%d\n", last_digit); // should be -> 60

    is_legit = last_digit % 10 == 0;
    // TEST PASSED printf("%d\n", is_legit); // should be 1 for my input
    // So the issue is outside this function
    return is_legit;
}

char *discover_company(int *first_two_digits_arr, char *card_number_arr)
{
    // getting the length of given credit card number.
    int input_length = get_str_length(card_number_arr);

    if (!is_valid(card_number_arr))
    {
        return "INVALID\n";
    }
    else
    {
        //                      ten's place                     unary's place
        int first_two_digits = (first_two_digits_arr[0] * 10) + first_two_digits_arr[1];
        // TEST PASSED printf("%d", first_two_digits);
        // 1. for AMEX -> American Express
        int amex_length = (sizeof(AMEX) / sizeof(AMEX[0]));
        for (int i = 0; i < amex_length; i++)
        {
            if (first_two_digits == AMEX[i] && input_length == 15)
                return "AMEX\n";
        }

        // 2. for MASTERCARD int master_length = (sizeof MASTER / MASTER[0]);
        int master_length = sizeof(MASTER) / sizeof(MASTER[0]);
        for (int i = 0; i < master_length; i++ && input_length == 16)
        {
            if (first_two_digits == MASTER[i])
                return "MASTERCARD\n";
        }

        // 3. for VISA
        if (first_two_digits_arr[0] == VISA && (input_length == 13 || input_length == 16))
        {
            return "VISA\n";
        }

        // 4. what if it's none of those three? do I simply return INVALID\n ?
        return "INVALID\n";
    }
}

void get_first_two_nums(int *first_two_digits_arr, char *arr)
{
    for (int i = 0; i < 2; ++i)
        first_two_digits_arr[i] = arr[i] - '0';
}

void convert_input_arr(long int input, char *card_number_arr)
{
    sprintf(card_number_arr, "%ld", input);
}

int get_str_length(char *input)
{
    int length = 0;

    while (input[length] != '\0')
    {
        length++;
    }
    return length;
}
