#include <cs50.h>
#include <stdio.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNIES 1

const int COINS_LABELS[] = {QUARTER, DIME, NICKEL, PENNIES};

int i = 0; 
int coins = 0;
int current_max = COINS_LABELS[0]; 
int change;

void calc() 
{
    if (change != 0) {
        do {
            if (change < current_max) {
                i++;
                current_max = COINS_LABELS[i];
                calc();
            } 
            else if (change == current_max) {
                change -= current_max; // change becomes 0 and do...while exits
                coins++;
            } 
            else if (change > current_max) {
                change -= current_max; // subtracts but still != 0        
                coins++;
            }
        } while (change > 0);
    }
}

int main(void)
{
    do {
        change = get_int("Change owed: ");
        if (change < 0) {
            puts("⚠ [WARNING]: change needs to be at least 0");
            puts("");
        }
    } while (change < 0);

    calc();
    
    printf("%d\n", coins);
    return 0;
}
