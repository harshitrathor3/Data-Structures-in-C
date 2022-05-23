#include<stdio.h>
#include<stdlib.h>
int main(){
    struct Node
    {
        int data;
        struct Node *next;
    };

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = (struct Node*)malloc(sizeof(struct Node));

    head->data = 101;
    head->next = second;

    second->data = 102;
    second->next = last;

    last->data = 103;
    last->next = NULL;

    struct Node *n = head;

    while (n!=NULL){
        printf("%d ",n->data);
        n = n->next;
    }
    printf("\n");
}