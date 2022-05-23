#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node = *head_ref;
    new_node->data = data;
    new_node->next = node;
    // *head_ref = new_node;
    if (node!=NULL){
        while (node->next!=*head_ref)
            node = node->next;
        
        node->next = new_node;
        *head_ref = new_node;
        return;
    }
    
    *head_ref = new_node;
    new_node->next = new_node;
    // if (node==NULL){
    //     new_node->next = new_node;
    //     new_node->data = data;
    //     node=new_node;
    //     return;
    // }

    // node->next = new_node;
    // *head_ref = new_node;
}

void append(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    if (*head_ref==NULL){
        *head_ref = new_node;
        new_node->next = new_node;
        return;
    }

    struct Node *node = *head_ref;
    
    while (node->next!=(*head_ref))
        node = node->next;
    
    node->next = new_node;

}

void insertAfter(struct Node *node, int data){

    if (node==NULL){
        printf("Previous Node catn be null\n");
        return;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = node->next;
    node->next = new_node;

}

void print(struct Node *node){
    struct Node *head = node;
    int i=0;
    do {
        printf("Element %d = %d\n", ++i, node->data);
        node = node->next;
    }while(node!=head);
}

void delete(struct Node **head_ref, struct Node *node){
    
    struct Node *n = *head_ref;
    struct Node *temp;
    
    if (*head_ref==node){
    struct Node *n1 = *head_ref;
        while (n->next!=*head_ref){
            n = n->next;
        }
        temp = *head_ref;
        *head_ref = n1->next;
        n->next = *head_ref;
        free(temp);
        return;
    }

    while (n->next!=node){
        // printf("chl ra h\n");
        n = n->next;
    }
    temp = n->next;
    n->next = n->next->next;
    free(temp);
}

void delete_pos(struct Node **head_ref, int pos){
    struct Node *node = *head_ref;
    
    while (--pos)
        node = node->next;
    
    delete(head_ref, node);

}

int main(){
    struct Node *head = NULL;
    push(&head, 10);
    
    // print(head);
    // printf("\n");
    // push(&head, 20);
    // print(head);
    // printf("\n");
    // push(&head, 100);
    append(&head, 20);
    append(&head, 30);

    insertAfter(head, 15);
    insertAfter(head->next->next, 25);
    print(head);
    // delete(&head, head->next->next);
    // delete(&head, head);
    delete_pos(&head, 1);
    printf("After Delete : \n");
    // delete_pos(&head, 1);
    print(head);
    // printf("\n");
}