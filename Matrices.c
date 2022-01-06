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
void display(Matrix m)
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

int main()
{
	Matrix M;
//	int size;
//	printf("Enter the dimension: ");
//	scanf("%d", &size);
	M.dim = 4;
//	M.A = (int *)malloc(M.dim*sizeof(int));
	
	setDiagonal(&M,1,1,5);setDiagonal(&M,2,2,6);setDiagonal(&M,3,3,7);setDiagonal(&M,4,4,8);
	getDiagonal(M,4,4);
	display(M);
	

}