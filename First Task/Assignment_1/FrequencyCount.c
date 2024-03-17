#include <stdio.h>

void FrequencyCount(int arr[], int size) 
{
    printf("Frequency of each element:\n");

    for (int i = 0; i < size; i++) 
    {
        int count = 1;

        if (arr[i] != -1) 
        {
            for (int j = i + 1; j < size; j++) 
            {
                if (arr[i] == arr[j]) 
                {
                    count++;
                    arr[j] = -1; //? Mark as visited, if visited it will not be counted again
                }
            }

            printf("%d : %d\n", arr[i], count);
        }
    }
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 2, 3, 5, 6, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    FrequencyCount(arr, size);

    return 0;
}