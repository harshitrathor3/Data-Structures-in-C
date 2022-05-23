#include<iostream>
#include<conio.h>

using namespace std;

int largest( int *arr, int n){
    int curlrg = arr[0];

    for (int i=1; i<n ;i++)
        if (arr[i]>curlrg)
            curlrg = arr[i];
    return curlrg;
}

int main(){
    int a[] = {1,4,5,3,2,34,22,5,6,7,2,3,687,2};
    int x = largest(a, 14);
    cout<<"Largest element "<<x;
}
