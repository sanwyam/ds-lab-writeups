#include <stdio.h>

int front = -1;
int rear = -1;
int max = 4;
int arr[max];

int main()
{
    int ch;
    do
    {
        printf("\nMenu: 1.Enqueue 2.dequeue 3.exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("\nExit");
            break;
        default:
            printf("\nInvalid choice");
        }
    } while (ch != 3);
    return 0;
}

void enqueue()
{
    int element;
    if ((rear + 1) % max == front)
        printf("\nQueue full");
    else
    {
        printf("\nEnter new element: ");
        scanf("%d", &element);
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % max;
        arr[rear] = element;
    }
}

void dequeue()
{
    if (rear == -1)
        printf("\nQueue empty");
    else
    {
        printf("\nRemoved element os: %d", arr[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % max;
    }
}