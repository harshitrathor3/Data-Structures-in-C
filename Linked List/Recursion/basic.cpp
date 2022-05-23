#include<iostream>
using namespace std;

int main(){
    static int i=0;
    cout<<"Hello "<<endl;
    i++;
    if (i<10)
        main();
}