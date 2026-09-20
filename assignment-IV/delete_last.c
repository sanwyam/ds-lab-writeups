#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
extern struct Node *head;
void delete_last()
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}