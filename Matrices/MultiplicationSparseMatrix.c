#include<stdio.h>
#include<stdlib.h>

typedef struct Element
{
	int r;
	int c;
	int e;
} element;

typedef struct Matrix
{
	int m;
	int n;
	int num;
	element *ele;
} matrix;

void create(matrix *s)
{
	printf("Enter the dimensions: ");
	scanf("%d%d", &s->m, &s->n);
	printf("Number of elements: ");
	scanf("%d", &s->num);
	s->ele = (element*)malloc(s->num*(sizeof(element)));
	printf("Enter elements\n");
	for(int i=0; i<s->num;i++)
	{
		scanf("%d %d %d", &s->ele[i].r, &s->ele[i].c, &s->ele[i].e);
	}
}

void display(matrix s)
{
	int k=0;
	for(int i=0;i<s.m;i++)
	{
		for(int j=0;j<s.n;j++)
		{
			if(i+1 == s.ele[k].r && j+1 == s.ele[k].c)
			{
				printf("%d ", s.ele[k++].e);
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(matrix *s)
{
	for(int i=0; i<s->num; i++)
	{
	for(int j=i+1; j<s->num; j++)
		{	
			if(s->ele[i].r > s->ele[j].r)
			{
				swap(&s->ele[i].r , &s->ele[j].r);
				swap(&s->ele[i].c , &s->ele[j].c);
				swap(&s->ele[i].e , &s->ele[j].e);
			}
			else if(s->ele[i].r == s->ele[j].r)
			{
				if(s->ele[i].c > s->ele[j].c){
				swap(&s->ele[i].c , &s->ele[j].c);
				swap(&s->ele[i].e , &s->ele[j].e);
				}
			 
			}
		}
	}
	
}

void transpose(matrix *s)
{
	int temp=0;
	for(int i=0;i<s->num;i++)
	{
		swap(&s->ele[i].r , &s->ele[i].c);
	}
	swap(&s->m, &s->n);
	sort(s);

}

matrix * multiplication(matrix *s1, matrix *s2)
{
	if(s1->n == s2->m)
	{
		matrix *s;
		transpose(s2);
		s = (matrix *)malloc(sizeof(matrix));
		s->ele = (element *)malloc((s1->num + s2->num)*sizeof(element));
		s->m=s1->m; s->n=s2->m;
		int k=0;
		for(int i=0; i<s1->num; i++)
		{
			for(int j=0; j<s2->num; j++)
			{
				if(s1->ele[i].c == s2->ele[j].c)
				{
					s->ele[k].r = s1->ele[i].r;
					s->ele[k].c = s2->ele[j].r;
					s->ele[k++].e = s1->ele[i].e * s2->ele[j].e; 	
				} 	
			}	
		}
		s->num = k;
		sort(s);
		for(int i=0;i<s->num-1;i++)
		{
			if(s->ele[i].r == s->ele[i+1].r && s->ele[i].c == s->ele[i+1].c)
			{
				s->ele[i].e += s->ele[i+1].e;
				for(int k=i+1;k<s->num;k++)
				{
					s->ele[k] = s->ele[k+1];
				}
				s->num--;
			}
		}
		return s;	
			
	}else return NULL;
	
}


int main()
{
	printf("\t\t\t....Multiplication of Sparse Matrix....\n\n");
	matrix s1, s2, *s;
	printf("Matrix 1\n");
	create(&s1);
	printf("Matrix 2\n");
	create(&s2);
	printf("\n");
	printf("1st Matrix\n"); display(s1);printf("\n");
	printf("2nd Matrix\n"); display(s2);printf("\n");
	s = multiplication(&s1, &s2);
	printf("Resultant matrix\n") ;display(*s);
}