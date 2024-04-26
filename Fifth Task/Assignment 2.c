#include <stdio.h>

enum ArithmeticOperation 
{
    ADDITION = '+',
    DIVISION = '/',
    BITWISE_AND = '&',
    LEFT_SHIFT = 'l',
    LOGICAL_NOT = '!'
};

int calculate(int operand1, int operand2, enum ArithmeticOperation operation) 
{
    switch (operation) 
    {
        case ADDITION:
            return operand1 + operand2;
        case DIVISION:
            return operand1 / operand2;
        case BITWISE_AND:
            return operand1 & operand2;
        case LEFT_SHIFT:
            return operand1 << operand2;
        case LOGICAL_NOT:
            return !operand1;
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
    printf("Enter operation character: ");
    scanf(" %c", &operation_char);

    enum ArithmeticOperation operation = (enum ArithmeticOperation)operation_char;

    printf("Result: %d\n", calculate(operand1, operand2, operation));

    printf("Size of enum ArithmeticOperation: %lu bytes\n", sizeof(enum ArithmeticOperation));

    return 0;
}
