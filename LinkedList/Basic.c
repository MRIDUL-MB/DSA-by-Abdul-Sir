#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
	int data;
	struct Node *next;
} *head=NULL;

//create : copying the data of array into ll
void create(int arr[], int n)
{
	struct Node *last,*t;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->data=arr[0];
	head->next=NULL;
	last = head	;
	
	
	for(int i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=arr[i];
		t->next = NULL;
		last->next = t;
		last=t;	
	}
}

//display
void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}

//display recursive
void displayR(struct Node *p){
	if(p != NULL)
	{
		displayR(p->next);
		printf("%d ",p->data );
	}
}

//length
int length(struct Node *p)
{
	int count=0;
	while(p)
	{
		count += 1;
		p=p->next;
	}
	return count;
}

//lenght recursive
int lengthR(struct Node *p)
{
	if(!p) return 0;
	return lengthR(p->next)+1;
}

//Sum
int Sum(struct Node *p)
{
	int s=0;
	while(p)
	{
		s+=p->data;
		p=p->next;
	}
	return s;
}

//Sum with Recursive
int SumR(struct Node *p)
{
	if(!p) return 0;
	return SumR(p->next) + p->data;
}

//Max
int Max(struct Node *p)
{
	int max= head->data;
	while(p)
	{
		if(p->data > max) max = p->data;
		p=p->next;
	}
	return max;
}

//Max with recursion
int MaxR(struct Node *p)
{
	int x=0;
	if(!p) return INT_MIN;
	else {
		x=MaxR(p->next);
		return x>p->data?x:p->data;
	}
}

//Min
int Min(struct Node *p)
{
	int min= INT_MAX;
	while(p)
	{
		if(min > p->data) min = p->data;
		p=p->next;
	}
	return min;
}

//Min with recursive
int MinR(struct Node *p)
{
	int x;
	if(!p) return INT_MAX;
	else{
		x = MinR(p->next);
		return x>p->data?p->data:x;
	}
}

int main()
{
	int arr[]={1,2,3,4,-5,4,3,17,2,5,6,4,9};
	create(arr,13);
	display(head);
//	displayR(head);
//	int len = length(head); 
//	printf("Length of LL is %d", len);printf("\n");
	printf("Length of LL is %d", lengthR(head));printf("\n");
//	printf("Sum of LL is %d", Sum(head));printf("\n");
	printf("Sum of LL is %d", SumR(head));printf("\n");
//	printf("Max element is %d", Max(head));printf("\n");
	printf("Max element is %d", MaxR(head));printf("\n");
//	printf("Max element is %d", Min(head));printf("\n");
	printf("Max element is %d", MinR(head));printf("\n");
}