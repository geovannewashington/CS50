#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);
void meow(int n);

int main(void)
{
        int n = get_positive_int();
        meow(n);                
        return 0;
}

int get_positive_int(void)
{
        int n;
        do {
                n = get_int("Number: ");
        } while (n < 1); // -> so a number less than one is an invalid input, the cat can't meaow 0 times
        return n;
}

void meow(int n) {
        for (int i = 0; i < n; i++) {
                puts("meow! 🐈");
        }
}