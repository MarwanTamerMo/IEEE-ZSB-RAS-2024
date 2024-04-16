#include <stdio.h>

#define ADDITION(a, b) ((a) + (b))
#define SUBTRACTION(a, b) ((a) - (b))
#define MULTIPLICATION(a, b) ((a) * (b))
#define DIVISION(a, b) ((b) != 0 ? ((a) / (b)) : (printf("Error: Division by zero!\n"), 0))

int main() 
{
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);

    float result;
    switch (choice) 
    {
        case 1:
            result = ADDITION(num1, num2);
            printf("Result of addition: %.2f\n", result);
            break;
        case 2:
            result = SUBTRACTION(num1, num2);
            printf("Result of subtraction: %.2f\n", result);
            break;
        case 3:
            result = MULTIPLICATION(num1, num2);
            printf("Result of multiplication: %.2f\n", result);
            break;
        case 4:
            result = DIVISION(num1, num2);
            if (num2 != 0)
                printf("Result of division: %.2f\n", result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
