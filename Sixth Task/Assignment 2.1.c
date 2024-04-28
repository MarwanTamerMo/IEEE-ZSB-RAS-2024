#include <stdio.h>

int main() 
{
    int hours, minutes, seconds;
    int time_in_seconds;

    printf("Enter the time in [hh:mm:ss] format: ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) 
    {
        printf("Invalid time format!\n");
        return 1;
    }

    time_in_seconds = hours * 3600 + minutes * 60 + seconds;

    printf("Time stored in a single integer variable: %d seconds\n", time_in_seconds);

    // Got to get this formula from ChatGpt
    hours = time_in_seconds / 3600;
    minutes = (time_in_seconds % 3600) / 60;
    seconds = time_in_seconds % 60;

    printf("Time extracted from the integer variable: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
