#include <stdio.h>
#include <stdlib.h>

typedef struct AVL_node {
	int data;
	struct AVL_node* left;
	struct AVL_node* right;
	int bf;
}AVL_node;

typedef struct QueueNode {
    AVL_node* data;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int count;
}Queue;

void LevelOrder(AVL_node* root, Queue* Q);
void enqueue(Queue* Q, AVL_node* x);
AVL_node* dequeue(Queue* Q);
AVL_node* init_AVL(AVL_node* root);
int max(int a, int b);
int height(AVL_node* root);
AVL_node* update_bf(AVL_node* root);
AVL_node* LL_rotate(AVL_node* x);
AVL_node* RR_rotate(AVL_node* x);
AVL_node* LR_rotate(AVL_node* x);
AVL_node* RL_rotate(AVL_node* x);
AVL_node* insert_AVL(AVL_node* root, int x);
AVL_node* FindMin(AVL_node* root);
AVL_node* delete_AVL(AVL_node* root, int target);
void Inorder(AVL_node* root);
void Preorder(AVL_node* root);
void Postorder(AVL_node* root);
AVL_node* destroy_AVL(AVL_node* root);
