#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void append(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref==NULL){
        *head_ref = new_node;
        return;
    }
    struct Node *node = *head_ref;
    
    while (node->next!=NULL)
        node = node->next;
    
    node->next = new_node;

}

void removee(struct Node **head_ref){
    // struct Node *temp;
    struct Node *node = *head_ref;

    if (node->next==NULL){
        // temp = node;
        *head_ref = NULL;
        free(node);
        return;
    }
    
    // temp = node;
    *head_ref = node->next;
    free(node);
}

void print(struct Node *node){
    int i=1;
    while (node!=NULL){
        printf("Element %d = %d\n", i++, node->data);
        node = node->next;
    }
}

int main(){
    struct Node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    // removee(&head);
    // removee(&head);
    append(&head, 40);
    append(&head, 50);
    removee(&head);
    print(head);
}