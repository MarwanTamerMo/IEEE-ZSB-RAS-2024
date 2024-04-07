#include <stdio.h>

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;  // This pointer will point to the the array exactly the first element of the array

    printf("Array elements using pointer:\n");
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) 
    {
        printf("%d ", *ptr);
        ptr++;  // Move the pointer to the next element by incrementing the pointer by the int size in the memory
    }
    printf("\n");

    return 0;
}
