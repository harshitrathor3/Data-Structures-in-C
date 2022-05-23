#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int main(){
    long n;
    scanf("%d",&n);

    int *ptr = (int*)calloc(n, sizeof(int));
    float *ptr1 = (float*)calloc(n, sizeof(float));


    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    ptr[7] = 70;

    // ptr1[0] = 1.235;
    // printf("for float %f\n",*ptr1);

    printf("%d\n\n\n",*(ptr+7));
    printf("%d\n",ptr);
    printf("%d\n",*ptr);
    printf("%d\n",*(ptr+1));
    ptr+=2;
    printf("%d\n",*ptr);
    printf("\n\n");
    free(ptr);
    free(ptr1);
}