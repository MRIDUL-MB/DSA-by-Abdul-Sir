#include<stdio.h>
#include<stdlib.h>

typedef struct Element
{
	int i;
	int j;
	int x;
} element;

typedef struct SparseMatrix
{
	int m;
	int n;
	int e;
	element *ele;
} sparse;

void create(sparse *s)
{
	printf("Enter the dimensions: ");
	scanf("%d%d", &s->m, &s->n);
	printf("eleber of non-zeros element: ");
	scanf("%d", &s->e);
	s->ele = (element*)malloc(s->e * sizeof(element));
	printf("Enter the elements\n");
	for(int index=0; index<s->e; index++)
	{
		scanf("%d%d%d", &s->ele[index].i, &s->ele[index].j, &s->ele[index].x);
	}
}

void display(sparse s)
{

	int k=0;
	for(int i=0; i<s.m; i++)
	{
		for(int j=0; j<s.n; j++)
		{
			if(i==s.ele[k].i && j==s.ele[k].j)
			{
				printf("%d  ", s.ele[k++].x);
			}else{
				printf("0  ");
			}
		}
		printf("\n");
	}
}

sparse* add(sparse *A, sparse *B)
{
	
	int i=0,j=0,k=0;
	sparse *sum;
	sum = (sparse *) malloc (sizeof(sparse));
	sum->ele = (element *) malloc ((A->e + B->e)*sizeof(element));
	if (A->m != B->m || A->n != B->n) return NULL;
	else{
		sum->m = A->m; sum->n = A->n;
		while( i< A->e &&  j< B->e)
		{
			if(A->ele[i].i == B->ele[j].i)
			{
				if(A->ele[i].j == B->ele[j].j )
				{
					sum->ele[k].i = A->ele[i].i;
					sum->ele[k].j = A->ele[i].j;
					sum->ele[k++].x = A->ele[i++].x + B->ele[j++].x;
				}else if (A->ele[i].j < B->ele[j].j)
				{
					sum->ele[k++] = A->ele[i++];
				}else{
					sum->ele[k++] = B->ele[j++];
				}
			} else if (A->ele[i].i < B->ele[j].i)
			{
					sum->ele[k++] = A->ele[i++];	
			} else{
					sum->ele[k++] = B->ele[j++];
			}
		}
		while (i < A->e ){
			sum->ele[k++] = A->ele[i++];
		}
		while (j < B->e){
			sum->ele[k++] = B->ele[j++];
		}
		 sum->e = k;
		 return sum;
	}
}



int main()
{
	sparse s1,s2;
	create(&s1);
	display(s1);
	create(&s2);
	display(s2);
	sparse *s = add(&s1,&s2);
	printf("\n");
	display(*s);
}