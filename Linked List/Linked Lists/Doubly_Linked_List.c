#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void push(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node = *head_ref;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = node;
    
    if (node!=NULL)
        node->prev = new_node;

    *head_ref = new_node;

}

void append(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node = *head_ref;

    new_node->data = data;
    new_node->next = NULL;

    if (node==NULL){
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (node->next!=NULL)
        node = node->next;
    
    node->next = new_node;
    new_node->prev = node;

}

void insert_After(struct Node *node, int data){

    if (node==NULL){
        printf("Node cant be null\n");
        return;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;

    if (new_node->next!=NULL){
        new_node->next->prev = new_node;
    }

}

void print(struct Node *node){
    int i=0;
    struct Node *last;
    printf("Traversal in Forward Direction : \n");
    while (node!=NULL){
        printf("Element %d = %d\n",++i,node->data);
        last = node;
        node = node->next;
    }
    i=0;
    printf("Traversal in Reverse Direction : \n");
    while (last!=NULL){
        printf("Element %d = %d\n",++i,last->data);
        last = last->prev;
    }
}

void deletenode(struct Node **head_ref, struct Node *node){
    // struct Node *node = *node;
    
    if (node==(*head_ref)){
        *head_ref = node->next;
        node->next->prev = NULL;
    }

    if (node->prev!=NULL)
        node->prev->next = node->next;
    if (node->next!=NULL)
        node->next->prev = node->prev;
    
    // free(node);

}

void delete_deletenode(struct Node **head_ref, int pos){
    struct Node *node = *head_ref;
    while(--pos){
        node = node->next;
    }
    deletenode(head_ref, node);
}

void delete(struct Node **head_ref, int pos){
    struct Node *node = *head_ref;

    if (pos==1){
        *head_ref = node->next;
    }

    while (--pos){
        node = node->next;
    }

    if (node->prev!=NULL)
        node->prev->next = node->next;

    if (node->next!=NULL)
        node->next->prev = node->prev;

}

int main(){
    struct Node *head = NULL;
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);
    append(&head, 50);
    append(&head, 60);
    insert_After(head->next, 25);
    print(head);

    printf("\nAfter Delete : \n\n");
    delete_deletenode(&head, 2);
    deletenode(&head, head->next->next);
    delete(&head, 2);
    print(head);
    
}