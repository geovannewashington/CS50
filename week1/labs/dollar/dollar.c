#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

char to_upper(char c);
char to_lower(char c);

int main(void)
{
        int dollars = 1;
        
        while (true) {
                char c = get_char("Here's $%d. Double it and give to next person? [y = yes] ", dollars);
                if (to_upper(c) == 'Y') {
                        dollars *= 2;
                } else {
                        puts("Alright... program finished.");
                        break; // exits the loop if the person doesn't doulbe it
                }
        }

        printf("Here's $%d. 💸\n", dollars);
        return 0;
}

char to_upper(char c) 
{
        return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

char to_lower(char c) 
{
        return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}