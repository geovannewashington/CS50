// swap.c 

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Integers;

// swap prototype
void swap(int *x, int *y); 

int main()
{
    Integers foo = { .y = 10, .x = 20 };
    Integers *ptr = &foo;
    
    printf("Before: foo.x = %d | foo.y = %d\n", foo.x, foo.y);
    swap(((int *)ptr + 0), ((int *)ptr + 1));
    printf("Before: foo.x = %d | foo.y = %d\n", foo.x, foo.y);
    
    return 0;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp; 
}
