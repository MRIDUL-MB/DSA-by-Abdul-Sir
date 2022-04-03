#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node;

node *top = NULL;

void push(int value)
{
	node *t = (node*)malloc(sizeof(node));
	t->data=value;
	t->next=top;
	top=t;
}

int isEmpty()
{
	if(top==NULL) return 1;
	return 0;
}

int isFull()
{
	node *t=(node*)malloc(sizeof(node));
	if(t==NULL) return 1;
	return 0;
}

void display()
{
	printf("\nDisplaying...\n");
	node *p=top;
	while(p){
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}

void pop()
{
	if(isEmpty()) return;
	node *t=top;
	top=top->next;
	free(t);
}

int atTop()
{
	if(isEmpty()) return -1;
	return top->data;
}

void peek(int index)
{
	node *p=top;
	for(int i=0;i<index-1&&p;i++) p=p->next;
	if(p)printf("Element at index %d is %d\n",index,p->data);
	else printf("index out of range!");
}

int main()
{
	push(1);
	push(2);
	push(3);
	display();
//	pop();
//	pop();
//	pop();
//	pop();
//	display();
	printf("\nElement at Top: %d\n", atTop());
	printf("IsEmpty: %s\nIsFull: %s\n",isEmpty()?"yes":"no", isFull()?"yes":"no");
	peek(4);
}