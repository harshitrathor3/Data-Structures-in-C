#include<stdio.h>
int arr[10];
int main(){
    int ar1[10];

    for (int i=0; i<13; i++)
        scanf("%d", &arr[i]);
    
    for (int i=0; i<13; i++)
        printf("%d   %d\n", &arr[i], arr[i]);

    printf("\n\n");
    for (int i=0; i<13; i++)
        scanf("%d", &ar1[i]);
    
    for (int i=0; i<13; i++)
        printf("%d   %d\n", &ar1[i], ar1[i]);

}