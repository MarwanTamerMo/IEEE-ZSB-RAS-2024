#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) 
    {
        last = last->next;
    }

    last->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) 
{
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) 
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* node) 
{
    if (node == NULL) 
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list: ");

    while (node != NULL) 
    {
        printf("%d ", node->data);
        node = node->next;
    }
    
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;
    char choice;
    int value;

    while (1) 
    {
        printf("Enter a value to add to the linked list, '11' to delete, 'p' to print, or 'x' to exit: ");
        scanf(" %c", &choice);

        if (choice == 'x') {
            break;
        } 
        else if (choice == 'p') 
        {
            printList(head);

        } 
        else if (choice == '1') 
        {
            deleteNode(&head, 11);

        } 
        else 
        {
            scanf("%d", &value);
            append(&head, value);
        }
    }

    // Free memory allocated for the linked list before exiting
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}