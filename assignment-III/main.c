#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node* insert_first(struct node*);
struct node* insert_end(struct node*);
struct node* insert_after(struct node*);
struct node* delete_first(struct node*);
struct node* delete_last(struct node*);
struct node* delete_after(struct node*);
void display(struct node*);

int main()
    {
    int ch;
    struct node *head = NULL;

    do
        {
        printf(" 1. Insert First");
        printf(" 2. Insert End");
        printf(" 3. Insert After");
        printf(" 4. Delete First");
        printf(" 5. Delete Last");
        printf(" 6. Delete After");
        printf(" 7. Display");
        printf(" 8. Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
            {
            case 1:head = insert_first(head);
            break;

            case 2:head = insert_end(head);
            break;

            case 3:head = insert_after(head);
            break;

            case 4:head = delete_first(head);
            break;

            case 5:head = delete_last(head);
            break;

            case 6:head = delete_after(head);
            break;

            case 7:display(head);
            break;

            case 8:printf("\nProgram Ended.");
            break;

            default:printf("\nInvalid Choice");
            }

        }while(ch != 8);

        return 0;
    }