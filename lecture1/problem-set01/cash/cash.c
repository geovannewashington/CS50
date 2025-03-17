#include <cs50.h>
#include <stdio.h>
/*
PS notes:
$1.00 == 100cents
user input == change owned (nice, we won't need to calculate it)
Core of problem: NOTE: prints the minimum coins needed to make the given amount of change, in cents

let user input = 70
output should be: 4 (25, 25, 10, 10)

Coins we have available: 
25cents, 10cents, 5cents, 1cent

int calc_coin(int currentMax, int currentChange)
	if (currentMax - currentChange) > currentMax
		calc_coin(currentMax, currentChange);
*/

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNIES 1

int change;
int quarters, dimes, nickels, pennies = 0;
int result;

void calc_pennies()
{
    do {
        if (change == PENNIES) {
            change = change - PENNIES; // change becomes 0 and do...while exits
            pennies++;
        } 
        else if (change > PENNIES) {
            change = change - PENNIES; // subtracts but still != 0        
            pennies++;
        }
    } while (change > 0);

}

void calc_nickels()
{
    do {
        if (change < NICKEL) {
            calc_pennies();
        } 
        else if (change == NICKEL) {
            change = change - NICKEL; // change becomes 0 and do...while exits
            nickels++;
        } 
        else if (change > NICKEL) {
            change = change - NICKEL; // subtracts but still != 0        
            nickels++;
        }
    } while (change > 0);

}

void calc_dime()
{
    do {
        if (change < DIME) {
            calc_nickels();
        } 
        else if (change == DIME) {
            change = change - DIME; // change becomes 0 and do...while exits
            dimes++;
        } 
        else if (change > DIME) {
            change = change - DIME; // subtracts but still != 0        
            dimes++;
        }
    } while (change > 0);

}

void calc_quarter() 
{
    if (change != 0) {
        do {
            if (change < QUARTER) {
                calc_dime();
            } 
            else if (change == QUARTER) {
                change = change - QUARTER; // change becomes 0 and do...while exits
                quarters++;
            } 
            else if (change > QUARTER) {
                change = change - QUARTER; // subtracts but still != 0        
                quarters++;
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

    calc_quarter();
    result = quarters + dimes + nickels + pennies; 
    
    //the following printf should print the amount of coins needed.
    printf("%d\n", result);
    return 0;
}

// Prompt the user for change owed, in cents

// Calculate how many quarters you should give customer
// Subtract the value of those quarters from cents

// Calculate how many dimes you should give customer
// Subtract the value of those dimes from remaining cents

// Calculate how many nickels you should give customer
// Subtract the value of those nickels from remaining cents

// Calculate how many pennies you should give customer
// Subtract the value of those pennies from remaining cents

// Sum the number of quarters, dimes, nickels, and pennies used
// Print that sum

// NOTE: quarters = 25cents, dimes = 10cents, nickels = 5cents and finally pennies = 1cent


