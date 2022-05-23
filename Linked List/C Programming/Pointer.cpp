#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int main(){
   int x = 5;
   int *ptr;
   ptr = &x;
   printf("%d\n%d\n",x,*ptr);
   printf("%d",ptr);
   return 0;
}