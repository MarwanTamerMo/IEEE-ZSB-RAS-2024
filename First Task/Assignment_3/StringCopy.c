#include <stdio.h>

void stringCopy(char source[], char destination[]) 
{
    int i = 0;

    while (source[i] != '\0') // Can be done in for loop also like this - for(int i = 0; source[i] != '\0'; ++i).
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; //? This is for Null-termination the destination string
}

int main() 
{
    char source[100], destination[100];

    printf("Enter a string: ");
    scanf("%s", source);

    stringCopy(source, destination);

    printf("Copied string: %s\n", destination);

    return 0;
}