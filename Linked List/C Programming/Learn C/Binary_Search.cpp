#include<iostream>
using namespace std;

int main(){
    int a[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int mid, low, high, key, index, status;

    cout<<"Enter no to search"<<endl;
    cin>>key;
    low = 0;
    high = 9;

    for (low=0; low<=high; ){
        mid = (low+high)/2;

        if (a[mid]==key){
            status = 1;
            index = mid;
            break;
            }
        else if (key>a[mid])
            low = mid + 1;
        else 
            high = mid - 1;

    }

    if (status ==1)
        cout<<"Element found at "<<index<<endl;
    else
        cout<<"Element not found"<<endl;

}