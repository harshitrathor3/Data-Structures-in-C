#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void append(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref==NULL){
        *head_ref = new_node;
        return;
    }

    struct Node *temp = *head_ref;
    while (temp->next!=NULL)
        temp = temp->next;

    temp->next = new_node;
}

void print(struct Node *node){
    int i=0;

    while (node->next!=NULL){
        printf("Element at %d = %d\n", ++i, node->data);
        node = node->next;
    }
    printf("\n");
}
 
int main(){
    struct Node *head = NULL;
    push(&head, 20);
    push(&head, 10);
    append(&head, 30);
    append(&head, 40);
    print(head);
}