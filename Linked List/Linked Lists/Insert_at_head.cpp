#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insert_After(struct Node* prev_node, int new_data){
    if (prev_node==NULL) printf("The given previous node can not be null\n");

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

}

void append(struct Node** head_ref, int new_data){
    
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    
    // last_node->next = new_node;
    if (*head_ref ==NULL){
        *head_ref = new_node;
        return;
    }

    while (last->next!=NULL)
        last = last->next;
    
    last->next = new_node;
    // return;
    

}

void print(struct Node *node){
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = NULL;

    // push(&head, 100);
    // push(&head, 101);
    // push(&head, 102);
    // push(&head, 103);

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);


    insert_After(head->next, 8);

    print(head);
    return 0;
}