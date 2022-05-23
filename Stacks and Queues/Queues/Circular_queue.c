#include<stdio.h>
#define true 1

int queue[10];
int front=-1, rear=-1;

void append(int data){
    rear++;
    if (front==rear || (rear>9 && front==0)){
        printf("Queue is full\n");
        if (rear==10 || front>0) rear--;
        return;
    }
    if (rear==10 && front>0) rear = 0;
    queue[rear] = data;
    if (front==-1) front = 0;
}

int removee(){
    int n = queue[front];
    if (front==rear && front!=-1){
        front=-1;
        rear=-1;
        return n;
    }
    front++;
    if (front==10 && rear>=0) front=0;
    return n;
}

void print(){
    if (front<=rear){
        for (int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }
    else{
        for (int i=front; i<10; i++){
            printf("%d ", queue[i]);
        }
        for (int i=0; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main(){
    int n, num;
    printf("Enter\n1 to append\n2 to remove\n3 to print\n");
    while (true){
        printf("Enter Operation : ");
        scanf("%d", &n);
        switch (n)
        {
        
        case 1:
            printf("Enter num : ");
            scanf("%d", &num);
            append(num);
            printf("front = %d and rear = %d\n", front, rear);
            break;
        
        case 2:
            printf("%d\n", removee());
            printf("front = %d and rear = %d\n", front, rear);
            break;

        case 3:
            print();
            printf("front = %d and rear = %d\n", front, rear);
            break;

        default:
            break;
        
        }
        if (n==4) break;
    }
}