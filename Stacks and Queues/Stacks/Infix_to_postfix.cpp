#include<iostream>
using namespace std;

string symbol;
char stack[100];
int top=-1, k, n;
string str="";

bool isOperand(char c){
    if (int(c)>=65 && int(c)<=90) return true;
    else return false;
}

bool isOperator(char c){
    if (c=='+' || c=='-' || c=='*' || c=='/' || c=='$') return true;
    return false;
}

int get_priority(char c){
    if (c=='+' || c=='-') return 0;
    if (c=='*' || c=='/') return 1;
    if (c=='$') return 2;
}

bool check_pririty(char c1, char c2){
    if (c1=='(' || c1==')' || c2=='(' || c2==')') return false;
    if (get_priority(c1)==get_priority(c2)) return true;
    return false;
}

int main(){
    cout<<"Enter a Infix Expression : ";
    cin>>symbol;

    int i=0;
    char temp;
    while (symbol[i]!=NULL){
        temp = symbol[i];
        cout<<"Temp : "<<temp<<endl;

        if (isOperand(temp)){
            str = str + temp;  
        }
        else if (isOperator(temp)) {
            if (top==-1) stack[++top] = temp;
            else{
                // cout<<"Temp : "<<temp<<endl;
                // cout<<"Stack last : "<<stack[top]<<endl;
                if (check_pririty(temp, stack[top] )) {

                    str = str + stack[top];
                    stack[top] = temp;

                    // cout<<str<<endl;
                    // cout<<stack[top]<<endl<<endl;

                }
                else{
                    stack[++top] = temp;
                }
            }
        }
        else{
            if (temp=='('){
                stack[++top] = temp;
                k = top+1; 
            }
            else if (temp==')') {
                // n = top;
                cout<<endl;
                cout<<"top = "<<top<<endl;
                cout<<"k = "<<k<<endl;
                while (top>=k){
                    str = str + stack[top--];
                    cout<<"STR HERE : "<<str<<endl;
                }
                top--;
                cout<<"STack here  : "<<stack<<endl;
                cout<<endl;
            }
        }
        // cout<<"Stack : "<<stack<<endl;
        i++;
        cout<<"Stack : "<<stack<<endl;
        cout<<"String : "<<str<<endl<<endl;
    }
    // cout<<endl;
    // cout<<"Top : "<<top<<endl;
    // cout<<"Stack : "<<stack<<endl;
    // cout<<str<<endl;
    // cout<<endl;
    while (top!=-1){
        // if (stack[top]=='(' || stack[top]==')') top--;
        str = str + stack[top--];
    }

    cout<<str;

}

// ((A/B)*C)-(D*E)+F