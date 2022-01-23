#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} node; 
node *head=NULL, *last=NULL;

//creating circular list
void create(int *arr, int n) 
{
	head=(node*)malloc(sizeof(node));
	head->data=arr[0];
	head->next=head;
	last = head;
	
	for(int i=1;i<n;i++)
	{
		node *t = (node*)malloc(sizeof(node));
		t->data = arr[i];
		t->next = last->next;
		last->next = t;
		last=t;
	}
}

// creating with own logic
void create1(int *arr, int n) 
{
	head=(node*)malloc(sizeof(node));
	head->data=arr[0];
	head->next=NULL;
	last = head;
	
	for(int i=1;i<n;i++)
	{
		node *t = (node*)malloc(sizeof(node));
		t->data = arr[i];
		t->next = NULL;
		last->next = t;
		last=t;
	}
	last->next = head;
}


//Displaying the ll
void display(node *p)
{
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=head);
}

//Display using Recursion
void displayR(node *p)
{
	static int flag=0;
	if(p!=head || flag==0)
	{
		flag=1;
		printf("%d ",p->data);
		displayR(p->next);
	}
	flag=0;
}
//length
int length()
{
	node *p=head;
	int len=0;
	do{
		len++;
		p=p->next;
	}while(p!=head);
	return len;
}

//inserting
void insert(int index, int value)
{
	node *t = (node*)malloc(sizeof(node)), *p=head;
	t->data=value;
	if(index<0 || index > length()) return;
	if(index==0)
	{
		t->next=head;
		if(head == NULL)
		{
			head=t;
			head->next=head;
		}
		else{
		
		while(p->next!=head)p=p->next;	
		p->next=t;
		head=t;
		}		
	}else{
		for(int i=0;i<index-1;i++) 
		{
			p=p->next;
		}	
		t->next=p->next;	
		p->next=t;
	}
}

int del(int index)
{
	node *p=head;
	node *t=(node*)malloc(sizeof(node));
	int x;
	if(index<0 || index >= length()) return -1;
	if(index == 0)
	{
		x=head->data;
		while(p->next != head) p=p->next;
		if(p == head){
			free(head);
			head = NULL;
			return x;
		}
		p->next=head->next;
		free(head);
		head=p->next;
		return x;
	}else{
		for(int i=0;i<index-1;i++) p=p->next;
		t=p->next;
		x=t->data;
		p->next=t->next;
		free(t);
		return x;
	}
}

int main()
{
	int arr[]={1};
	create(arr,1);
	display(head);
	printf("\n");
	
//	displayR(head);
//	insert(6,44);
	printf("deleted item %d",del(0));printf("\n");
	
	display(head);

}
