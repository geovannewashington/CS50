#include <stdio.h>

int convert_case(char c);

int main(int argc, char *agrv[])
{
    int c;
    
    while ((c = getchar()) != EOF)
        printf("%c\n", convert_case(c));

    return 0;
}

int convert_case(char c)
{
    // check if input is lowercase
    if (c >= 97 && c <= 122) return c - 32; 
    // check if input is uppercase
    if (c >= 65 && c <= 90) return c + 32;
    
    // default failure return;
    return 1;
}

