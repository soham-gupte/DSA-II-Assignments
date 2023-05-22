#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int size;
	int** node;
}graph;

typedef struct queueNode {
	int data;
	struct queueNode* next;
}queueNode;

typedef struct Queue {
	queueNode* front, rear;
	int count;
}Queue;

void initQueue(Queue* Q) {
	Q->front = Q->rear = NULL;
	Q->count = 0;
}

void enqueue(Queue* Q, int x) {
	queueNode* temp = (queueNode*)malloc(sizeof(queueNode));
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
		queueNode* temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
		Q->count--;
		return x;
	}
}

void initGraph(graph* G, char* file) {
	
	FILE *f = fopen(file, "r");
	fscanf(f, "%d", &G->size);

	G->node = (int**)malloc(sizeof(int*)*G->size);
	for (int i=0; i<G->size; i++) {
		G->node[i] = (int*)malloc(sizeof(int)*G->size);
		for (int j=0; j<G->size; j++) {
			fscanf(f, "%d", &G->node[i][j]);
		}
	}

	fclose(f);

}

void displayGraph(graph* G) {
	printf("Adjacency matrix of graph:\n");
	for (int i=0; i<G->size; i++) {
		for (int j=0; j<G->size; j++) {
			printf("%d ",G->node[i][j]);
		}
		printf("\n");
	}
}

void displayDegree(graph* G) {
	printf("Display degree of nodes: \n");
	int count;
	for (int i=0; i<G->size; i++) {
		count = 0;
		printf("Degree of node %d: ",i+1);
                for (int j=0; j<G->size; j++) {
                        if (G->node[i][j]) {
				count++;
			}
                }
                printf("%d\n",count);
        }
}

//void isConnected(graph* G) {
//	int j;
//	printf("Graph is: ");
//	for (int i=1; i<G->size; i++) {
//		while (
		

int main() {
	graph G;
	initGraph(&G, "graph.txt");
	//displayGraph(&G);
	//displayDegree(&G);
	return 0;
}
