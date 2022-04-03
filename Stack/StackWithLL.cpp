#include<iostream>
using namespace std;

class Node {
	public:
	int data;
	Node *next;
};

class Stack{
	private:
		Node* top;
	public:
		Stack(){top=NULL;}
		void push(int);
		void pop();
		void display();
		void peek(int);
		~Stack(){
			delete top;
			cout<<"Destructing all the things of this class..."<<endl;
		}
};

void Stack::push(int value){
	Node *t= new Node;
	if(t==NULL){
		cout<<"Stack overflow"<<endl;
		return;
	}else{
		t->data=value;
		t->next=top;
		top = t;
	}
}

void Stack::pop(){
	if(top==NULL){
		cout<<"Stack Underflow "<< endl;
		return;
	}
	Node *t=top;
	top=top->next;
	delete t;
}

void Stack::display()
{
	Node *p=top;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	} cout<< endl;
}

void Stack::peek(int index)
{
	if(top==NULL) return;
	Node *p=top;
	for(int i=0;i<index-1&&p;i++) p = p->next;
	if(p)cout<<p->data<<endl;
}

int main(){
	Stack s;
	s.push(1);s.push(5);
	s.display();
	s.pop();s.pop();s.pop();
	s.display();
}
