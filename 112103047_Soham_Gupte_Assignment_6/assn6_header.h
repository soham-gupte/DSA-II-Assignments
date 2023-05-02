#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

typedef struct Heap {
	int* arr;
	int size;
}Heap;

void initHeap(Heap* h, int n);
bool isFullHeap(Heap* h);
void insertMaxHeap(Heap* h, int x);
void insertMinHeap(Heap* h, int x);
void displayLevelOrder(Heap* h);
