#include<stdio.h>
#include<stdlib.h>

typedef struct Matrix{
	int *A;
	int dim;
}Matrix;

// Diagonal Matrix
void setDiagonal(Matrix *m, int i, int j, int x)
{
	if(i==j)
	{
		m->A[i-1] = x;
	}
}
void getDiagonal(Matrix m, int i, int j)
{
	if(i==j)
	{
		printf("%d\n", m.A[i-1]);
	}else{
		printf("0");
	}
}
void displayDiagonal(Matrix m)
{
	int i, j;
	for(i=0;i<m.dim;i++)
	{
		for(j=0;j<m.dim;j++)
		{
			if(i==j)
			{
				printf("%d ", m.A[i]);
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

//Lower triangle Matrix
void setLower(Matrix *m, int i, int j, int k)
{
	int result = i*(i-1)/2 + j - 1;
	if(i>=j)
	{
		m->A[result] = k;
	}
}
void getLower(Matrix m, int i, int j)
{
	if(i>= j)
	{
		int result = m.A[i*(i-1)/2 + j - 1];
		printf("%d\n", result);
	}
}
void displayLower(Matrix m)
{
	int i, j;
	for(i=1;i<=m.dim;i++)
	{
		for(j=1;j<=m.dim;j++)
		{
			if(i>=j)
			{
				int result = m.A[i*(i-1)/2 + j - 1];
				printf("%d ", result);
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
 
//Upper triangle Matrix
void setUpper(Matrix *m, int i, int j, int k)
{
	int result = j*(j-1)/2 + i - 1;
	if(j>=i)
	{
		m->A[result] = k;
	}
}
void getUpper(Matrix m, int i, int j)
{
	if(j>= i)
	{
		int result = m.A[j*(j-1)/2 + i - 1];
		printf("%d\n", result);
	}
}
void displayUpper(Matrix m)
{
	int i, j;
	for(i=1;i<=m.dim;i++)
	{
		for(j=1;j<=m.dim;j++)
		{
			if(j>=i)
			{
				int result = m.A[j*(j-1)/2 + i - 1];
				printf("%d ", result);
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
 
//Symmetric Matrix
void setSym(Matrix *m, int i, int j, int k)
{
	m->A[i*(i-1)/2 + j-1] = k;
//	m->A[j*(j-1)/2+ i-1] = k;
	
}
void getSym(Matrix m, int i, int j)
{
	printf("%d", m.A[i*(i-1)/2+j-1]);
}
void displaySym(Matrix m)
{
	int i, j;
	for(i=1;i<=m.dim;i++)
	{
		for(j=1;j<=m.dim;j++)
		{
			if(i>=j) printf("%d ", m.A[i*(i-1)/2 + j-1]);
			else if(j>=1) printf("%d ", m.A[j*(j-1)/2 + i-1]);
			else printf("0 ");
		
		}
		printf("\n");
	}
	
}


int main()
{
	Matrix M;
//	int size;
//	printf("Enter the dimension: ");
//	scanf("%d", &size);
	M.dim = 5;
	
	int size = (M.dim)*(M.dim + 1)/2;
	M.A = (int *)malloc(size*sizeof(int));
	for(int i=0; i<size; i++)
	{
		M.A[i] = 0;
	}
	
//	setDiagonal(&M,1,1,5);setDiagonal(&M,2,2,6);setDiagonal(&M,3,3,7);setDiagonal(&M,4,4,8);
//	getDiagonal(M,4,4);
//	displayDiagonal(M);
	
//	setLower(&M,1,1,5);setLower(&M,3,2,3);setLower(&M,4,3,7);setLower(&M,5,5,10);
//	setLower(&M,0,1,4);
//	displayLower(M);

//	setUpper(&M,1,1,5);setUpper(&M,2,3,3);setUpper(&M,3,4,7);setUpper(&M,5,5,10);
//	setUpper(&M,3,5,4);
//	displayUpper(M);

	setSym(&M,1,1,2);setSym(&M,2,1,3);setSym(&M,3,1,4);setSym(&M,4,1,5);
	setSym(&M,5,4,9);setSym(&M,4,3,8);setSym(&M,3,2,7);setSym(&M,5,1,6);
	displaySym(M);
}