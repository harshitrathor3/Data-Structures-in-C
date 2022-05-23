#include<iostream>
using namespace std;

int main(){
    int arr[4][4], cnt=0;

    cout<<"Enter array values : "<<endl;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++){
            cin>>arr[i][j];
            if (arr[i][j]!=0) cnt++;
        }
    
    int ar[cnt][3];
    int k=0;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (arr[i][j]!=0){
                ar[k][0] = i+1;
                ar[k][1] = j+1;
                ar[k++][2] = arr[i][j];
            }
        }
    }

    cout<<"Sparse Matrix is : "<<endl;

    for (int i=0; i<cnt; i++){
        for (int j=0; j<3; j++)
            cout<<ar[i][j]<<" ";
        cout<<endl;
    }
    
    int nar[4][4], r, c, v;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            nar[i][j] = 0;
    

    for (int i=0; i<cnt; i++){
        r = ar[i][0];
        c = ar[i][1];
        v = ar[i][2];
        nar[r-1][c-1] = v; 
    }

    cout<<"Original Array : "<<endl;

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++)
            cout<<nar[i][j]<<" ";
        cout<<endl;
    }
}