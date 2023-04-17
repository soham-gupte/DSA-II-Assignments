#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode {
        int val;
        struct bstNode* left;
        struct bstNode* right;
}bstNode;

typedef struct QueueNode {
        bstNode* data;
        struct QueueNode* next;
}QueueNode;

typedef struct Queue {
        QueueNode* front;
        QueueNode* rear;
        int count;
}Queue;

void initQueue(Queue* Q);
void enqueue(Queue* Q, bstNode* x);
bstNode* dequeue(Queue* Q);
bstNode* insert(bstNode* root, int x);
void LevelOrderDisplay(bstNode* root, Queue* Q);
