#include<stdio.h>
#include<stdbool.h>

int tree[20];
// int f=-1;
int n=0;

void insert(int data){
    tree[n++] = data;
}

void print(){
    int i=0;
    int num=0;
    int t=0;

    while (i<n){
        if (t%3==0){
            printf("Root Node : %d\nChilds are : ", tree[i++]);
            t++;
            continue;
        }
        if (num==0){
            if ((2*i-1)<=n)
                printf("%d ", tree[2*i-1]);
            num=1;
        }
        else{
            if ((2*i)<=n)
                printf("%d ", tree[2*i]);
            num=0;
            printf("\n");
        }
        t++;
    }
    printf("\n");
}

int main(){
    int n, num;
    printf("Enter :\n1  to insert\n2 to print\n3 to stop\n");
    while (true)
    {
        printf("Enter : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter num : ");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            print();
            break;
        default:
            break;
        }
        if (n==3) break;
    }
}