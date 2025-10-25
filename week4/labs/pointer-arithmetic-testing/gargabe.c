// gargabe.c

#include <stdio.h>

int main()
{
    int scores[1024] = {0};

    for (int i = 0; i < 1024; i++)
        printf("%d\n", scores[i]); // It's possible that one of these outputs will be non-zero
    return 0;
}
