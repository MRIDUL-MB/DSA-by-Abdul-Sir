#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
	int size;
	int top_index;
	int *s;
} stack;

//creating Stack
stack create()
{
	stack st;
	printf("Enter the size of the stack: ");
	scanf("%d", &st.size);
	
	// initialize the array
	st.s = (int*)malloc(sizeof(int));
	
	st.top_index = -1;
	
	return st;
}

// checking whether the stack is empty or not
int isEmpty(stack st){
	if(st.top_index == -1) return 1;
	return 0;
}

// checking whether the stack is full or not
int isFull(stack st){
	if(st.top_index == st.size - 1) return 1;
	return 0;
}

// displaying the stack
void display(stack st)
{
	if (isEmpty(st)) printf("\nNo element to display\n");
	else{
	
		printf("\nDisplaying--> \n");
		for(int i=st.top_index; i>=0; i--)
		{
			printf("%d\n", st.s[i]);
		}
	}
}

//inserting the elements
void push(stack *st, int data)
{
	if(isFull(*st)) printf("Stack overflow!!\n");
	else 
	{
		st->top_index++;
		st->s[st->top_index]=data;
		printf("%d is inserted\n",data);
	}
}

void pop(stack *st)
{
	if(isEmpty(*st)) printf("Stack is empty!!\n");
	else{
		printf("%d is popped out\n", st->s[st->top_index]);
		st->top_index--;
	}
}

int peek(stack st, int i)
{
	int x=-1;
	int index=st.top_index - i + 1;
	if(index>-1 && index < st.size)
	{
		return st.s[index];
	}
	return x;
}


int main(){
	
	stack st = create();
	push(&st, 1);
	push(&st, 2);
	push(&st, 3);
//	pop(&st);
//	pop(&st);
//	pop(&st);
//	pop(&st);
	printf("\nPeek element at index 1 is %d\n", peek(st, 1));
	display(st);
}