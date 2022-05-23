#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_After(struct Node* prev_node, int new_data){
    if (prev_node==NULL){
        printf("Previous Node can't be null\n");
        return;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    struct Node *last = *head_ref;

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while (last->next!=NULL)
        last = last->next;
    
    last->next = new_node;

}

void print(struct Node *node){
    while (node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void delete(struct Node **head_ref, int data){
    if (*head_ref==NULL){
        printf("List is emplty. can't delete..\n");
        return;
    }

    struct Node *node = *head_ref;

    if (node->next==NULL && node->data == data){
        *head_ref = NULL;
        return;
    }

    if (node->data==data){
        *head_ref = node->next;
        node->next = NULL;
        
        // printf("Node next : %d\n", node->next);
        // printf("head : %d\n",*head_ref);
        free(node);

        return;
    }

    while (1){

        if (node->next==NULL){
            printf("Element not in list\n");
            return;
        }

        if (node->next->data==data){
            node->next = node->next->next;
            return;
        }

        node = node->next;
    }
    free(node);
}

void delete_position(struct Node **head_ref, int pos){
    struct Node *node = *head_ref;
    

    if (pos==1){
        *head_ref = node->next;
        free(node);
        return;
    }

    pos-=2;

    while (pos-- && node!=NULL)
    {
        // if (node==NULL || node->next==NULL){
        //     printf("Position out of range...1\n");
        //     return;    
        // }
        node = node->next;
        
    }

    if (node==NULL || node->next==NULL){
        printf("Position out of range...2\n");
        return;
    }

    node->next = node->next->next;
    // free(node);

    // *head_ref = node;
        
}

void reverse(struct Node **head_ref){
    struct Node *node = *head_ref;
    
    if (node->next->next!=NULL){
        return reverse(&node);
    }

    node->next->next = node;

}

int main(){
    struct Node *head = NULL;
    
    push(&head, 102);
    push(&head, 103);
    append(&head, 104);


    insert_After(head->next, 7);

    print(head);

    // delete(&head, 102);
    // delete(&head, 8);
    // delete(&head, 104);
    // delete(&head, 103);
    
    delete_position(&head, 10);

    print(head);

}