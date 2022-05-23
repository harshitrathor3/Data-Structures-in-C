#include<stdio.h>
#include<stdlib.h>

#define bool _Bool
#define true 1
#define false 0

int queue[10];
int front=-1, rear=-1;

bool isfull(){
    if (front==0 && rear==9) return true;
    if (abs(front-rear)==1 && rear<front) return true;
    return false;
}


void push(int data){    
    if (isfull()){
        printf("Queue is full\n");
        return;
    }

    if (front==-1){
        front=0;
        queue[front] = data;
        rear=0;
        return;
    }

    if (front==0 && rear!=9){
        front=9;
        queue[front] = data;
        return;
    }

    if (front>rear){
        if (front-1!=rear){
            front--;
            queue[front] = data;
            return;
        }
        else{
            printf("Queue is full\n");
            return;
        }
    }

    if (front<rear && front!=0){
        front--;
        queue[front] = data;
        return;
    }
}

void append(int data){
    if (isfull()){
        printf("Queue is full\n");
        return;
    }

    if (rear==-1){
        rear=0;
        front=0;
        queue[rear] = data;
        return;
    }

    if (rear==9 && front>0){
        rear=0;
        queue[rear] = data;
        return;
    }

    if (rear>=front){
        rear++;
        queue[rear] = data;
        return;
    }

    if (rear<front && rear+1!=front){
        rear++;
        queue[rear] = data;
        return;
    }
}

void print(){
    if (front<=rear){
        for (int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else{
        for (int i=front; i<10; i++){
            printf("%d ", queue[i]);
        }
        for (int i=0; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int pop(){
    if (front==-1){
        printf("Queue is empty.\n");
        return 0;
    }

    int n;

    if (front==rear){
        n = queue[rear];
        rear = -1;
        front = -1;
        return n;
    }

    if (rear==0){
        n = queue[rear];
        rear = 9;
        return n;
    }

    return queue[rear--];

}

int removee(){
    int n;

    if (front==-1){
        printf("Queue is empty\n");
        return 0;
    }

    if (front==rear){
        n = queue[front];
        front=-1;
        rear=-1;
        return n;
    }

    if (front==9){
        n = queue[front];
        front = 0;
        return n;
    }

    return queue[front++];

}

int main(){
    int n, num;
    printf("Enter:\n1 to push\n2 to append\n3 to remove\n4 to pop\n5 to print\n");

    while (true)
    {
        printf("Enter pls : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter a no : ");
            scanf("%d", &num);
            push(num);
            printf("Front = %d Rear = %d\n", front, rear);
            break;

        case 2:
            printf("Enter a no : ");
            scanf("%d", &num);
            append(num);
            printf("Front = %d Rear = %d\n", front, rear);
            break;
        
        case 3:
            printf("%d\n", removee());
            printf("Front = %d Rear = %d\n", front, rear);
            break;

        case 4:
            printf("%d\n", pop());
            printf("Front = %d Rear = %d\n", front, rear);
            break;

        case 5:
            print();
            break;

        default:
            break;
        }

        if (n==6)   break;
    }
}