#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void push(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = data;

    if (*head_ref==NULL){
        new_node->prev = new_node;
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }


    new_node->prev = (*head_ref)->prev;
    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
    struct Node *node = *head_ref;

    while (node->next!=*head_ref){
        // printf("chl ra\n");
        node = node->next;
    }

    *head_ref = new_node;
    node->next = new_node;

}

void append(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*head_ref==NULL){
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node *node = *head_ref;

    while (node->next!=*head_ref)
        node = node->next;

    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;
    (*head_ref)->prev = new_node;

}

void insert_After(struct Node *node, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = node->next;
    new_node->prev = node;
    node->next->prev = new_node;
    node->next = new_node;
}

void insert(struct Node **head_ref, int data, int pos){

    if (pos==1)
        return push(head_ref, data);
    
    struct Node *node = *head_ref;
    pos--;
    while (--pos){
        node = node->next;
    }
    return insert_After(node, data);


}

void print(struct Node *node){
    if (node==NULL){
        printf("can't print.. List is empty\n");
        return;
    }
    int i=1;
    printf("Forward Traversal\n");
    struct Node *n = node;
    // struct Node *n1 = node;
    do{
        printf("Element %d = %d\n", i++, node->data);
        node = node->next;
    }while (node!=n);
    node = node->prev;
    // node = node->next;
    i=1;
    printf("Reverse Traversal\n");
    // n = n1;
    do{
        printf("Element %d = %d\n", i++, node->data);
        node = node->prev;
    }while (node!=n->prev);
    // printf("Element %d = %d\n", i++, node->data);

}

void delete(struct Node **head_ref, struct Node *node){
    struct Node *n = *head_ref;
    if (n==node){
        n->prev->next = n->next;
        *head_ref = n->next;
        (*head_ref)->prev = n->prev;
        return;
    }

    while (n->next!=node)
        n = n->next;
    
    n->next = node->next;
    node->next->prev = n;
}

void delete_pos(struct Node **head_ref, int pos){
    if (pos==1){
        return delete(head_ref, *head_ref);
    }

    struct Node *n = *head_ref;
    
    while (--pos){
        n = n->next;
    }
    
    delete(head_ref, n);

}

int main(){
    struct Node *head = NULL;
    // push(&head, 30);
    // push(&head, 20);
    // push(&head, 10);
    // push(&head, 5);
    append(&head, 40);
    append(&head, 50);
    push(&head, 10);
    append(&head, 60);
    push(&head, 5);
    // insert_After(head->next->prev->next->prev, 7);
    insert(&head, 7, 2);
    insert(&head, 59, 6);
    
    // delete(&head, head->next->next->next->next->next->next->next);
    delete_pos(&head, 4);
    // delete(&head, head);
    // delete(&head, head);
    print(head);
}