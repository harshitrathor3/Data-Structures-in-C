#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5,6,7};
    // arr.length();
    int len = arr-*(&arr-1);
    cout<<len<<endl;

    int arr1[] = {100,2,3,4,5};
     len = *(&arr1-1)-arr1;
    cout<<len<<endl;
    cout<<*arr1<<endl;
    cout<<(&arr1-1)<<endl;
    cout<<*(arr1+2)<<endl;
  
}