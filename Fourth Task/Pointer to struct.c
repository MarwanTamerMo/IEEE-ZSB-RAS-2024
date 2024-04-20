#include <stdio.h>
#include <stdlib.h>

struct info 
{
    char name[50];
    int age;
};

int main()
{
    struct info person;

    strcpy(person.name, "John");
    person.age = 30;

    struct info *ptr = &person;

    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);

    return 0;
}