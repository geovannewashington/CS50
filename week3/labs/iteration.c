// Draws a pyramid using recursion.
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // Get height of pyramid
    int height = get_int("Height: "); 
    
    // Draw pyramid
    draw(height);
    return 0;
}

void draw(int n)
{
    // If nothing to draw.
    if (n <= 0) {
        return;
    }

    // NOTE: we cannot call draw passin 'n' 
    // this will result in a infinite loop.
    draw(n - 1);

    // Draw one more row of width n 
    for (int i = 0; i < n; i++) {
        printf("#");
    }
    printf("\n");
}
