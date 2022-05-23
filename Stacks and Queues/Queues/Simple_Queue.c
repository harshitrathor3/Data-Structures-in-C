#include<stdio.h>
#define true 1

int queue[10];
int front=-1, rear=-1;

void add(int n){
    queue[++rear] = n;
    if (front==-1) front = 0;
}

int pop(){
    return queue[front++];
}

int print(){
    for (int i=front; i<=rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main(){
    int n, n1, num;
    printf("Enter: \n1 to insert\n2 to pop\n3 to print\n");
    while (true){
        printf("Enter : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter no of element : ");
            scanf("%d", &n1);
            while (n1--){
                printf("Enter a no : ");
                scanf("%d", &num);
                add(num);
            }
            break;
        case 2:
            printf("%d\n",pop());
            break;
        case 3:
            print();
            break;
        default:
            break;
        }
    }
}