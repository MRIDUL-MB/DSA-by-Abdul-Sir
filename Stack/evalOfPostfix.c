#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
	int top;
	int size;
	int *arr;
}stack;

stack st;
void create( int size){
	st.arr = (int*)malloc((size+1)*sizeof(int));
	st.size=size;
	st.top=-1;
}

void push( char val)
{
	st.top++;
	st.arr[st.top] = val; 
}

int pop()
{
    int x=0;
	if(st.top == -1) return 0;
	else {
		x=st.arr[st.top];
		st.top--;
		return x;
	}
	
} 
int isOperand(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/') return 0;
	return 1;
}

int pre(char c)
{
	if(c=='+'||c=='-') return 1;
	else if(c=='*'||c=='/') return 2;
	return 0;
}

int eval(char* infix)
{
	int i=0;
	while(infix[i]!='\0'){
		if(isOperand(infix[i]))
		{
			push((int)infix[i++]-48);
		}else{
			char op = infix[i++];
			int b=pop(), a=pop();
			int res = 0;
			if(op == '+') res =  a + b;
			else if(op == '-') res =  a - b;
			else if(op == '*') res =  a * b;
			else if(op == '/') res =  a / b;
			push(res);
		}
	}
	int result = pop();
	return result;
}

int main()
{
	char infix[]="35*62/+4-";
	create(8);
	printf("%d ", eval(infix));
}