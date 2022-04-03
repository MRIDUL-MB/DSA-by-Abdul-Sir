#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int top;
	int size;
	char *arr;
}stack;

void create(stack *st, int size){
	st->arr = (char*)malloc((size+1)*sizeof(char));
	st->size=size;
	st->top=-1;
}

void push(stack *st, char val)
{
	st->top++;
	st->arr[st->top] = val; 
}

char pop(stack *st)
{
    char x=' ';
	if(st->top == -1) return x;
	else {
		x=st->arr[st->top];
		st->top--;
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

char* convert(char *infix, stack *st)
{
	char *postfix= (char*)malloc(sizeof(char)*(st->size+1));
	int i=0, j=0;
	while(infix[i]!='\0')
	{
		if(isOperand(infix[i])) postfix[j++]=infix[i++];
		else{
			if(pre(infix[i]) > pre(st->arr[st->top])){
				push(st, infix[i++]);
			}else{
				postfix[j++]=pop(st);
			}
		}
	}
	while(st->top != -1)
	{
		postfix[j++]=pop(st);
	}
	postfix[j]='\0';
	return postfix;
}

int main()
{
	stack st;
	char infix[] = {'a','+','b','*','c','-','d','e','\0'};
	create(&st, 8);
	char *postfix = convert(infix, &st);
	for(int i; postfix[i]!='\0';i++)
	{
		printf("%c ", postfix[i]);
	}
	
	
	
}
