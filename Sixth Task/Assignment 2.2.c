#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isStopCode(char *str, char *stopCode) 
{
    return strcmp(str, stopCode) == 0;
}

void printUniqueCharacters(char *str) 
{
    int freq[256] = {0}; // Assuming ASCII characters
    
    printf("Unique characters in the string: ");
    
    for (int i = 0; str[i] != '\0'; ++i) 
    {
        char ch = str[i];

        if (freq[ch] == 0) 
        {
            printf("%c", ch);
        }

        freq[ch]++;
    }

    printf("\n");
}

int main() 
{
    char input[100];
    const char *stopCode = ":(";

    while (1) 
    {
        printf("Enter a string (Enter ':(' to stop): ");
        scanf("%s", input);

        if (isStopCode(input, stopCode)) 
        {
            printf("Stop code detected. Exiting...\n");
            break;
        }

        printUniqueCharacters(input);
    }

    return 0;
}