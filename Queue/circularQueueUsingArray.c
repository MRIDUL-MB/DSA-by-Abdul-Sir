#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue
{
    int size;
    int rear;
    int front;
    int *arr;
} queue;

queue q;

// creating
void create(int size)
{
    q.arr = (int *)malloc(sizeof(int) * size);
    q.size = size;
    q.front = q.rear = 0;
}

// inserting
void enqueue(int val)
{
    // if queue is full
    if ((q.rear + 1) % q.size == q.front)
    {
        printf("queue is full\n");
    }
    else
    {
        q.rear = (q.rear + 1) % q.size;
        q.arr[q.rear] = val;
        printf("%d is inserted\n", val);
    }
}

// deleting
int dequeue()
{
    // if queue is empty
    int x = -1;
    if (q.rear == q.front)
    {
        printf("queue is empty\n");
    }
    else
    {
        q.front = (q.front + 1) % q.size;
        x = q.arr[q.front];
    }
    return x;
}

// displaying
void display()
{
    int i = q.front + 1;
    while ((q.rear + 1) % q.size != i)
    {
        printf("%d ", q.arr[i]);
        i = (i + 1) % q.size;
    }
    printf("\n");
}

int main()
{
    create(6);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    enqueue(4);
    enqueue(5);
    display();
    printf("deleted element is %d\n", dequeue());
    display();
    enqueue(6);
    enqueue(2);
    enqueue(8);
    display();
}