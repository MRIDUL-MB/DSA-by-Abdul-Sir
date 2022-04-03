#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
	int top;
	int size;
	char *arr;
}stack;

stack st;

void create(int size)
{
	st.arr = (char*)malloc((size+1)*sizeof(char));
	st.top = -1;
	st.size = size;
}

void push(char c)
{
	st.top++;
	st.arr[st.top] = c;
}

char pop()
{
	if(st.top == -1) return ' ';
	else{
		char x= st.arr[st.top];
		st.top --;
		return x;
	}
}

int isOperand(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='('||c==')') return 0;
	return 1;
}

int preOut(char c)
{
	if(c=='+'||c=='-') return 1;
	else if(c=='*'||c=='/') return 3;
	else if(c=='^') return 6;
	else if(c=='(') return 7;
	else return 0;
}

int preIn(char c)
{
	if(c=='+'||c=='-') return 2;
	else if(c=='*'||c=='/') return 4;
	else if(c=='^') return 5;
	else if(c=='(') return 0;
	else return 0;
}

char* convert(char* infix)
{
	char *postfix=(char *)malloc((st.size+1)*sizeof(char));
	int i=0, j=0;
	while(infix[i] != '\0')
	{
		if(isOperand(infix[i])) postfix[j++]=infix[i++];
		else{
			if(preOut(infix[i]) > preIn(st.arr[st.top]))
			{
				push(infix[i++]);
			}else{
				if(infix[i]==')' && st.arr[st.top]=='(') {
					pop();				
					i++;
				}
				else postfix[j++]=pop();
			}
		}
	}
	while(st.top != -1)
	{
		postfix[j++]=pop();
	}
	postfix[j] = '\0';
	return postfix;
}

int main(){
	char infix[] = "((a+b)*c)-d^e^f";
	create(15);
	char *postfix = convert(infix);
	int i=0;
	while(postfix[i]!='\0')
	{
		printf("%c ", postfix[i]);
		i++;
	}
	return 0;
}

