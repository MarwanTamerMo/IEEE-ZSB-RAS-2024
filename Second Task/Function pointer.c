#include <stdio.h>

void increment_num(int *num) 
{
    (*num)++;
}

int main() 
{
    void (*ptr)(int *);

    ptr = &increment_num;

    int value = 5;

    (*ptr)(&value);

    printf("Incremented number: %d\n", value);

    return 0;
}
