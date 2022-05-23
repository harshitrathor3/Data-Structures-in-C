#include<stdio.h>
#include<malloc.h>
#define true 1

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue{
    struct Node *node;
    struct Queue *next;
};

struct Node *root = NULL;
struct Queue *queue = NULL;

void enqueue(struct Queue **head_ref, struct Node *node){
    struct Queue *new_node = (struct Queue*)malloc(sizeof(struct Queue));
    new_node->node = node;
    new_node->next = NULL;

    if (*head_ref==NULL){
        *head_ref = new_node;
        return;
    }

    struct Queue *node1 = *head_ref;

    while (node1->next!=NULL){
        node1 = node1->next;
    }
    node1->next = new_node;
}

struct Queue* dequeue(struct Queue **head_ref){
    struct Queue *node = *head_ref;
    if (*head_ref==NULL){
        printf("Queue is already empty.....\n");
        return node;
    }
    
    *head_ref = (*head_ref)->next;
    return node;
}

void insert(int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root==NULL){
        root = new_node;
        return;
    }
    
    enqueue(&queue, root);
    while (true){
        struct Node *node = dequeue(&queue);

        if (node->left!=NULL && node->right!=NULL){
            enqueue(&queue, node->left);
            enqueue(&queue, node->right);
        }
        else{
            if (node->left==NULL){
                node->left = new_node;
                return;
            }
            node->right = new_node;
            return;
        }
    }
}

void inorder_traversal(struct Node *node){
    if (root==NULL){
        printf("Tree is empty...\n");
        return;
    }
    if (node->left!=NULL) inorder_traversal(node->left);
    printf("%d ", node->data);
    if (node->right!=NULL) inorder_traversal(node->right);
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    inorder_traversal(root);
}