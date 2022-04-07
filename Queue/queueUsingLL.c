#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
} queue;

queue *rear = NULL, *front = NULL;

void enqueue(int val)
{
    // if queue is full
    queue *t = (queue *)malloc(sizeof(queue));
    if (t == NULL)
        printf("queue is full\n");
    else
    {
        t->data = val;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        rear->next = t;
        rear = t;
        printf("%d is inserted\n", val);
    }
}
int dequeue()
{
    int x = -1;
    // if queue is empty
    // queue *t = (queue *)malloc(sizeof(queue));
    if (front == NULL)
        printf("queue is empty\n");
    else
    {
        queue *t = front;
        front = front->next;
        x = t->data;
        free(t);
    }
    return x;
}
void display()
{
    queue *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    enqueue(1);
    enqueue(2);
    display();
    printf("%d\n", dequeue());
    display();
    enqueue(3);
    enqueue(4);
    display();
}