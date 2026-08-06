#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node* delete_first(struct node *head) {
    if(head == NULL) {
        printf("List Empty\n");
        return head;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    return head;
}