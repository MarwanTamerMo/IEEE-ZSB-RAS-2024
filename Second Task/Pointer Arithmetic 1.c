#include <stdio.h>

int main() 
{
    int *pl;
    char *p2;
    long long *p5;

    int x = 10;
    char y = 'A';
    long long z = 123456789012345LL;

    pl = &x;
    p2 = &y;
    p5 = &z;

    printf("Before Increment:\n");
    printf("pl points to: %d\n", *pl);
    printf("p2 points to: %c\n", *p2);
    printf("p5 points to: %lld\n", *p5);

    pl++;
    p2++;
    p5++;

    printf("\nAfter Increment:\n");
    printf("pl points to: %d\n", *pl);  // Output: Undefined Behavior, Incrementing an integer pointer by 1 moves it to the next integer-sized memory location, which may or may not be accessible.
    printf("p2 points to: %c\n", *p2);  // Output: Undefined Behavior, Incrementing a char pointer by 1 moves it to the next byte-sized memory location, which may or may not be accessible.
    printf("p5 points to: %lld\n", *p5);  // Output: Undefined Behavior, Incrementing a long long pointer by 1 moves it to the next long long-sized memory location, which may or may not be accessible.

    return 0;
}