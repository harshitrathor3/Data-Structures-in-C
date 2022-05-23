#include<iostream>
using namespace std;

struct student{
    int roll;
    string name;
    struct student *next;
};

int main(){
    struct student s1;

    s1.roll = 101;
    s1.name = "Amit";

    cout<<"Roll no : "<<s1.roll<<endl;
    cout<<"Name : "<<s1.name<<endl;
    
}