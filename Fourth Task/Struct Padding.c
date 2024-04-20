#include <stdio.h>
//#pragma pack

struct test 
{
    int id;
    char name[50];
    char class_id;
};

int main() 
{

    printf("Size of struct test before changing the order of definition of the string: %zu bytes\n", sizeof(struct test));

    struct test 
    {
        char name[50];
        int id;
        char class_id;
    };

    printf("Size of struct test after changing the order of definition of the string: %zu bytes\n", sizeof(struct test));

    return 0;
}

/*--------------------------------------------------------------
Explanation:

NOTE: I'm explaining this considering this program runs on a 32-Bit system.

There's something called struct padding:-

In C, the size of a struct is determined by the size of its members and any padding added by the compiler for alignment purposes.

In 32-bit systems the size of an int for example is reserved in the memory as 4-Bytes each int variable,

so the compiler tells the system to allocate 4-Bytes for each varibale in the struct regardless of its type,
and if it's larger than 4-Bytes or the allocated space the CPU automatically allocates another space of 4-Bytes in
the memory for it even if it only needs one byte to be fully stored.

For example in the second struct test the compiler at first reserved 4-Bytes of memory for the char type variable
even it only needs 1-Byte to be fully stored, that results in loss of 3-Bytes in the memory.

When we changed the order of the struct variables to make the int variable the compiler reserved 4-Bytes
for the int variable resulted in no waste or void space in the memory making it more efficient.4

We can avoid this and save us the time of reallocating members of the struct by using PACKING
and it can be done using a macro called #pragma see the the comment above (Line 2);

- Marwan Tamer

--------------------------------------------------------------*/