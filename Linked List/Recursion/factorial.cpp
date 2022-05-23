#include<iostream>
using namespace std;

int fact(int n);

int main(){
    int n, fact1;
    cout<<"Enter number : ";
    cin>>n;
    fact1 = fact(n);
    cout<<"Factorial : "<<fact1<<endl;
    return 0;
}

int fact(int n){
    
    if (n==0) return 1;

    return n*fact(n-1);
}