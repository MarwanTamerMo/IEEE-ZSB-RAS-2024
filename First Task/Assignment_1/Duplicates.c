#include <stdio.h>

// Function to count duplicates in an array
int Duplicates(int arr[], int size) 
{
    int count = 0;

    for (int i = 0; i < size; i++) 
    {
        // Check if the current element is duplicate. The (-1) means that it has been visited already
        //? Because I will iterate over the whole array one time to check for duplicate and then set it to (-1)

        if (arr[i] != -1) 
        {
            int duplicateCount = 1;

            for (int j = i + 1; j < size; j++) 
            {
                if (arr[i] == arr[j]) 
                {
                    duplicateCount++;
                    arr[j] = -1; // Mark as visited
                }
            }
            // If duplicateCount is greater than 1, it means there are duplicates
            if (duplicateCount > 1) 
            {
                count++;
            }
        }
    }
    return count;
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 2, 3, 6, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int duplicateCount = Duplicates(arr, size);

    printf("Total number of duplicate elements: %d\n", duplicateCount);

    return 0;
}