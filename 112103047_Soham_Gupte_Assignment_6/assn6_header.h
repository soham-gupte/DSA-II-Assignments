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
void deleteMin(Heap* h, int* deleted_pos);
void deleteMax(Heap* h, int* deleted_pos);
bool isHeapEmpty(Heap* h);
void swap(int* a, int* b);
void delete(Heap* h, int* deleted_pos);
void heapifyMin(Heap* h, int* deleted_pos);
void heapifyMax(Heap* h, int* deleted_pos);
