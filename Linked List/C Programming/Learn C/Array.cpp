#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    int a[11] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int a1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i=0; i<=10; i++)
        cout<<a[i]<<endl;

    
    cout<<a[300];
}