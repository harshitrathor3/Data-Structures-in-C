#include<iostream>
using namespace std;

int main(){
    int a[3][3], b[3][3], c[3][3];

    cout<<"Enter Elements of First Array"<<endl;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin>>a[i][j];
    
    cout<<"Enter Elements of Second Array"<<endl;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin>>b[i][j];

    // for (int i=0; i<3; i++){
    //     for (int j=0; j<3; j++){
    //         c[i][j] = a[i][j]+b[j][i];
    //     }
    // }

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<"A"<<a[i][j]<<endl;
            cout<<"B"<<b[j][i]<<endl;

        }
    }


    // cout<<"Multiplication is"<<endl;
    // for (int i=0; i<3; i++){
    //     for (int j=0; j<3; j++)
    //         cout<<c[i][j]<<"\t";
    //     cout<<endl;   
    // }


}