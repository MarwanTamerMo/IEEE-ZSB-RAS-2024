#include <stdio.h>

struct Date 
{
    int day;
    int month;
    int year;
};

void Compare(struct Date date1, struct Date date2) 
{

    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year) 
    {
        printf("Dates are equal\n");
    } 
    else 
    {
        printf("Dates are not equal\n");
    }
}

int main() 
{
    struct Date date1, date2;
    
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);
    
    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    Compare(date1, date2);

    return 0;
}
