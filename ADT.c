#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Array
{
	int *A;
	int size;
	int length;
}Array;

//display
void Display(Array arr)
{
	printf("Displaying all the elements\n");
	for(int i=0;i<arr.length;i++)
	{
	printf("%d\n",arr.A[i]);
	}
	printf("\n");
}

//Add/Append
void Add(Array *arr, int value)
{
	if(arr->length < arr->size){
	arr->A[arr->length] = value;
	arr->length ++;
	}else{
		printf("Sorry, index is out of range....\n");
	}

}

//Insert
void Insert(Array *arr, int index, int value)
{
	if(index <= arr->length){
		for(int i=arr->length ; i>index; i--){
			arr->A[i] = arr->A[i-1];			
		}
		arr->A[index] = value;
		arr->length ++;
		printf("Successfully, Inserted %d at index %d....\n", value, index);
	}else{
		printf("Sorry, index is out of range....\n");
	}
}

//Delete
void Delete(Array *arr, int index)
{
	if(index < arr->length){
		for(int i=index;i<arr->length-1;i++){
			arr->A[i] = arr->A[i+1];
		}
		arr->length --;
		printf("Sucessfully deleted node at index %d\n", index);
	}
	else{
		printf("Sorry, index is out of range....\n");
	}
}

//Linear Search
int LinearSearch(Array arr, int value){
	for(int i=0; i < arr.length; i++){
		if(arr.A[i] == value){
			return i;
		}

	}
		return -1;
}

//Swap
void swap(int* a, int *b){
	 int temp;
	 temp = *a;
	 *a = *b;
	 *b = temp;
}

//Linear Search with Transposition
int LinearSearchT(Array *arr, int value){
	for(int i=0; i < arr->length; i++){
		if(arr->A[i] == value){
			swap(&arr->A[i],&arr->A[i-1]); //A[i]  <-->  A[i-1]
			return i;
		}
	}
	return -1;
}

//Linear Search with Move to Front/Head
int LinearSearchM(Array *arr, int value){
	for(int i=0; i < arr->length; i++){
		if(arr->A[i] == value){
			swap(&arr->A[i],&arr->A[0]); //A[i]  <-->  A[0]
			return i;
		}
	}
	return -1;
}

//Binary Search
int BinarySearch(Array arr, int value){
	int l=0, h;
	h = arr.length - 1;

	while(l<=h){
		int m = (l+h)/2;
		if(arr.A[m] == value){
			return m;
		}
		else if(arr.A[m] > value){
			h= m-1;
		}	
		else{
			l=m+1;
		}
		
	}
	return -1;	
}

//Binary Search with recursion
int BinarySearchR(Array arr, int value,int h, int l){

	if(l<=h){
		int m = (l+h)/2;
		if(arr.A[m] == value){
			return m;
		}
		else if(arr.A[m] > value){
			return BinarySearchR(arr, value, m-1, l);
		}	
		else{
			return BinarySearchR(arr, value, h,m+1);
		}
	}
	return -1;	
}

//Reverse the Array
void Reverse(Array *A)
{
	int i,j;
	int* B = (int*)malloc(A->length*(sizeof(int)));
	for( i=0, j=A->length-1; i<A->length; i++ , j--)
	{
		B[j] = A->A[i];
	}
	for(int i=0;i < A->length;i++)
	{
		A->A[i] = B[i];
	}
}

//Reverse using swaping
void Reverse2(Array *A)
{
	int i,j,temp;
	for( i=0, j=A->length-1; i<j; i++ , j--)
	{
		temp = A->A[i];
		A->A[i] = A->A[j];
		A->A[j] = temp; 
	}
	
}

//isSorted 
bool isSorted(Array *arr)
{
	for(int i=0; i<arr->length - 1; i++)
	{
		if(arr->A[i] > arr->A[i+1] ) return false;
	}
	return true;
}

//-ve number to the left side
void Replace(Array *arr)
{
	int i=0,temp;
	int j = arr->length - 1;
	while(i<j)
	{
		while(arr->A[i] < 0) i++;
		while(arr->A[j] > 0) j--;
		if(i<j)
		{
			temp = arr->A[i];
			arr->A[i] = arr->A[j];	
			arr->A[j] = temp;	
		}
	}
}

//Merging
Array Merging(Array arr1, Array arr2)
   {
	int m = arr1.length, n=arr2.length,i=0,j=0,k=0;

	int *p= (int*)malloc((m+n)*sizeof(int));
	while(i<m && j<n)
	{	
		if(arr1.A[i] < arr2.A[j]){
			p[k++] = arr1.A[i++];
		}else{
			p[k++] = arr2.A[j++];
		}
	}
	while(i<m) p[k++] = arr1.A[i++];
	while(j<n) p[k++] = arr2.A[j++];
	
	Array arr3 = {p,k,k};
	
	return arr3;
}

//Union using merging
Array Union(Array arr1, Array arr2)
{
	int m = arr1.length, n=arr2.length,i=0,j=0,k=0;

	int *p= (int*)malloc((m+n)*sizeof(int));
	while(i<m && j<n)
	{	
		if(arr1.A[i] == arr2.A[j]){
			j++;
		}
		else if(arr1.A[i] < arr2.A[j]){
			p[k++] = arr1.A[i++];
		}else{
			p[k++] = arr2.A[j++];
		}
	}
	while(i<m) p[k++] = arr1.A[i++];
	while(j<n) p[k++] = arr2.A[j++];
	
	Array arr3 = {p,k,k};
	
	return arr3;
}

//Intersection using merging
Array Intersection(Array arr1, Array arr2)
{
	int m = arr1.length, n=arr2.length,i=0,j=0,k=0;

	int *p= (int*)malloc((m+n)*sizeof(int));
	while(i<m && j<n)
	{	
		if(arr1.A[i] == arr2.A[j]){
			p[k++] = arr1.A[i++];
			j++;
		} 
		if(arr1.A[i] < arr2.A[j]){
		i++;
		}else{
		j++;
		}
	}
	
	
	Array arr3 = {p,k,k};
	
	return arr3;
}

//Difference using merging
Array Difference(Array arr1, Array arr2)
{
	int m = arr1.length, n=arr2.length,i=0,j=0,k=0;

	int *p= (int*)malloc((m+n)*sizeof(int));
	while(i<m && j<n)
	{	
		if(arr1.A[i] == arr2.A[j]){
			i++,j++;
		}
		else if(arr1.A[i] < arr2.A[j]){
			p[k++] = arr1.A[i++];
		}else{
			j++;
		}
	}
	while(i<m) p[k++] = arr1.A[i++];
	
	Array arr3 = {p,k,k};
	
	return arr3;
}

//Missing elements...
void MissingElements(Array arr)
{
	int diff = arr.A[0];
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i] - i != diff)
		{
			while(diff+i<arr.A[i]){
			
			printf("Missing element is %d\n", diff+i);
			diff++;
			}
		
		}
	}
}


//Missing elements using hashing
void MissingElementsH(Array arr, int h, int l)
{
	int *p = (int *)malloc(h*sizeof(int));
	for(int i=0; i<h;i++)
	{
		p[i] = 0;
	}
	for(int i=0; i<arr.length; i++)
	{
		p[arr.A[i]]=1;
	}
	for(int i=l; i<h;i++)
	{
		if(p[i] == 0) printf("Missing elemenet is %d\n", i);
	}
}

//Duplicate elements
void DuplicateElements(Array arr)
{
	int check=0;
	for(int i=0;i<arr.length-1;i++)
	{
		if(arr.A[i]==arr.A[i++] && check != arr.A[i])
		{
			printf("%d\n", arr.A[i]);
			check=arr.A[i];
		}	
	}	
}

//Count the Duplicate elements
void CountDuplicate(Array arr)
{
	int j=0;
	for(int i=0;i<arr.length-1;i++)
	{
		if(arr.A[i]==arr.A[i+1])
		{
			j = i+1;
			while(arr.A[j] == arr.A[i]) j++;
			printf("%d is repeating %d times\n",arr.A[i], j-i);
			i = j-1;
		}
		
	}	
}

//Duplicate with  hashing
void DuplicateElementsH(Array arr, int h, int l)
{
	int *p = (int *)malloc(sizeof(int) * h);
	for(int i=0; i<=h; i++)
	{
		p[i] = 0;
	}
	for(int i=0; i<arr.length; i++)
	{
		p[arr.A[i]]++;
	}
	for(int i=l; i<=h;i++)
	{
		if(p[i] > 1)
		{
			printf("%d is repeating %d times\n", i,p[i]);
		}
	}
	
}

// find pair of element where a+b = k using hashing
void POE(Array arr, int h, int k)
{
	int *p = (int*)malloc(h*sizeof(int));
	for(int i=0;i<=h;i++)
	{
		p[i] = 0;
	}
	for(int i=0; i<arr.length; i++)
	{
		if(p[k-arr.A[i]] == 1)
		{
			printf("%d + %d = %d\n",arr.A[i],k-arr.A[i],k);
		}
		
		p[arr.A[i]]++;
	}
}

int main()
{
	Array arr;
	int n,i;
	printf("Size of an array: ");
	scanf("%d", &arr.size);
	arr.A = (int*)malloc(arr.size*sizeof(int));
	arr.length = 0;
	printf("Enter the length of the array: ");
	scanf("%d", &n);
	
	arr.length = n;
	printf("Enter all elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	printf("\n");

//	Add(&arr,40);
//	Insert(&arr,7,20);
//	Insert(&arr,40,20);
//	Delete(&arr, 5);
//	printf("%d\n", LinearSearch(arr, 5));
//	printf("%d\n", LinearSearchT(&arr, 5));
//	printf("%d\n", LinearSearchM(&arr, 5));
//	printf("at index %d\n", BinarySearch(arr, 41));
//	printf("at index %d\n", BinarySearchR(arr, 18, arr.length , 0));
//	Reverse(&arr);
//	Reverse2(&arr);
//	printf("%s\n", isSorted(&arr) ? "true" : "false");
//	Replace(&arr);
	
//	Merging, Union, Intersection and Difference
//	int A[] = {2,6,10,15,25} ,B[]={3,6,7,15,20};
//	int *p = A, *q = B;
//	Array arr1 = {p,5,5};
//	Array arr2 = {q,5,5};
//	Array arr3 = Intersection(arr1, arr2);  
	
//	MissingElements(arr);
//	MissingElementsH(arr,20,1);
//	DuplicateElements(arr);
//	CountDuplicate(arr);
//	DuplicateElementsH(arr, 10,3);
//	POE(arr,9,10);
	Display(arr);
	
	return 0;
} 