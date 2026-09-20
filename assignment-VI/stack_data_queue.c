#include <stdio.h>
#define MAX 5
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;
void push1(int value)
{
    if (top1 == MAX - 1)
        printf("Queue is full!\n");
    else
        stack1[++top1] = value;
}
void push2(int value)
{
    stack2[++top2] = value;
}
int pop1()
{
    return stack1[top1--];
}
int pop2()
{
    return stack2[top2--];
}
void enqueue(int value)
{
    push1(value);
    printf("%d inserted into queue.\n", value);
}
void dequeue()
{
    int value;
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    while (top1 != -1)
    {
        push2(pop1());
    }
    value = pop2();

    while (top2 != -1)
    {
        push1(pop2());
    }

    printf("%d deleted from queue.\n", value);
}

void display()
{
    int i;

    if (top1 == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");

    for (i = top1; i >= 0; i--)
    {
        printf("%d ", stack1[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n--- Queue Using Stack ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}