#include<stdio.h>
#define true 1
struct s
{
    int data;
    int p;
};

struct s queue[10];
int front = -1, rear = -1;

void insert(int p, int d){
    
    queue[++rear].data = d;
    queue[rear].p = p;
    
    if (front==-1) front=0;
}

int get_priority(){
    int pr=queue[front].p;
    for (int i=front; i<=rear; i++){
        if (queue[i].p>pr){
            pr = queue[i].p;
        }
    }
    return pr;
}

void delete(){
    int pr = get_priority();
    int n;
    for (int i=front; i<=rear; i++){
        if (queue[i].p==pr){
            n=i;
            break;
        }
    }

    for (int i=n; i<rear; i++){
        queue[i].data = queue[i+1].data;
        queue[i].p = queue[i+1].p;
    }
    rear--;
}

void print(){
    
    for (int i=front; i<=rear; i++)
        printf("Element = %d with priority = %d\n", queue[i].data, queue[i].p);
    
    printf("\n");

}

int main(){
    int n;
    int num, p;

    printf("Enter:\n1 to insert\n2 to get highest priority\n3 to delete\n4 to print\n5 to end\n");;

    while (true){
        printf("Enter : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (rear==9){
                printf("Queue is full\n");
                break;
            }

            printf("Enter Priority : ");
            scanf("%d", &p);
            printf("Enter no : ");
            scanf("%d", &num);
            insert(p, num);
            break;
        
        case 2:
            if (rear==-1){
                printf("Queue is Empty\n");
                break;
            }
            printf("Highest Priority is : %d\n", get_priority());
            break;

        case 3:
            if (rear==-1){
                printf("Queue is Empty\n");
                break;
            }
            delete();
            break;

        case 4:
            print();
            break;

        default:
            break;
        }
        if (n==5) break;
    }
}