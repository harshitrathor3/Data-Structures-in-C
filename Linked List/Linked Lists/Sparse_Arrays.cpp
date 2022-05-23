#include<iostream>
using namespace std;

int main(){
    int n, q;
    cin>>n;
    string strings[n];
    for (int i=0; i<n; i++)
        cin>>strings[i];
    
    cin>>q;
    string queries[q];


    int arr[q];

    
    
    for (int i=0; i<q; i++)
        cin>>queries[i];
    
    for (int i=0; i<q; i++){
        arr[i]=0;
        for (int j=0; j<n; j++){
            if (strings[j]==queries[i]) arr[i]++;
        }
    }

    for (int i=0; i<q; i++)
        cout<<arr[i]<<" ";

}