#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insert(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

}

int main(){
    int arr[] = {4, 7, 2, 6, 8, 3, 2 ,7 ,2, 6, 1};
    int ar[11];

}