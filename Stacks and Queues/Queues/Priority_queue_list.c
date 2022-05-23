#include<stdio.h>
#include<stdlib.h>
#define true 1

struct Node{
    int data;
    int p;
    struct Node *next;
};
int i=0;

void insert(struct Node **head_ref, int p, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->p = p;
    new_node->next = NULL;

    if (*head_ref==NULL){
        *head_ref = new_node;
        return;
    }
    struct Node *node = *head_ref;
    while (node->next!=NULL){
        node = node->next;
    }
    node->next = new_node;

}

int get_priority(struct Node *node){
    int p = -1;
    
    while (node!=NULL){
        if (node->p>p)
            p = node->p;
        node = node->next;
    }
    return p;
}

void delete(struct Node **head_ref){
    int p = get_priority(*head_ref);

    if ((*head_ref)->p==p){
        printf("Deleted = %d with Priority = %d\n", (*head_ref)->data, (*head_ref)->p);
        *head_ref = (*head_ref)->next;
        return;
    }

    struct Node *node = *head_ref;
    struct Node *t;
    while (node->next->p!=p){
        node = node->next;
    }

    printf("Deleted = %d with Priority = %d\n", node->next->data, node->next->p);
    t = node->next;
    node->next = node->next->next;
    free(t);

}

void print(struct Node *node){
    int i=1;
    while (node!=NULL)
    {
        printf("Element %d = %d and priority = %d\n", i++, node->data, node->p);
        node = node->next;
    }
}

int main(){
    struct Node *head=NULL;
    int n, p, num;
    printf("Enter:\n1 to insert\n2 to get priority\n3 to delete\n4 to print\n");
    while (true)
    {
        printf("Enter : ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("Enter priority : ");
            scanf("%d", &p);
            printf("Enter data : ");
            scanf("%d", &n);
            insert(&head, p, n);
            break;
        
        case 2:
            printf("Priority = %d\n", get_priority(head));
            break;

        case 3:
            delete(&head);
            break;
        
        case 4:
            print(head);
            break;
        
        default:
            break;
        }
    }
}