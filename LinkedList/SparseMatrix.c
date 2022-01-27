#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int row;
	int col;
	int data;
	struct Node *next;
} node;

typedef struct Matrix{
	int m;
	int n;
	int size;
	struct Node *arr;
} matrix;

matrix* create(){
	matrix* mat=(matrix*)malloc(sizeof(matrix));
	int size;
	printf("Enter the dimensions: ");
	scanf("%d%d",&mat->m,&mat->n);
	printf("Enter the size: ");
	scanf("%d", &mat->size);
	node *arr=NULL, *last=NULL;
	printf("Enter the elements\n");
	for(int i=0;i<mat->size;i++)
	{
		int r,c,x;
		printf("\nEnter the row, column and value: ");
		scanf("%d%d%d",&r,&c,&x);
		if(arr==NULL)
		{
			arr=(node*)malloc(sizeof(node));
			arr->row=r;
			arr->col=c;
			arr->data=x;
			arr->next=NULL;
			last=arr;
		}else{
			node *t=(node*)malloc(sizeof(node));
			t->row=r;
			t->col=c;
			t->data=x;
			t->next=NULL;
			last->next=t;
			last=t;
	
		}
	}
	printf("\n");
	mat->arr = arr;
	return mat;
}

void display(matrix *mat)
{
	node *p=mat->arr;
	for(int i=0;i<mat->m;i++)
	{
		for(int j=0;j<mat->n;j++)
		{
			if(p && p->row == i && p->col == j)
			{
				printf("%d ",p->data);
				p=p->next;
				
			}else{
				printf("0 ");	
			}
		}
		printf("\n");
	}
	printf("\n");
}


matrix* add(matrix *mat1, matrix *mat2)
{
	node *arr =(node*)malloc(sizeof(node)),*last=NULL;
	arr->next=NULL;
	last=arr;
	int c=0;
	
	for(int i=0;i<(mat1->size+mat2->size);i++)
	{
		node *t=(node*)malloc(sizeof(node));
		t->next=NULL;
		last->next=t;
		last=t;
	}
	node *t=arr;
	node *p=mat1->arr, *q=mat2->arr;
	while(p&&q)
	{
		c++;
		if(p->row==q->row && p->col==q->col)
		{
			t->row=p->row;
			t->col=p->col;
			t->data=p->data + q->data;
			p=p->next;q=q->next;t=t->next;
			
		}else if(p->row == q->row)
		{
			if(p->col<q->col)
			{
				t->row=p->row;
				t->col=p->col;
				t->data=p->data; 
				p=p->next;t=t->next;
			}else{
				t->row=q->row;
				t->col=q->col;
				t->data=q->data; 
				q=q->next;t=t->next;
			}
		}else if(p->row<q->row)
		{
			t->row=p->row;
			t->col=p->col;
			t->data=p->data; 
			p=p->next;t=t->next;
		}else{
			t->row=q->row;
			t->col=q->col;
			t->data=q->data; 
			q=q->next;t=t->next;
		}
	}
	while(p)
	{
		c++;
		t->row=p->row;
		t->col=p->col;
		t->data=p->data; 
		p=p->next;t=t->next;
	}
	while(q)
	{
		c++;
		t->row=q->row;
		t->col=q->col;
		t->data=q->data; 
		q=q->next;t=t->next;
	}
	t->next=NULL;
	matrix *mat=(matrix*)malloc(sizeof(matrix));
	mat->arr=arr;
	mat->size=c;
	mat->m=mat1->m;
	mat->n=mat1->n;
	
	return mat;
}


int main(){
	
	matrix* mat1=create();
	display(mat1);
	matrix* mat2=create();
	display(mat2);
	
	matrix* mat3=add(mat1,mat2);
	display(mat3);
	
}