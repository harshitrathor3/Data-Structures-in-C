#include<iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter Dimensions : ";
    cin>>n>>m;
    int num = n * m;
    int n1, ans=1;
    for (int i=0; i<num; i++){
        printf("Here");
        cin>>n1;
        if (n1!=0 && n1!=1){
            ans=0;
            break;
        }
    }

    if (ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}