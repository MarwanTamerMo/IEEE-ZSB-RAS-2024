#include <stdio.h>

int main() 
{
    char name[100]; 
    int max_length;
    
    printf("Enter the maximum length of the name: ");
    scanf("%d", &max_length);

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter your name (maximum %d characters): ", max_length);
    fgets(name, sizeof(name), stdin);
    
    //? Replace the newline character with null terminator 
    //! To avoid the whitespace character in the buffer
    for (int i = 0; i < sizeof(name); ++i) 
    {
        if (name[i] == '\n') 
        {
            name[i] = '\0';
            break;
        }
    }

    printf("Your name: %s\n", name);

    // Calculate frequency of the most repeated character
    int freq[256] = {0}; // Assuming ASCII characters
    
    int max_freq = 0;
    char most_repeated_char;

    for (int i = 0; name[i] != '\0'; ++i) 
    {
        char ch = name[i];
        freq[ch]++;

        if (freq[ch] > max_freq) 
        {
            max_freq = freq[ch];
            most_repeated_char = ch;
        }
    }

    printf("Frequency of the most repeated character '%c': %d\n", most_repeated_char, max_freq);

    return 0;
}