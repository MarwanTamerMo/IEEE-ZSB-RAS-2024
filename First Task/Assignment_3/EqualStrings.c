#include <stdio.h>

int main() 
{
    char str1[100], str2[100];
    int isEqual = 1; // Assume strings are equal initially

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Compare each character of both strings

    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; ++i) 
    {
        if (str1[i] != str2[i]) 
        {
            isEqual = 0; 
            break;
        }
    }

    if (isEqual) 
    {
        printf("The strings are equal.\n");
    }
    else 
    {
        printf("The strings are not equal.\n");
    }

    return 0;
}