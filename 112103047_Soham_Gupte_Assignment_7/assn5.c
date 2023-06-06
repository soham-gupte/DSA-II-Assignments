#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph {
	int size;
	int** node;
}graph;

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
		temp->next = S->head->next;
		S->head->next = temp;
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

bool isEmptyQueue(Queue* Q) {
	if (!Q->count) {
		return true;
	}
	return false;
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

bool isConnected(graph* G, Queue* Q) {
	bool visited[G->size];
	for (int i = 0; i < G->size; i++) {
		visited[i] = false;
	}
	// Now we visit first node
	enqueue(Q, 0);
	int v;
	while (!isEmptyQueue(Q)) {
		v = dequeue(Q);
		visited[v] = true;
		for (int i=0; i<G->size; i++) {
			if (!visited[i] && G->node[v][i]) {
				enqueue(Q, i);
			}
		}
	}
	// Now check if all nodes are visited, if not, return false
	for (int i=0; i<G->size; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

void dfs(graph* G, Stack* S, int start, int* visited) {
	if (!G->size) {
		printf("No DFS possible!");
		return;
	}
	printf("DFS Traversal starting with %d: ",start);
	int v;
	push(S, start);
	visited[start] = 1;
	printf("%d  ",start);
	while (!isEmptyStack(S)) {
		v = pop(S);
		printf("%d ",v);
		for (int i=0; i<G->size; i++) {
			if (G->node[v][i] && !visited[i]) {
				push(S, i);
				visited[i] = 1;
				// printf("%d  ",i);
			}
		}
	}
	printf("\n");
}

int numberOfComponents(graph* G, Stack* S) {
	int componentCount = 0;
	int visited[G->size];
	for (int i=0; i<G->size; i++) {
		visited[i] = 0;
	}
	for (int i=0; i<G->size; i++) {
		if (!visited[i]) {
			dfs(G, S, i, visited);
			componentCount++;
		}
	}
	return componentCount;
}

bool isAdjacent(graph* G, int a, int b) {
	if (G->node[a][b]) {
		return true;
	}
	return false;
}

void cycle_recurse(graph* G, int* visited, int parent, int current, int* pathLength) {
	visited[current] = 1;
	for (int i=0; i<G->size; i++) {
		if (parent == current && G->node[i][parent]) {
			current = i;
			visited[current] = 1;
			continue; 
		}
		if (current != parent && G->node[current][i] && visited[i]) {
			printf("Cycle found of path length: %d\n",*pathLength);
			visited[i] = 0;
			*pathLength = 0;
		}
		else if (!visited[i] && G->node[current][i]) {
			*(pathLength)++;
			cycle_recurse(G, visited, current, i, pathLength);
			*(pathLength)--;
			visited[i] = 0;
		}
	}
	visited[current] = 0;
}

void Cycles(graph* G) {
	int visited[G->size];
	int cycleCount = 0;
	int* pathLength;
	*pathLength = 0;
	for (int i = 0; i < G->size; i++) {
		visited[i] = 0;
	}
	for (int i=0; i<G->size; i++) {
		cycle_recurse(G, visited, i, 0, pathLength);
	}
}

int main(int argc, char *argv[]) {
	graph G;
	Queue Q;
	Stack S;
	initGraph(&G, argv[1]);
	displayGraph(&G);
	displayDegree(&G);
	printf("Is the graph connected: %d\n",isConnected(&G, &Q));
	printf("Number of components: %d\n",numberOfComponents(&G, &S));
	printf("Are 1 and 3 adjacent?: %d\n",isAdjacent(&G, 1, 3));
	// Cycles(&G);
	return 0;
}
