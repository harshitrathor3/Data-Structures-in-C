#include<iostream>
using namespace std;

int f(int *x){
    *x = *x+1;
    return *x;
}

int main(){
    int x=100;
    int *p;
    p = &x;
    cout<<f(p)<<endl;
    cout<<x<<endl;
}