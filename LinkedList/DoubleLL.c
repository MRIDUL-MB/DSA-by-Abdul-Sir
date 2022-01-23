#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
} node;

node *head = NULL;

void create(int arr[], int size)
{
	head = (node*)malloc(sizeof(node));
	head->prev=NULL;
	head->data=arr[0];
	head->next=NULL;
	node *last=head;
	for(int i=1; i<size;i++)
	{
		node *t=(node*)malloc(sizeof(node));
		t->data=arr[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
	
}

void display()
{
	node *p=head;
	while(p)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}

int length(){
	node*p=head;
	int i=0;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

void insert(int index, int value)
{
	node *p=head;
	node *t=(node*)malloc(sizeof(node));
	t->data=value;
	if(index<0 || index>length()) return;
	else if(index==0){
		t->next=head;
		t->prev=NULL;
		head->prev=t;
		head=t;
	}else{
		for(int i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t->prev=p;
		t->next=p->next;
		if(p->next) p->next->prev=t;
		p->next=t;
	}
}

void del(int index)
{
	node *t=(node*)malloc(sizeof(node));
	node *p=head;
	if(index<0 || index>=length()) return;
	else if(index == 0){
		t=head->next;
		free(head);
		head=t;
	}else{
		for(int i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t=p->next;
		p->next=t->next;
		if(p->next)
		{
		t->next->prev=p;
		}
		free(t);
	}
}

void reverse()
{
	node *p=head, *t=NULL;
	while(p)
	{	
		t=p->next;
		p->next=p->prev;
		p->prev=t;           
		p=p->prev;
		if(p && p->next==NULL)head=p;
		
	}	
}

int main()
{
	int arr[] = {1,2,3,4,5};
	create(arr, 5);
	display();
	
//	printf("length is %d\n", length());
//	insert(5,20);
//	del(4);
	reverse();
	
	display();
}