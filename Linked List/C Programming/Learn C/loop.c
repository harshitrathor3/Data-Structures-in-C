#include<stdio.h>
#include<conio.h>

int main(){
    for (int i=1; i<=100; i+=10)
        printf("hello");
    printf("\n\n");
    int j=1;
    for (;;){
        printf("world");
        if (j>100)
            break;
        j++;
    }
}