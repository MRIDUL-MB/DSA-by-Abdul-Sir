#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
	int data;
	struct Node *next;
} *head=NULL, *first=NULL, *last=NULL,*third=NULL;



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

//Searching
struct Node * Search(struct Node *p, int key )
{
	while(p)
	{
		if(p->data == key) return p;
		p=p->next;
	}
	return NULL;
}

//Searching Recursive
struct Node * SearchR(struct Node *p, int key )
{
	if(!p) return NULL;
	if(p->data == key) return p;
	return SearchR(p->next, key);
}

//Searching with move to head
struct Node * MTH(struct Node *p, int key)
{
	struct Node *q=NULL;
	while(p)
	{
		if(p->data == key)
		{
			q->next = p->next;
			p->next = head;
			head = p;
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

//Searching with transposition
struct Node * trans(struct Node *p, int key)
{
	struct Node *q=NULL;
	while(p)
	{
		if(p->data == key)
		{
			int t = p->data;
			p->data = q->data;
			q->data = t;
			return q;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

//Insertion
void Insert(struct Node *p, int index, int value)
{
	struct Node *t;
	t = (struct Node *) malloc (sizeof(struct Node));
	t->data=value;
	if(index == 0)
	{
		t->next = p;
		head = t;
	}
	else if(index>0)
	{
		for(int i=0; i< index-1 && p; i++)
		{
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
}

//insert at the end
void InsertLast(int x)
{
	struct Node *t = (struct Node *)malloc(sizeof(struct Node)); 
	t->data=x;
	t->next=NULL;
	if(first == NULL)
	{
		first=(struct Node *)malloc(sizeof(struct Node));
		first=last=t;
		last->next=NULL;
	}else{
		last->next=t;
		last=t;
	
	}
}

// sorted insert
void SortInsert(struct Node *p, int x)
{
	struct Node *t= (struct Node*)malloc(sizeof(struct Node*));
	t->data=x;
	t->next=NULL;
 	
	while(p && x > p->next->data)
	{
		p=p->next;
	}
	if(x < p->data)
	{
		t->next = head;
		head=t;
	}
	else
	{
	
	t->next=p->next;
	p->next=t;
	}
	

}

//delete node
int Delete(struct Node *p, int index)
{
	struct Node *t, *q;
	int data=-1;
	if(index==1)
	{
		t=head;
		data = head->data;
		head=t->next;
		free(first);
	}else{
		t=head; q=NULL;
		for(int i=0; i<index-1&&p;i++){
			q=t;
		    t=t->next;
		 }
		if(p){ 	
			data = t->data;
			q->next = t->next;
			free(t);
		}
	}
	return data;
} 

//isSorted
int isSorted(struct Node *p)
{
	int x=INT_MIN;
	while(p)
	{
		if(x>p->data) return 0;
		x=p->data;
		p=p->next;
	}
	return 1;
}

//remove duplicate with sorted list
void removeDup(struct Node *p)
{
	if(isSorted(p))
	{
		struct Node *q=p;
		p=p->next;
		while(p)
		{
			
			if(q->data != p->data)
			{
			q=p;
			p=p->next; 
			}
			else
			{
				q->next=p->next;
				free(p);
				p=q->next;
			}	
		}
	}else{
		printf("List is not sorted\n");
	}
}

//reverse a linked list by elements using array
void reverseArr(struct Node *p, int n)
{
	int *arr = (int *)malloc(sizeof(int)*n);
	for(int i=n-1;i>=0;i--)
	{
		arr[i]=p->data;
		p=p->next;
	}
	p=head;
	for(int i=0;i<n;i++)
	{
		p->data=arr[i];  
		p=p->next;
	}
}

// reverse LL through links:- sliding pointers
void reversePointers(struct Node *p)
{
	struct Node *q=NULL, *r=NULL;
	while(p)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	head=q;

}

// reverse with recursion
void reverseR(struct Node *q, struct Node *p)
{
	if(p){
		reverseR(p,p->next);
		p->next = q;
	}else{
		head = q;
	}
}

//concatenating.........
void Concatenate(struct Node *p, struct Node *q)
{
	while(p->next)
	{
		p=p->next;
	}
	p->next=q;
}

//Merging
void Merging(struct Node *p, struct Node *q)
{

	if(p->data < q->data) 
	{
		third=last=p;
		p=p->next;
		last->next=NULL;
	}
	else 
	{
		third=last=q;
		p=p->next;
		last->next=NULL;
	};

	while(p && q)
	{
		if(p->data < q->data)
		{
			last->next=p;
			last=p;
			p=p->next;
			last->next = NULL;
			
		}else{
			last->next=q;
			last=q;
			q=q->next;
			last->next = NULL;
		}
	}
	if(p){
		last->next=p;
	}
	else{
		last->next=q;
	}
}

void makeCircularList(struct Node *p)
{
	struct Node *t = p;
	while(p->next) p=p->next;
	p->next=t;
	
}

void checkCircular(struct Node *p)
{
	struct Node *q=p;
	int i=10;
	do{
		p=p->next;
		q=q->next;
		q=q?q->next:NULL;
	}while(p&&q&&p!=q);
	if(p==q) printf("It's circular");
	else printf("It's not circular");
	
//	while(p&&q)
//	{
//		p=p->next;
//		q=q->next->next;
//		if(q == p){
//			printf("it's circular");
//			return;
//		}
//	}
//	printf("it's not circular");
	
}

int main()
{
	int arr[]={2,8,10,12};
	int n=4;
	create(arr,n);
	InsertLast(4);
	InsertLast(17);
	InsertLast(122);
	InsertLast(144);
	display(head);
//	display(first);

	
//	displayR(head);
//	int len = length(head); 
//	printf("Length of LL is %d", len);printf("\n");
//	printf("Length of LL is %d", lengthR(head));printf("\n");
//	printf("Sum of LL is %d", Sum(head));printf("\n");
//	printf("Sum of LL is %d", SumR(head));printf("\n");
//	printf("Max element is %d", Max(head));printf("\n");
//	printf("Max element is %d", MaxR(head));printf("\n");
//	printf("Min element is %d", Min(head));printf("\n");
//	printf("Min element is %d", MinR(head));printf("\n");
//	printf("Address of key element is %d", Search(head, 7));printf("\n");
//	printf("Address of key element is %d", SearchR(head, 17));printf("\n");
//	printf("Address of key element is %d", MTH(head, 17));printf("\n");
//	printf("Address of key element is %d", trans(head, 17));printf("\n");
//  Insert(head, 40,99);
//	InsertLast(1);
//	InsertLast(4);
//	InsertLast(6);
//	InsertLast(8);
//	InsertLast(12);
//	SortInsert(head, 0);
//	SortInsert(head, 1);
//	SortInsert(head, 2);
//	printf("Deleted element is %d\n",Delete(head,3));
//	printf("Is it sorted?:- %s\n", isSorted(head)?"true":"false");
//	removeDup(head);
//	reverseArr(head,n);
//	reversePointers(head);
//	reverseR(NULL,head);
//	Concatenate(head,first);
//	Merging(head,first);
//	makeCircularList(head);
//	checkCircular(head);

	display(head);
}