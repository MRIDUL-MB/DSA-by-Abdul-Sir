#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
} node;
node *head=NULL;


void create(int arr[], int size)
{
	node *last=NULL;
	head=(node*)malloc(sizeof(node));
	head->data=arr[0];
	head->next=head->prev=head;
	last=head;
	for(int i=1;i<size;i++)
	{
		node *temp=(node*)malloc(sizeof(node));
		temp->data=arr[i];
		temp->next=last->next;
		temp->prev=last;
		last->next=temp;
		last=temp;
	}
	head->prev=last;
}

void display()
{
	if(head==NULL)
	{
		printf("NULL\n");
		return;
	}
	node *p=head;
	do{
		printf("%d ", p->data);
		p=p->next;
	}while(p!=head);
	printf("\n");
}

void displayReverse()
{
	node *p=head->prev;
	while(p!=head)
	{
		printf("%d ",p->data);
		p=p->prev;
	}
	printf("%d", p->data);
}

int length()
{
	if(head==NULL) return 1;
	int count=0;
	node *p=head;
	do{
		count++;
		p=p->next;
	}while(p!=head);
	
	return count;
	
}

void insert(int index, int value)
{
	if(index<0 || index>length()) return;
	node *temp=(node*)malloc(sizeof(node));
	temp->data=value;
	if(index == 0)
	{
		if(head==NULL)
		{
			temp->prev=temp->next=temp;
			head=temp;
			return;
		}
		temp->next=head;
		temp->prev=head->prev;
		head->prev->next=temp;
		head->prev=temp;
		head=temp;
	}else{
		node *p=head;
		for(int i=0;i<index-1;i++)p=p->next;
		temp->prev=p;
		temp->next=p->next;
		temp->next->prev=temp;
		p->next=temp;
	}
}


void del(int index)
{
	if(index<0||index>=length()) return;
	node *t=(node *)malloc(sizeof(node));
	if(index==0)
	{
		if(head==NULL) return;
		t=head;
		head->prev->next=head->next;
		head->next->prev=head->prev;
		head=head->next;
		free(t);
	}else{
		node *p=head;
		for(int i=0;i<index-1;i++)p=p->next;
		t=p->next;
		p->next=p->next->next;
		p->next->prev=p;
		free(t);
		
	}
}

int main(){
	int arr[]={1,2,3,4,5};
	create(arr,5);
	display();
	
//	displayReverse();
//	insert(0,30);
//	insert(1,30);
//	insert(2,30);
//	insert(3,30);
//	del(0);
//	del(3);
//	del(0);
	
	display();
}