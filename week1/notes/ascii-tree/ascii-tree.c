#include <stdio.h>
#include <cs50.h>

void clear_screen(void) {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}

void print_rows(int n, int padding);

int main(void)
{
    int total_height;
    int initial_padding;
    
    do {
        total_height = get_int("how tall you want your tree to be? ");
        if (total_height < 1) {
            puts("⚠ [WARNING]: tree needs to be at least 1 unit tall");
            puts("");
        }
        
        initial_padding = total_height - 1;
    } while (total_height < 1);
    clear_screen();
    

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
    printf("%*s", padding, "");

    // Print stars
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    
    printf("\n");
}
