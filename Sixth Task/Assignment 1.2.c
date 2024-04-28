#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *ptr1, *ptr2, *ptr3;

    // Allocate memory using malloc
    ptr1 = (int *)malloc(sizeof(int));

    if (ptr1 == NULL) 
    {
        printf("Memory allocation failed for ptr1\n");
    } 
    else 
    {
        *ptr1 = 10;
        printf("Value of ptr1: %d\n", *ptr1);
    }

    // Allocate memory using malloc
    ptr2 = (int *)malloc(2 * sizeof(int));

    if (ptr2 == NULL) 
    {
        printf("Memory allocation failed for ptr3\n");
    } 
    else 
    {
        ptr2[0] = 30;
        ptr2[1] = 40;
        printf("Values of ptr3: %d, %d\n", ptr3[0], ptr3[1]);
    }

    // Free the memory allocated to ptr3
    free(ptr3);
    printf("Memory allocated to ptr3 freed.\n");

    // Allocate memory with a relatively bigger size
    ptr3 = (int *)malloc(5 * sizeof(int));

    if (ptr3 == NULL) 
    {
        printf("Memory allocation failed for ptr4\n");
    } 
    else 
    {
        for (int i = 0; i < 5; ++i) 
        {
            ptr3[i] = i * 10;
        }

        printf("Values of ptr4: ");

        for (int i = 0; i < 5; ++i) 
        {
            printf("%d ", ptr3[i]);
        }
        
        printf("\n");
    }

    // Free allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}

/*----------------------------------------------------------------

Now, when memory allocated to ptr3 is freed, the memory space is returned to the system and can be reused for 
subsequent allocations. 

When ptr4 is allocated with a relatively bigger size, it might succeed or fail depending on the availability of memory. 
If the system has limited memory space and there isn't enough contiguous memory available for the larger allocation, 
the allocation for ptr4 might fail. 

This scenario could lead to memory fragmentation (memory leaks)

The operating system would not be happy about this it may cause the system services and other applications that wants
memory space to be deadlocked and stop responding.

----------------------------------------------------------------*/