#include<iostream>
using namespace std;
int arr[10];


int Binary_Search(int l, int r, int val){
    int n = (l+r)/2;
    if (arr[n]==val)
        return n+1;
    else if (arr[n]>val)
         Binary_Search(l, n, val);
    else
         Binary_Search(n, r, val);
    
}


int main(){
    int n;
    cout<<"Enter no of elements : ";
    cin>>n;
    cout<<"Enter elements : "<<endl;
    
    for (int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Enter Element to Search : ";
    int e;
    cin>>e;
    
    cout<<"Element is at "<<Binary_Search(0, n, e)<<" position";

}