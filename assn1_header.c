#include <stdio.h>
#include <stdlib.h>
#include "assn1_header.h"

void initQueue(Queue* Q) {
		Q->rear = Q->front = NULL;
		Q->count = 0;
}

void enqueue(Queue* Q, bstNode* x) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = x;
	temp->next = NULL;
	if (!Q->count) {
		Q->front = Q->rear = temp;
	}
	else {
		Q->rear->next = temp;
		Q->rear = Q->rear->next;
	}
	Q->count++;
}

bstNode* dequeue(Queue* Q) {
	if (!Q->count) {
	        return NULL;
	}
	else {
		QueueNode* temp = Q->front;
		bstNode* temp1 = temp->data;
		Q->front = Q->front->next;
		temp->next = NULL;
		free(temp);
		Q->count--;
		return temp1;
	}
}

bstNode* insert(bstNode* root, int x) { 
	if (!root) {
		bstNode* temp = (bstNode*)malloc(sizeof(bstNode));
		temp->val = x;
		temp->left = temp->right = NULL;
		root = temp;
	}
	else if (x < root->val) {
		root->left = insert(root->left, x);
	}
	else {
		root->right = insert(root->right, x);
	}
	return root;
}

void LevelOrderDisplay(bstNode* root, Queue* Q) {
	while (root) {
		printf("%d\t",root->val);
		if (root->left) {
			enqueue(Q, root->left);
		}
		if (root->right) {
			enqueue(Q, root->right);
		}
		root = dequeue(Q);
	}
}
