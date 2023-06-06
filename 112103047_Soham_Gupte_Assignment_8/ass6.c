#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode;

typedef struct Stack {
	ListNode* head;
}Stack;

typedef struct Queue {
	ListNode *front, *rear;
	int count;
}Queue;

void initQueue(Queue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	Q->count = 0;
}

void initStack(Stack* S) {
	S->head = NULL;
}

bool isEmptyStack(Stack* S) {
	if (!S->head) {
		return true;
	}
	return false;
}

void push(Stack* S, int x) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = x;
	temp->next = NULL;
	if (isEmptyStack(S)) {
		S->head = temp;
	}
	else {
		temp->next = S->head;
		S->head = temp;
	}
}

int pop(Stack* S) {
	if (isEmptyStack(S)) {
		printf("ERROR: Underflow");
		return -1;
	}
	ListNode* temp = S->head;
	S->head = S->head->next;
	int x = temp->data;
	free(temp);
	return x;
}

void enqueue(Queue* Q, int x) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = x;
	temp->next = NULL;
	if (!Q->count) {
		Q->front = Q->rear = temp;
	}
	else {
		Q->rear->next = temp;
		Q->rear = temp;
	}
	Q->count++;
}

int dequeue(Queue* Q) {
	if (!Q->count) {
		return -1;
	}
	else {
		int x = Q->front->data;
		ListNode* temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
		Q->count--;
		return x;
	}
}


typedef struct node {
    int point;
    int weight;
    struct node* next;
}node;

typedef struct graph {
	struct node **head;
    int size;
}graph;

void insertNode(graph* G, int x, int position, int adjacent) {
    if (!G->head) {
        return;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp->weight = x;
    temp->next = NULL;
    temp->point = adjacent;
    if (!G->head[position]) {
        G->head[position] = temp;
        return;
    }
    temp->next = G->head[position];
    G->head[position] = temp;
}

void BFS(graph* G, Queue* Q) {
    int visited[G->size];
    for (int i=0; i<G->size; i++) {
        visited[i] = 0;
    }
    int v = 0;
    enqueue(Q, v);
    visited[v] = 1;
    while (Q->count) {
        v = dequeue(Q);
        printf("%d ",v);
        node* temp = G->head[v];
        while (temp) {
            if (!visited[temp->point]) {
                enqueue(Q, temp->point);
                visited[temp->point] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFS(graph* G, Stack* S) {
    int visited[G->size];
    for (int i=0; i<G->size; i++) {
        visited[i] = 0;
    }
    int v = 0;
    push(S, v);
    visited[v] = 1;
    while (!isEmptyStack(S)) {
        v = pop(S);
        printf("%d ",v);
        node* temp = G->head[v];
        while (temp) {
            if (!visited[temp->point]) {
                push(S, temp->point);
                visited[temp->point] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void initGraph(graph* G, char* file) {
    int temp;
    FILE *f = fopen(file, "r");
    fscanf(f, "%d", &G->size);
    G->head = (node**)malloc(sizeof(node*)*G->size);
    for (int i=0; i<G->size; i++) {
        G->head[i] = NULL;
    }
    for (int i=0; i<G->size; i++) {
        for (int j=0; j<G->size; j++) {
            fscanf(f, "%d", &temp);
            if (temp) {
                insertNode(G, temp, i, j);
            }
        }
    }
}

bool isAdjacent(graph* G, int i, int j) {
    node* temp = G->head[i];
    while (temp) {
        if (temp->point == j) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}   

void Prim(graph* G) {
    // Keep track of visited vertices
    int visited[G->size];
    for (int i=0; i<G->size; i++) {
        visited[i] = 0;
    }
    // Keep track of visited edges
    int edges = 0, length = 0;
    visited[0] = 1;
    int x, y, min;
    while (edges < G->size-1) {
        x = 0; 
        y = 0;
        min = INT_MAX;  
        for (int i=0; i<G->size; i++) {
            if (visited[i]) {
                for (int j=0; j<G->size; j++) {
                    if (!visited[j] && isAdjacent(G,i,j) && min > G->head[i]->weight) {
                        min = G->head[i]->weight;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        length += min;
        edges++;
        visited[y] = 1;
        printf("%d -> %d | %d\n",x,y,min);
    }
    printf("Length of spanning tree: %d\n",length);
}

int main(int argc, char* argv[]) {
    Queue Q;
    Stack S;
    initStack(&S);
    initQueue(&Q);
    graph G;
    initGraph(&G, argv[1]);
    printf("BFS Traversal: ");
    BFS(&G, &Q);
    printf("DFS Traversal: ");
    DFS(&G, &S);
    printf("Prim's Algorithm: \n");
    Prim(&G);
    return 0;
}
