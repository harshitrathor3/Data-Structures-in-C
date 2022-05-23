#include<stdio.h>
#include<stdlib.h>

int main(){
    char nm[20];
    gets(nm);
    // scanf("%s", &nm);
    // nm = (char*)malloc(sizeof(char)*5);
    printf("%s\n", nm);
}