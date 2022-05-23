#include<iostream>
using namespace std;

void Sum(int ar1[2][2], int ar2[2][2]){
    cout<<"Sum is "<<endl;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++)
            cout<<ar1[i][j] + ar2[i][j]<<" ";
        cout<<endl;
    }
}

void Transpose(int ar1[2][2]){
    
    int temp = ar1[0][1];
    ar1[0][1] = ar1[1][0];
    ar1[1][0] = temp;
    cout<<"Transpose is "<<endl;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++)
            cout<<ar1[i][j]<<" ";
        cout<<endl;
    }
}

void Determinant(int ar1[2][2]){
    cout<<"Determinanat is "<<ar1[0][0]*ar1[1][1] - ar1[0][1]*ar1[1][0]<<endl;
}

int main(){
    int arr1[2][2];
    int arr2[2][2];
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            cin>>arr1[i][j];

    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            cin>>arr2[i][j];
    cout<<endl;
    Sum(arr1, arr2);
    Transpose(arr1);
    Determinant(arr2);
}