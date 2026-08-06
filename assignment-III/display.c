#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *head){
    struct node *temp = head;

    if(head == NULL){
        printf("\nList is Empty");
        return;
    }

    printf("\nList : ");

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n NULL");
}
