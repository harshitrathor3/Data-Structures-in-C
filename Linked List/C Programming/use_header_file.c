#include<stdio.h>
// #include<stdlib.h>
// #include<conio.h>
#include<ao.h>

void main(){
    int a, b, c, d;
    system("clear");
    printf("Enter two nos : ");
    scanf("%d%d",&a,&b);
    c = add(a, b);
    printf("%d",c);
}