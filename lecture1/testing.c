#include <stdio.h>

void print_rows(int n, int padding);
int main(void)
{
    const int total_height = 8;
    int initial_padding = total_height - 1;
    int total_width = 1;
    
    for (int i = 0; i < total_height; i++) {
        print_rows(total_width, initial_padding);
        initial_padding--;
        
        if (i == 0) {
            total_width *= 3;
        } else if (i >= 1) {
            total_width += 2;
        } 
    }

    return 0;
}

void print_rows(int n, int padding)
{
    // Print padding spaces
    for (int j = 0; j < padding; j++) {
        putchar(' ');
    }
    
    // Print stars
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    
    printf("\n");
}