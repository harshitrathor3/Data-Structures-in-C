#include<iostream>
using namespace std;

int x[10] = {1,2,3};

void fun(int *x){
    for (int i=4; i<7; i++){
        cin>>x[i];
    }
}

int main(){
   fun(x);

   for (int i=0; i<9; i++)
    cout<<x[i]<<endl;
    cout<<"saaaa"<<sizeof(x)/sizeof(x[0])<<endl;
}