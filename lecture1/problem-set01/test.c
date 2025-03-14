#include <stdio.h>

int main(void)
{   
    int myArr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int sizeOfArr = sizeof(myArr) / sizeof(myArr[0]); 

    int doubleArr[sizeOfArr];

    for (int i = 0; i < sizeOfArr; ++i)
    {
        doubleArr[i] = myArr[i] * 2;
        printf("index: %d | original | doubled\n", i);
    }
    return 0;
}
