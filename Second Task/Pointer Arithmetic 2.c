#include <stdio.h>

int main() 
{
    int hex_value = 0x12345678;
    int *ptr = &hex_value;

    printf("Before Operations: *ptr = 0x%x\n", *ptr);

    *ptr++;
    printf("After *ptr++: *ptr = 0x%x\n", *ptr); // Output: Undefined Behavior. *ptr++ first dereferences the pointer and then increments it, meaning it increments the address it points to. This can lead to unexpected behavior as it may not point to a valid memory location.

    *++ptr;
    printf("After *++ptr: *ptr = 0x%x\n", *ptr); // Output: Undefined Behavior. *++ptr first increments the pointer and then dereferences it. Similar to the previous operation, it may not point to a valid memory location.

    ++*ptr;
    printf("After ++*ptr: *ptr = 0x%x\n", *ptr); // Output: Incremented value of hex_value. ++*ptr increments the value at the memory location ptr points to, which modifies hex_value.

    return 0;
}
