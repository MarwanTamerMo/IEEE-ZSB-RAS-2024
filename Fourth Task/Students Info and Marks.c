#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 2

struct student_info 
{
    char name[50];
    int age;
    char address[100];
    int marks;
};

int print_student_info(struct student_info students[], int size) 
{
    int count_low_marks = 0;

    for (int i = 0; i < size; ++i) 
    {
        printf("Student %d info:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");

        if (students[i].marks < 12) 
        {
            count_low_marks++;
        }
    }

    return count_low_marks;
}

int main() 
{
    struct student_info students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; ++i)
    {

        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &students[i].age);
        printf("Enter address for student %d: ", i + 1);
        scanf(" %[^\n]", students[i].address);
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &students[i].marks);
        printf("\n");
    }

    int count = print_student_info(students, MAX_STUDENTS);
    
    printf("Number of students with marks less than 12: %d\n", count);

    return 0;
}
