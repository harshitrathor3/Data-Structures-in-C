#include<iostream>
using namespace std;

int factorial(int n){
    if (n<=0) return 1;
    return n*factorial(n-1);
}

int fibonacci(int n){
    if (n==0) return 0;
    if (n<=3) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int gcd(int x, int y){
    if (y>x){
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

    if (x%y==0) return y;
    return gcd(y, x%y);
}

int main(){
    cout<<"Factorial : "<<factorial(10)<<endl;
    cout<<"Fibonacci : "<<fibonacci(9)<<endl;
    cout<<"GCD : "<<gcd(98, 12)<<endl;
}