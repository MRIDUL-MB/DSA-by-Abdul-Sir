//!----------Binary Search ------!
//!----------Mridul bagla--------!

#include<stdio.h>

//Binary Search  :return index
int BinarySearch(int arr[], int n, int value)
{
	int l=0,h=n-1,m;
	while(l<=h)
	{
		m=l+(h-l)/2;
		if(arr[m]==value) return m;
		else if(arr[m] < value) l=m+1;
		else h=m-1;
	}
	return -1;
}

// In descending order
int BSdes(int arr[], int n, int value)
{
	int l=0,h=n-1,m;
	while(l<=h)
	{
		m=l+(h-l)/2;
		if(arr[m]==value) return m;
		else if(arr[m] > value) l=m+1;
		else h=m-1;
	}
	return -1;	
}



int main()
{
	int arr[]={1,3,5,6,7,9,12,15,18};
	int ARR[]={18,15,12,9,7,6,5,3,1};
	printf("%d\n", BinarySearch(arr,9,15));
	printf("%d\n", BSdes(ARR,9,3));
	return 0;
}