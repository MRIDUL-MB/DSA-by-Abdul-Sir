#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
} queue;

queue q;
void create(int size)
{
    q.arr = (int *)malloc(size * sizeof(int));
    q.front = q.rear = -1;
    q.size = size;
    printf("Queue is created\n");
}
int isEmpty()
{
    if (q.rear == q.front)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (q.rear == q.size - 1)
        return 1;
    else
        return 0;
}
void insert(int value)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }
    q.rear++;
    q.arr[q.rear] = value;
    printf("%d is inserted\n", value);
}

int del()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    q.front++;
    int x = q.arr[q.front];
    return x;
}

void display()
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main()
{

    create(10);
    insert(1);
    display();
    insert(2);
    insert(3);
    display();
    printf("%d is deleted\n", del());
    display();
}