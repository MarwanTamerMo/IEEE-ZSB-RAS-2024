#include <stdio.h>

#define ADD(x, y) ((x) + (y))
#define SUBTRACT(x, y) ((x) - (y))

enum ArithmeticOperation 
{
    ADDITION = '+',
    SUBTRACTION = '-'
};

int calculate(int operand1, int operand2, enum ArithmeticOperation operation) 
{
    switch (operation) 
    {
        case ADDITION:
            return ADD(operand1, operand2);
        case SUBTRACTION:
            return SUBTRACT(operand1, operand2);
        default:
            printf("Invalid operation\n");
            return 0;
    }
}

int main() 
{
    int operand1, operand2;
    char operation_char;

    printf("Enter operand1: ");
    scanf("%d", &operand1);
    printf("Enter operand2: ");
    scanf("%d", &operand2);
    printf("Enter operation character (+ for addition, - for subtraction): ");
    scanf(" %c", &operation_char);

    enum ArithmeticOperation operation = (enum ArithmeticOperation)operation_char;

    printf("Result: %d\n", calculate(operand1, operand2, operation));

    return 0;
}