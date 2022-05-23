#include<stdio.h>
#include<malloc.h>
#define true 1

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};


struct Queue{
    struct Tree *node;
    struct Queue *next;
};

struct Stack{
    struct Tree *node;
    struct Stack *next;
};

struct Queue *queue = NULL;
struct Tree *root = NULL;
struct Stack *stack = NULL;

void push(struct Tree *node){
    struct Stack *new_node = (struct Stack*)malloc(sizeof(struct Stack));
    new_node->node = node;
    new_node->next = NULL;

    if (stack==NULL){
        stack = new_node;
        return;
    }

    struct Stack *temp = stack;
    while (temp->next!=NULL)
        temp = temp->next;
    
    temp->next = new_node;
}

struct Tree* pop(){
    struct Stack *temp = stack;
    if (temp==NULL){
        printf("Stack is empty..\n");
        return NULL;
    }
    if (temp->next==NULL){
        struct Tree *node = temp->node;
        stack = NULL;
        return node;
    }

    while (temp->next->next!=NULL)
        temp = temp->next;
    struct Tree *node = temp->next->node;
    temp->next = NULL;
    return node;
}

void enqueue(struct Tree *node){
    struct Queue *new_node = (struct Queue*)malloc(sizeof(struct Queue));
    new_node->node = node;
    new_node->next = NULL;

    if (queue==NULL){
        queue = new_node;
        return;
    }

    struct Queue *temp = queue;

    while (temp->next!=NULL)
        temp = temp->next;

    temp->next = new_node; 
}

struct Tree* dequeue(){
    if (queue==NULL){
        printf("Queue is empty\n");
        return NULL;
    }
    struct Tree *temp = queue->node;
    queue = queue->next;
    return temp;    
}

void insert(int data){

    struct Tree *node = (struct Tree*)malloc(sizeof(struct Tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    if (root==NULL){
        root=node;
        return;
    }
    enqueue(root);

    while (true){
        struct Tree *temp = dequeue();

        if (temp->left!=NULL && temp->right!=NULL){
            enqueue(temp->left);
            enqueue(temp->right);
        }
        else{
            if (temp->left==NULL) temp->left = node;
            else temp->right = node;
            struct Queue *temp1 = queue;
            queue = NULL;
            free(temp1);
            return;
        }
    }
}

void inorder(struct Tree *node){

    if (node==NULL){
        printf("Root Node is empty\n");
        return;
    }

    if (node->left!=NULL) inorder(node->left);
    printf("%d ", node->data);
    if (node->right!=NULL) inorder(node->right);
}

void inorder_loop(struct Tree *node){
    int done=0;
    struct Tree *current = node;
    while (!done)
    {
        if (current!=NULL){
            push(current);
            current = current->left;
        }
        else if (stack!=NULL){
            current = pop();
            printf("%d ", current->data);
            current = current->right;
        }
        else{
            done=1;
        }
    }
}

void preorder(struct Tree *node){
    if (node==NULL){
        printf("Root Node is empty\n");
        return;
    }

    printf("%d ", node->data);
    if (node->left!=NULL) preorder(node->left);
    if (node->right!=NULL) preorder(node->right);
}

void preorder_loop(struct Tree *node){
    int done=0;
    struct Tree *current = node;

    while (!done)
    {
        if (current!=NULL){
            printf("%d ", current->data);
            push(current);
            current = current->left;
        }
        else if (stack!=NULL){
            current = pop();
            current = current->right;
        }
        else{
            done=1;
        }
    }
}

void postorder(struct Tree *node){
    if (node->left!=NULL) postorder(node->left);
    if (node->right!=NULL) postorder(node->right);
    printf("%d ", node->data);
}

void postorder_loop(struct Tree *node){
    int done=0;
    struct Tree *current = node;

    while (!done)
    {
        
    }
    

}

struct Tree* find_node(struct Tree*node, int data){
    int done=0;
    struct Tree *current = node;
    while (!done)
    {
        if (current!=NULL){
            push(current);
            current = current->left;
        }
        else if (stack!=NULL){
            current = pop();
            if (current->data==data){
                return current;
            }
            current = current->right;
        }
        else{
            done=1;
        }
    }
}

void delete(int data){
    int temp_data;
    struct Tree *temp_node = root;
    struct Tree *temp_node2;
    while (true){
        if (temp_node->right->right!=NULL)
            temp_node = temp_node->right;
        else{
            temp_data = temp_node->right->data;
            temp_node2 = temp_node->right;
            free(temp_node2);
            temp_node->right = NULL;
            if (data==temp_data) return;
            break;
        }
    }
    
    struct Tree *temp_node1 = find_node(root, data);
    temp_node1->data = temp_data;
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);
    insert(110);
    insert(120);
    insert(130);
    insert(140);
    insert(150);


    inorder(root);
    printf("\n");
    delete(60);
    inorder(root);
    printf("\n");

    // printf("Inorder Traversal : ");
    // inorder(root);
    // printf("\n");

    // printf("Preorder Traversal : ");
    // preorder(root);
    // printf("\n");

    // printf("Postorder Traversal : ");
    // postorder(root);
    // printf("\n");

    // preorder_loop(root);
    // printf("\n");

    // push(root);
    // push(root->left);
    // push(root->right);
    // push(root->left->left);
    // struct Tree *t;
    // printf("%d ",pop()->data);
    // printf("%d ",pop()->data);
    // printf("%d ",pop()->data);
    // printf("%d ",pop()->data);
    // printf("\n");
}