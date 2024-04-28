#include <stdio.h>

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))

inline size_t my_sizeof_func(int);

int main() 
{
    int arr[10];
    int num = 10;

    printf("Size of int: %zu\n", my_sizeof(num));

    printf("Size of int: %zu\n", my_sizeof_func(num));
    printf("Size of arr: %zu\n", my_sizeof_func(arr));

    return 0;
}

inline size_t my_sizeof_func(int type) 
{
    return ((char *)(&type + 1) - (char *)(&type));
}

/*----------------------------------------------------------------

Macros:

- Macros are preprocessor directives that perform pure text replacement.
- They are processed by the preprocessor before the compilation.
- Macros do not perform type checking. They operate purely on textual substitution.
- Macros can be used to define constants, inline functions, or perform simple computations.

//? Best use case:

- You need pure text replacement.
- You need to define constants or perform simple computations.
- Compatibility with older compilers is a concern.

Inline Functions:

- Inline functions are actual functions that can be defined within the code.
- They are processed by the compiler during the compilation phase.
- Inline functions perform type checking and provide better safety compared to macros.
- They can be used to define complex operations or computations.

//? Best use case:

- You need type safety and type checking.
- You want to define complex operations or computations.
- Readability and maintainability of code are important.

----------------------------------------------------------------*/