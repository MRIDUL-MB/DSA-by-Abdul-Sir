#include<stdio.h>

typedef struct SparseMatrix
{
	int r;
	int c;
	int e;	
} sparse;

void add(sparse A[], sparse B[])
{
	int i=1,j=1,k=1;
	sparse C[A[0].e + B[0].e];
	C[0].r = A[0].r; C[0].c = A[0].c;
	while( i<=A[0].e && j<=B[0].e)
	{
		if(A[i].r == B[j].r)
		{
			if(A[i].c == B[j].c )
			{
				C[k].r = A[i].r;
				C[k].c = A[i].c;
				C[k++].e = A[i++].e + B[j++].e;
			}else if (A[i].c < B[j].c)
			{
				C[k].r = A[i].r;
				C[k].c = A[i].c;
				C[k++].e = A[i++].e;
			}else{
				C[k].r = B[j].r;
				C[k].c = B[j].c;
				C[k++].e = B[j++].e;
			}
		} else if (A[i].r < B[j].r)
		{
			C[k].r = A[i].r;
			C[k].c = A[i].c;
			C[k++].e = A[i++].e;	
		} else{
				C[k].r = B[j].r;
				C[k].c = B[j].c;
				C[k++].e = B[j++].e;
		}
	}
	while (i <= A[0].e ){
		C[k].r = A[i].r;
		C[k].c = A[i].c;
		C[k++].e = A[i++].e;
	}
	while (j <= B[0].e ){
		C[k].r = B[j].r;
		C[k].c = B[j].c;
		C[k++].e = B[j++].e;
	}
	C[0].e = k-1;
	 for(int i=0; i<=k-1 ; i++)
	{
		printf("%d %d %d\n", C[i].r, C[i].c, C[i].e);		
	}
	 
}

int main()
{
	
	sparse a[] = {{5,6,5},{1,4,6},{2,2,7},{3,2,2},{3,4,5},{5,2,4}};
	sparse b[] = {{5,6,6},{2,2,3},{2,5,5},{3,3,2},{3,6,5},{4,4,9},{5,2,8}};

	add(a,b);
	
	
}