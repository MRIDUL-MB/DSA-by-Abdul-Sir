#include<iostream>
using namespace std;

//Swap
template<typename T>
void Swap(T*x, T*y){
	T temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

template<class T>
class Array
{
	private:
	T* A;
	int size;
	int length;
	
	public:
	//constructor
	Array(int size){
		this->size = size;
		A = new T[size];
	}
	
	//create
	void create(){
		cout<<"Enter the length of the Array: "<<flush;
		cin >> length;
		cout << "Enter all the elements"<<endl;
		for(int i=0; i<length; i++){
			cin>>A[i];
		}
	}
	
	//display
	void display(){
		cout << "Displaying all the elements"<<endl;
		for(int i=0; i<length; i++){
			cout<<A[i]<<endl;
		}
	}
	
	//Add or Append
	void add(T value){
		if(length<size){
			A[length] = value;
			length ++;
			cout<<"Sucessfully added!"<<endl;
		}else{
			cout<<"Sorry, index is out of range"<<endl;
		}
	}
	
	//Insert
	void insert(int index, T value){
		if(length<size){
			if(index <= length){
				for(int i=length;i>index;i--){
					A[i] = A[i-1];
				}}
				A[index] = value;
				length ++;
				cout<<"Sucessfully, inserted "<<value<<" at index "<<index<<endl;
			}else{
					cout<<"Sorry, index is out of range"<<endl;
			}
		}
	
	//Delete
	void Delete(int index){
	if(index<length){
		for(int i=index;i<length;i++){
			A[i] = A[i+1];
		}
		length --;
		cout<<"Sucessfully, deleted at index "<<index<<endl;
	}else{
		cout<<"Sorry, index is out of range"<<endl;
		}
	}
	
	//Linear Search
	void LinearSearch(T value){
		for(int i=0;i<length;i++){
			if(A[i]==value){
			cout << value << " at index " << i << endl;
			break;
			}
		}
		
	}
	
	
	//Linear Search with Transposition
	void LinearSearchT(T value){
		for(int i=0;i<length;i++){
			if(A[i]==value){
			Swap(&A[i], &A[i-1]);
			cout << value << " at index " << i << endl;
			break;
			}
		}
		
	}
	
	//Linear Search with Move to frond/head
	void LinearSearchM(T value){
		for(int i=0;i<length;i++){
			if(A[i]==value){
			Swap(&A[i], &A[0]);
			cout << value << " at index " << i << endl;
			break;
			}
		}
		
	}
	
	//Binary Search
	int BinarySearch(T value){
		int l=0, h=length-1, m=0;
		while(l<=h){
			m = (l+h)/2;
			if(A[m] == value){
				return m;
			}else if(A[m] > value ){
				h = m-1;
			}else{
				l = m+1;
			}
		}
		return -1;
	}
	
	//Reverse the array
	void Reverse()
	{
		int i,j;
		int* B = new T[size];
		for(i=0, j=length-1; i<length ; i++ , j--)
		{
			B[i] = A[j];
		}
		for(i=0;i<length;i++)
		{
			A[i] = B[i];
		}
	}
	
	//Reverse the array by swapping
	void Reverse2()
	{
		int i,j,temp;
		for(i=0, j=length-1; i<j ; i++ , j--)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		
	}
	
	//isSorted 
	bool isSorted()
	{
		for(int i=0; i<length - 1; i++)
		{
			if(A[i] > A[i+1] ) return false;
		}
		return true;
	}
	
	//-ve number to the left side
	void Replace()
	{
	int i=0,temp;
	int j = length - 1;
	while(i<j)
	{
		while(A[i] < 0) i++;
		while(A[j] > 0) j--;
		if(i<j)
		{
			temp = A[i];
			A[i] = A[j];	
			A[j] = temp;	
		}
	}
}
	
	//destructor
	~Array(){
		delete []A;
		cout << "Array Destroyed"<<endl;
	}
};


int main()
{
	Array<char> arr(20);
	arr.create();
//	arr.add(20);
//	arr.insert(7,40);
//	arr.Delete(4);
// 	arr.LinearSearch('e');
// 	arr.LinearSearchT(5);
// 	arr.LinearSearchM('o');
// 	cout << arr.BinarySearch(118)<<endl;
//	arr.Reverse();
//	arr.Reverse2();
//	printf("%s\n", arr.isSorted() ? "true" : "false");
//	arr.Replace();
	arr.display();
}