#include <stdio.h>

int main() {
    int x = 10, y = 20, z = 30;
    int *p, *q, *r;
    
    p = &x;
    q = &y;
    r = &z;

    // Print initial values
    printf("Initial values:\n");
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    printf("p: %p, q: %p, r: %p\n", p, q, r);
    printf("*p: %d, *q: %d, *r: %d\n", *p, *q, *r);

    // Swapping pointers
    printf("\nSwapping pointers.\n");
    int *temp = r;
    r = p;
    p = q;
    q = temp;

    // Print values after swapping
    printf("\nValues after swapping:\n");
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    printf("p: %p, q: %p, r: %p\n", p, q, r);

    return 0;
}