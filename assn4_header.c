#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct BST {
    int size;
    int* bst;
}BST;

typedef struct QueueNode {
	int val;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	int count;
	QueueNode* front;
	QueueNode* rear;
}Queue;

void initQueue(Queue* Q) {
	Q->front = NULL;
	Q->count = 0;
	Q->rear = NULL;
}

void enqueue(int val, Queue* Q) {

	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->next = NULL;

	if (Q->count == 0) {
		Q->front = Q->rear = temp;
	}

	else {
		Q->rear->next = temp;
		Q->rear = Q->rear->next;
	}

	Q->rear->val = val;
	Q->count++;
}

int dequeue(Queue* Q) {

	if (Q->count==0) {
		printf("Underflow\n");
		return -1;
	}

	else {
		QueueNode* temp = Q->front;
		Q->front = Q->front->next;
		temp->next = NULL;
		int x = temp->val;
		free(temp);
		Q->count--;
		return x;
	}
}

void createBST(int n, BST* p) {
	printf("Enter size: ");
	scanf("%d",&n);
	p->size = n;
	p->bst = (int*)malloc(sizeof(int)*n);
	printf("Enter elements: ");
	for (int i=0;i<n;i++) {
		scanf("%d",&p->bst[i]);
	}
}

bool isEmptyBST(BST* p) {
	if (!p->size) {
		return 1;
	}
	return 0;
}

int expo_with_two(int x) {
	int temp = 1;
	while (x>0) {
		temp *= 2;
		x -= 1;
	}
	return temp;
}

// Height of BST: 

int heightOfBST(BST* p) {
    if (isEmptyBST(p)) {
	return -1;
    }
    int height = 0;
    int iter = 0, level = 0;
    while (iter < p->size) {
	    int level_nodes = expo_with_two(level);
	    for (int i = iter; i< level_nodes + iter; i++) {
		    if (i >= p->size) {
			    return height;
		    }
	    }
	    height++;
	    level++;
	    iter = iter + level_nodes;
    }
    return height - 1;
}

// No. of leaf nodes:

int numberOfLeafNodes(Queue* Q, BST* p) {
	if (isEmptyBST(p)) {
		return 0;
	}
//	int iter = 0, count = 0;
//	while (iter < p->size) {
//		if (p->bst[iter] != INT_MIN) {
//			if ((2*iter
	
	enqueue(p->bst[0], Q);
	int i = 0, count = 0;
	while (Q->count) {
		int temp = dequeue(Q);
		if (2*i+1 < p->size && p->bst[2*i+1] != 0) {
		      	enqueue(p->bst[2*i+1], Q);
		}
  		if (2*i+2 < p->size && p->bst[2*i+2] != 0) {
			enqueue(p->bst[2*i+2], Q);
		}
		if (2*i+1 >= p->size && 2*i+2 >= p->size) {
			count++;
		}
		i++;
	}
	return count;
}

void LevelOrder(BST* p) {
	if (isEmptyBST(p)) {
		printf("BST is Empty!");
		return;
	}
	for (int i=0;i<p->size;i++) {
		if (p->bst[i]) {
			printf("%d\t",p->bst[i]);
		}
	}
}	
	
bool isComplete(BST* p) {
	if (isEmptyBST(p)) {
                printf("BST is Empty!");
                return true;
        }
        for (int i=0;i<p->size;i++) {
                if (p->bst[i]) {
                        if (p->bst[2*i+1] ^ p->bst[2*i+2]) {
				return false;
			}
                }
        }
	printf("lmao");
	return true;
}

int main() {
	BST p;
	Queue Q;
	initQueue(&Q);
	int n = 0;
	createBST(n, &p);
	printf("Height of BST: %d\n",heightOfBST(&p));
	printf("Number of leaf nodes: %d\n",numberOfLeafNodes(&Q, &p)); 
	printf("Level Order Display: ");
	LevelOrder(&p);
	printf("\nIs the BST Complete: %d",isComplete(&p));
}
