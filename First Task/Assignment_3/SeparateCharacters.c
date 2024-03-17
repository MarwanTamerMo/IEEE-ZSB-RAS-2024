#include <stdio.h>

int main() 
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Individual characters in the string:\n");

    for (int i = 0; str[i] != '\0'; i++) 
    {
        printf("%c ", str[i]);
    }

    printf("\n");

    return 0;
}