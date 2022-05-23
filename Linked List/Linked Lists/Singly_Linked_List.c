#include<stdio.h>
#include<stdlib.h>

struct Node
{
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
    struct Node *node = *head_ref;
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref==NULL){
        *head_ref = new_node;
        return;
    }

    while (node->next!=NULL)
    {
        node = node->next;
    }

    node->next = new_node;
}

void insert_after(struct Node *prev, int data){
    if (prev==NULL){
        printf("Previous Node cant be null\n");
        return;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void print(struct Node *node){
    int i = 0;
    while (node!=NULL)
    {
        printf("Element %d = %d\n", ++i, node->data);
        node = node->next;
    }
    
}

void reverse(struct Node **head_ref){
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next = NULL;

    while (current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void reverse_recursive(struct Node **head_ref){
    struct Node *node = *head_ref;
    if (node->next->next==NULL){
        *head_ref = node;
        node->next->next = node;
        return;
    }

    reverse_recursive(&(node->next));
    node->next->next = node;
    return;

}

int main(){
    struct Node *head = NULL;
    push(&head, 1);
    append(&head, 2);
    append(&head, 3);
    insert_after(head->next->next, 4);
    append(&head, 5);
    print(head);
    // printf("\nAfter Reversing : \n");
    // reverse(&head);
    // reverse_recursive(&head);
    // print(head);

}