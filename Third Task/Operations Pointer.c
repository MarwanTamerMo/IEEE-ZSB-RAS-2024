#include <stdio.h>

float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);

typedef float (*operation_ptr)(float, float);

float addition(float a, float b) 
{
    return a + b;
}

float subtraction(float a, float b) 
{
    return a - b;
}


float multiplication(float a, float b) 
{
    return a * b;
}


float division(float a, float b) 
{
    if (b != 0)
    {
        return a / b;
    }
    else 
    {
        printf("Error: Division by zero!\n");
        return 0; 
    }
}

int main() 
{
    operation_ptr operation;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            operation = addition;
            break;
        case 2:
            operation = subtraction;
            break;
        case 3:
            operation = multiplication;
            break;
        case 4:
            operation = division;
            break;
        default:
            printf("Invalid choice!\n");
            return 1; 
    }


    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);

    float result = operation(num1, num2);

    switch (choice) 
    {
        case 1:
            printf("Result of addition: %.2f\n", result);
            break;
        case 2:
            printf("Result of subtraction: %.2f\n", result);
            break;
        case 3:
            printf("Result of multiplication: %.2f\n", result);
            break;
        case 4:
            printf("Result of division: %.2f\n", result);
            break;
    }

    return 0;
}