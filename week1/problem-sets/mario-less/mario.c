#include <cs50.h>
#include <stdio.h>

/* prints mario end-level pyramids */

/*[FEATURES]:
1 - accepts user input for how tall the pyramid should be
e.g:
5 units tall | output:
    #
   ##
  ###
 ####
#####

it's essentially a square, so the base = height
*/
int initial = 1;

void draw_pym(int pym_heigth);
void print_line(int pym_heigth);

int main(void)
{
    int pym_height;
    do {
        pym_height = get_int("Height: ");
        if (pym_height < 1)
            puts("[WARNING]: Pyramid heigth needs to be at least one unit tall");
    } while (pym_height < 1); /* pyramid needs to be at least 1 unit tall, we could prompt this as a warning to the user*/
    draw_pym(pym_height);

    return 0;
}

void draw_pym(int pym_height)
{   
    for (int i = 0; i < pym_height; i++) {
        print_line(pym_height);
    }
}

void print_line(int pym_height) 
{
    if ((pym_height - initial) != 0) {
        printf("%*s", pym_height - initial, " ");
    } 
    
    for (int i = 0; i < initial; ++i) {
        printf("#");
    }

    printf("\n");    
    initial++;
}

