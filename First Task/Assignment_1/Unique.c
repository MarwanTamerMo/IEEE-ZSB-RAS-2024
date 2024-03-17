#include <stdio.h>

void printUnique(int arr[], int size) 
{

    printf("Unique elements in the array: ");

    for (int i = 0; i < size; ++i) 
    {
        int count = 1;

        for (int j = 0; j < size; ++j)
        {
            if (i != j && arr[i] == arr[j]) // Check if the current element is a duplicate
            {
                count++;
                break;
            }
        }

        if (count == 1)
        {
           printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 2, 3, 5, 6, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printUnique(arr, size);

    return 0;
}