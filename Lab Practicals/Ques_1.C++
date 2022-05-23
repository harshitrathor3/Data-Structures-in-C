#include<iostream>
#include<functional>
using namespace std;
#define len 10

int arr[len];
int indx=0;

void print(int n){
        for (int i=0; i<n; i++)
            cout<<arr[i]<<" ";
}

void Insert(){

    int num;
    cout<<"Enter no of Elements : ";
    cin>>num;

    for (int i=0; i<num; i++)
        cin>>arr[i];
    indx+= num;
    cout<<"Array is : ";
    print(num);
    
}

void Append(){
    int num;
    cout<<"Enter no of elements : ";
    cin>>num;
//     cout<<indx<<endl;
    for (int i=indx; i<indx+num; i++)
        cin>>arr[i];

    cout<<"Array is : ";
    for (int i=0; i<num+indx; i++)
        cout<<arr[i]<<" ";
    indx+=num;
}

void Search(){
        if (indx==0) cout<<"Array is empty"<<endl;
        else{
        int num;
        cout<<"Enter element to Search : ";
        cin>>num;

                int i;
                for (i=0; i<indx; i++)
                        if (arr[i]==num){
                                printf("Element %d is present at %d",num,i+1);
                                break;
                        }
                if (i==indx) cout<<"Element not Found";
        }
}

void Traverse(){
        if (indx==0) cout<<"Array is Empty"<<endl;
        else{
                for (int i=0; i<indx; i++)
                        cout<<arr[i]<<" ";
        }
}

int getIndex(int num){
                for (int i=0; i<indx; i++)
                        if (arr[i]==num)
                                return i;
                return -1;
        }

void Delete(){
        char chr;
        int ind;
        cout<<"Enter 'a' to delete with value"<<endl;
        cout<<"Enter 'b' to delete with index"<<endl;
        cout<<"Enter : ";
        cin>>chr;

        if (chr=='a'){
                
                int num;
                cout<<"Enter value : ";
                cin>>num;

                if (getIndex(num)>-1){
                        ind = getIndex(num);
                        goto find;
                }
                else cout<<"Num "<<num<<" not in Array"<<endl;

        }
        else if (chr=='b') {
                
                cout<<"Enter Index : ";
                cin>>ind;
          find:
                int j=ind;
                while (j<indx){
                        arr[j] = arr[j+1];
                        j++;
                }
                indx--;
                print(indx);
        }
        else {
                cout<<"Pls enter 'a' or 'b' "<<endl;
                Delete();
        }
}

int isfull(){
        if (len==indx) return 0;
        return len-indx;
}

int isempty(){
        if (indx<0) return 0;
        return indx+1;
}

void Sort(){

        if (!isempty()) {
                cout<<"Array is empty"<<endl;
                return ;
        }

        else if(isempty()==1){
                 cout<<"Here"<<endl;
                 print(indx);
                 return;
        }

        else{
                // cout<<"here"<<endl;
                int temp;
                
                for (int i=0; i<indx; i++){
                        // cout<<"Inside external for"<<endl;
                        for (int j=i+1; j<indx; j++){
                                // cout<<"Insode internal for"<<endl;
                                if (arr[i]>arr[j]){
                                        // cout<<"Inside if"<<endl;
                                        temp = arr[i];
                                        arr[i] = arr[j];
                                        arr[j] = temp;
                                        // cout<<"change"<<endl;
                                }
                        }
                }
                print(indx);
        }
}

void Reverse(){
        for (int i=indx-1; i>=0; i--)
                cout<<arr[i]<<" ";
        cout<<endl;
}

void Replace(){
        int num, inx;
        cout<<"Enter element to replace : ";
        cin>>num;
        cout<<"Enter inx : ";
        cin>>inx;
        arr[inx] = num;
        print(indx);
}

int main(){
    int ans;
    // string *opr[] = {&Insert, "Append", "Search", "Traverse", "Delete", "isfull", "isempty", "Sort", "Merge", "Reverse", "Replace"};
    // string *opr[] = {&Insert(), &Insert()};

    cout<<"Enter\n1 for Insert\n2 to Append\n3 to Search\n4 to Traverse\n5 to Delete\
    \n6 to Check isfull\n7 to Check isempty\n8 to Sort\n9 to Reverse\n10 to Replace"<<endl;
    
    while (ans!=0){
        cout<<endl<<endl;
        cout<<"Enter Operation No : ";
        cin>>ans;
        switch(ans){
            case 1 : Insert();
                    break;
            case 2 : Append();
                    break;
            case 3 : Search();
                    break;
            case 4 : Traverse();
                    break;
            case 5 : Delete();
                    break;
            case 6 : if (isfull()) cout<<"No remaning space is "<<isfull()<<endl;
                       else  cout<<"Yes it's is full"<<endl;
                    break;

            case 7 : if (isempty()) cout<<"No there are "<<isempty()<<" element"<<endl;
                      else cout<<"Yaaa its empty";
                    break;
            case 8 : Sort();
                    break;
        
            case 9 : Reverse();
                    break;
            case 10 : Replace();
                    break;
        }
  }
}