#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node* insert_after(struct node *head) {
    int key;
    printf("Insert after value: ");
    scanf("%d", &key);

    struct node *temp = head;

    while(temp != NULL && temp->data != key)
    temp = temp->next;

    if(temp == NULL) {
        printf("Value not found\n");
        return head;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}