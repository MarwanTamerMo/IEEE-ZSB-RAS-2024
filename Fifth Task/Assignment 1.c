#include <stdio.h>
#include <string.h>

typedef struct 
{
    unsigned int roll_number : 4;
    unsigned int age : 8;
    unsigned int marks : 3;

} student_info;

typedef struct 
{
    char name[20];
    char address[50];

} string_info;

typedef struct 
{
    student_info info;
    string_info strings;
    
} student_record;

void print_student_info(student_record record) {
    printf("Roll Number: %u\n", record.info.roll_number);
    printf("Age: %u\n", record.info.age);
    printf("Marks: %u\n", record.info.marks);
    printf("Name: %s\n", record.strings.name);
    printf("Address: %s\n", record.strings.address);
    printf("\n");
}

int main() {
    student_record students[15];

    for (int i = 0; i < 15; ++i) 
    {
        students[i].info.roll_number = i + 1;
        students[i].info.age = 20 + i;
        students[i].info.marks = i % 8;
        sprintf(students[i].strings.name, "Student %d", i + 1);
        sprintf(students[i].strings.address, "Address %d", i + 1);
    }

    for (int i = 0; i < 15; ++i) 
    {
        printf("Student %d:\n", i + 1);
        print_student_info(students[i]);
    }

    printf("Size of student_record: %lu bytes\n", sizeof(student_record));

    return 0;
}
