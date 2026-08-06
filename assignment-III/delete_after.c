#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};


struct node* delete_after(struct node *head) {
    int key;
    printf("Delete node after value: ");
    scanf("%d", &key);

    struct node *temp = head;

    while(temp != NULL && temp->data != key)
    temp = temp->next;

    if(temp == NULL || temp->next == NULL) {
        printf("Deletion not possible\n");
        return head;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}