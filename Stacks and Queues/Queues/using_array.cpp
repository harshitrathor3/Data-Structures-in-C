#include<iostream>
using namespace std;
#define size 10
int queue[size];
int front = -1, rear = -1;

void add(int n){
    queue[++rear] = n;
    if (front==-1) front = 0;
}

int del(){
    return queue[front++];
}

void print(){
    for (int i=front; i<=rear; i++)
        cout<<queue[i]<<" ";
        cout<<endl;
}

void main(){
    int n;
    while (n){
        cout<<"Enter "<<endl<<"1 to add"<<endl<<"2 to delete"<<endl<<"3 to print"<<"0 to exit"<<endl;
        cout<<"Enter Operation : ";
        cin>>n;

        switch(n){
            case 1: 
                
        }

    }
}