#include<iostream>
using namespace std;
#define size 10

int stack[size];
int top = -1;

void push(int);
int pop();
bool isfull();
bool isempty();
void print_stack();

bool isfull(){
    return top==size-1;
}

bool isempty(){
    return top==-1;
}

void push(int n){
    // top++;
    stack[++top] = n;
}

void print_stack(){
    for (int i=0; i<top+1; i++)
        cout<<stack[i]<<" ";
        cout<<endl;
}

int pop(){
    int num;
    num = stack[top--];
    // top--;
    return num;
}

int main(){
    int n;
    while (n){
        cout<<"Enter "<<endl<<"1 to push"<<endl<<"2 to pop"<<endl<<"3 to print"<<endl<<"0 to exit"<<endl;
        cout<<"Enter a no : ";
        cin>>n;
        switch(n){
            case 1: if (isfull()){
                        cout<<endl<<"Stack is full"<<endl<<endl;
                        break;
                    }
                    int num;
                    cout<<"Enter no to push : ";
                    cin>>num;
                    push(num);
                    break;
            
            case 2: if (isempty()) {
                        cout<<endl<<"Stack is empty"<<endl<<endl;
                        break;
                    }
                    cout<<endl<<pop()<<endl<<endl;
                    break;
            
            case 3: 
                    cout<<endl;
                    print_stack();
                    cout<<endl;
                    break;
        }
    }



}

