#include<iostream>
using namespace std;



// reverse
void reverse(char a[]){
	

	int i=0,j=0;
	char temp;
	for(;a[j]!='\0';j++);
	j = j-1;
	int count=0;
	for(;i<j;i++,j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		if (a[i] != a[j]) count ++;
	}
	printf("%s\n", a);
	
	if(count == 0)
	{
		cout << "yes it is palindrome";
	}else{
		cout<< "No it's not a palindrome";
	}
}

// finding the duplicate characters in the string using hashing
// it's for small letters only
void DuplicateH(char a[])
{
	int z[25]={0};
	for(int i=0;a[i]!='\0'; i++)
	{
		z[a[i]-97]++;
	}
	for(int i=0; i<26;i++){
		if(z[i]>1)
		{
			char a = i+97;
			cout << "there is a duplicacy in the string, which is" << " " << (char)(i+97)  ;
			break;	
		}
	}
}

//it's for both small and capital letters
void DuplicateAllH(char a[])
{
	int z[122]={0};
	for(int i=0;a[i]!='\0'; i++)
	{
		z[a[i]]++;
	}
	for(int i=0; i<122;i++){
		if(z[i]>1)
		{
			cout << (char)(i) << " "; 
		}
	}
}

//finding duplicacy using masking & merging
//masking: to check whether bit is on or off;
//merging: to set the bit on;
void DuplicateMM(char a[])
{
	int x=0,h=0;
	for(int i=0; a[i]!='\0';i++)
	{
		x = 1;
		x = x << (a[i]-97);
		if( (x&h) > 0){ 
		printf("%c ", a[i]);
		} //masking
		else {
		h = h | x; // merging
	}
}
}

//Anagram with hashing
void AnagramH(char a[], char b[])
{
	int h[25]={0},i=0;
	for(i=0; a[i]!='\0';i++)
	{
		h[a[i]-97]++;
    }
    int count=0;
    for(int j=0; b[j]!='\0'; j++)
    {
    	if(h[b[j]-97] > 0) count++; 
	}
	if(count == i) printf("It's a anagram");
	else printf("Not a anagram");
}


//Permutation with Recursion
void Per(char s[], int k)
{
	static int A[10]={0};
	static char res[10];
	if(s[k]=='\0')
	{
		res[k]='\0';
		printf("%s\n",res);
	}else{
		for(int i=0;s[i]!='\0';i++)
		{
			if(A[i]==0)
			{
				res[k] = s[i];
				A[i]=1;
				Per(s,k+1);
				A[i]=0;
			}
		}
	}
}


int main()
{
	char string[20];
	gets(string);
//	char b[20];
//	gets(b);
	printf("\n");
	
//	reverse(string);
//	DuplicateAllH(string);
//	DuplicateMM(string);
//	AnagramH(string, b);		
	Per(string,0);
	
}