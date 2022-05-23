#include<stdio.h>
#include<malloc.h>
#define true 1

struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *root = NULL;
struct Tree *p = NULL;

void insert(int data){
    struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root==NULL){
        root = new_node;
        return;
    }

    struct Tree *temp = root;
    while (true){
        if (temp->data>data){
            if (temp->left==NULL){
                temp->left = new_node;
                break;
            }
            temp = temp->left;
        }
        else{
            if (temp->right==NULL){
                temp->right = new_node;
                break;
            }
            temp = temp->right;
        }
    }
}

void inorder(struct Tree *temp){
    if (temp->left!=NULL) inorder(temp->left);
    printf("%d ", temp->data);
    if (temp->right!=NULL) inorder(temp->right);
}

void search(struct Tree *node, int data){
    if (node==NULL || node->data==data){    
        printf("Node is present at : %d\n", node);
        return;
    }
    if (node->data>data)
        return search(node->left, data);
    if (node->data<data)
        return search(node->right, data);
    printf("This element is not present\n");
}

struct Tree* search1(struct Tree *node, int data){
    while (true){
        if (node==NULL)
            return NULL;
        if (node->data==data)
            return node;
        if (node->data>data){
            p=node;
            node=node->left;
        }
        if (node->data<data){
            p=node;
            node=node->right;
        }
    }
}
  
void delete(int data){
    struct Tree *temp = search1(root, data);
    if (temp==NULL){
        printf("Element not present\n");
        return;
    }
    int child=0;
    if (temp->left!=NULL) child++;
    if (temp->right!=NULL) child++;

    struct Tree *temp1;
    if (child==0){
        temp1=temp;
        if (p->left->data==temp1->data) p->left=NULL;
        else p->right=NULL;
        free(temp1);

    }
    else if (child==1){
        if (temp->left!=NULL){
            temp->data = temp->left->data;
            temp1=temp->left;
            temp->left=NULL;
        }
        else{
            temp->data = temp->right->data;
            temp1=temp->right;
            temp->right=NULL;
        }
    }
    else{
        struct Tree *temp2=temp->right;
        if (temp2->left==NULL){
            temp->data=temp2->data;
            temp->right = temp2->right;
            temp1=temp2;
        }
        else{
            while (temp2->left!=NULL){
                p = temp2;
                temp2 = temp2->left;
            }
            temp->data=temp2->data;
            p->left=NULL;
            temp1=temp2;
        }
    }
    free(temp1);
}

int main(){
    insert(10);
    insert(5);
    insert(15);
    insert(2);
    insert(1);
    insert(3);
    insert(7);
    insert(6);
    insert(8);
    insert(12);
    insert(17);
    insert(16);
    insert(20);
    insert(11);
    insert(13);
    
    inorder(root);
    printf("\n");
    delete(12);
    printf("After delete\n");
    inorder(root);
    printf("\n");
    // search(root, 10000);
    // printf("%d\n", search1(root, 10000));
}