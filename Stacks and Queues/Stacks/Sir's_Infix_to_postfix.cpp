#include<iostream>
#include<stdio.h>
using namespace std;
char infix[100];
char stack[100];
char postfix[100];
int top = -1;
int isoperator(char ch);
int priority(char ch);
void push(char ch);
char pop();
void printpostfix();
int main() {
	int i=0,j=0,k;
	cout<<"enter any infix expression";
	cin>>infix;	
	while(infix[i]!=NULL) {
		if(isoperator(infix[i])) {
			if(top == -1)
				stack[++top] = infix[i];
			else {
				if(priority(stack[top])>priority(infix[i])) {
					postfix[j++] = pop();
					push(infix[i]);
				}				
				
				else {
					push(infix[i]);
				}	
			}
			
		}
		else {
			if(infix[i]=='(') {
				k=top;
				//push(infix[i]);
			}
			else {
				if(infix[i]==')') {
					while(top>=k) {
						postfix[j++] = stack[top--];
					}
				}
				else
					postfix[j++] = infix[i];
			}
			
						
		}
		i++;
	}
	while(top!=-1) {							//empty stack
		postfix[j++] = pop();
	}
	postfix[j] = '\0';							//insert null
	cout<<"Postfix Expression: ";
	printpostfix();
    // cout<<postfix<<endl;
	


}
int isoperator(char ch) {
	if(ch=='$'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
	return 1;
	else
	return 0;
}
int priority(char ch) {
	if(ch=='$')
	return 3;
	else {
		if(ch=='*'||ch=='/')
		return 2;
		else
		return 1;
	}	
}
void push(char ch) {
	top = top + 1;
	stack[top] = ch;
}
char pop() {
	char ch = stack[top];
	top = top-1;
	return ch;
}
void printpostfix() {
	int i=0;
	while(postfix[i]!=NULL) {
		cout<<postfix[i];
		i++;
	}
}