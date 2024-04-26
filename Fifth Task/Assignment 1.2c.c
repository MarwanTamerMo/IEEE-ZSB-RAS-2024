#include <stdio.h>

typedef float real_number;

typedef struct 
{
    real_number real;
    real_number imag;

} complex_number;

typedef unsigned int uint;

typedef struct 
{
    uint roll_num;
    uint age;
    uint marks;

} student_data;

typedef char string[50];

typedef struct 
{
    student_data info;
    string name;
    string address;

} student_record;

void add_complex(complex_number num1, complex_number num2, complex_number *result) 
{
    result->real = num1.real + num2.real;
    result->imag = num1.imag + num2.imag;
}

int main() 
{
    printf("Size of real_number: %lu bytes\n", sizeof(real_number));
    printf("Size of complex_number: %lu bytes\n", sizeof(complex_number));
    printf("Size of uint: %lu bytes\n", sizeof(uint));
    printf("Size of student_data: %lu bytes\n", sizeof(student_data));
    printf("Size of string: %lu bytes\n", sizeof(string));
    printf("Size of student_record: %lu bytes\n", sizeof(student_record));

    complex_number num1 = {3.5, 2.7};
    complex_number num2 = {1.8, 4.2};
    
    complex_number result;

    add_complex(num1, num2, &result);

    printf("Result: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
