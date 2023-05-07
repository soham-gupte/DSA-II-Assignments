#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include "assn6_header.h"

void swap(int *x,int *y){
    if (*x == *y) {
		return;
	}
	*x = *y + *x;
	*y = *x - *y;
	*x = *x - *y;
}

void initHeap(Heap* h, int n) {
	h->size = n;
	h->arr = (int*)malloc(sizeof(int)*n);
	while (n--) {
		h->arr[n] = INT_MIN;
	}
}

bool isFullHeap(Heap* h) {
	if (h->arr[h->size - 1] != INT_MIN) {
		return true;
	}
	return false;
}

bool isHeapEmpty(Heap* h) {
	if (h->size == 0) {
		return true;
	}
	return false;
}

void insertMaxHeap(Heap* h, int x) {
	if (isFullHeap(h)) {
		printf("Heap is full! Cannot insert\n");
		return;
	}
	int i = 0;
	while (i < h->size && h->arr[i] != INT_MIN) {
		i++;
	}
	h->arr[i] = x;
	while (i > 0 && x > h->arr[(i-1)/2]) {
	        h->arr[i] = h->arr[(i-1)/2];	  
	        i = (i-1)/2;
	}	
	h->arr[i] = x;
}

void insertMinHeap(Heap* h, int x) {
	if (isFullHeap(h)) {
                printf("Heap is full! Cannot insert\n");
		return;
        }
	int i = 0;
	while (i < h->size && h->arr[i] != INT_MIN) {
			i++;
	}
	h->arr[i] = x;
	while (i > 0 && x < h->arr[(i-1)/2]) {
			h->arr[i] = h->arr[(i-1)/2];
			i = (i-1)/2;
	}
	h->arr[i] = x;
}

void delete(Heap* h, int* deleted_pos) {
	if (isHeapEmpty(h)) {
		printf("Cannot delete! Underflow!");
		return;
	}

	(*deleted_pos)--;
	swap(&h->arr[0], &h->arr[*deleted_pos]);
	
	int x = h->arr[0];
}

void heapifyMin(Heap* h, int* deleted_pos) {
	int i=0;
	while (2*i+1 < *deleted_pos) {
		if (2*i+2 < *deleted_pos && h->arr[i] > h->arr[2*i+2] && h->arr[2*i+2] < h->arr[2*i+1]) {
			swap(&h->arr[i], &h->arr[2*i+2]);
			i = 2*i+2;
		}
		else if (h->arr[i] > h->arr[2*i+1]) {
			swap(&h->arr[i], &h->arr[2*i+1]);
			i = 2*i+1;
		}
		else {
			return;
		}
	}
}

void heapifyMax(Heap* h, int* deleted_pos) {
	int i=0;
	while (2*i+1 < *deleted_pos) {
		if (2*i+2 < *deleted_pos && h->arr[i] < h->arr[2*i+2] && h->arr[2*i+2] > h->arr[2*i+1]) {
			swap(&h->arr[i], &h->arr[2*i+2]);
			i = 2*i+2;
		}
		else if (h->arr[i] < h->arr[2*i+1]) {
			swap(&h->arr[i], &h->arr[2*i+1]);
			i = 2*i+1;
		}
		else {
			return;
		}
	}
}

void deleteMin(Heap* h, int* deleted_pos) {
	
	delete(h, deleted_pos);
	// Display deleted element:
	printf("%d  ",h->arr[*deleted_pos]);
	// Heapify it!
	heapifyMin(h, deleted_pos);

}

void deleteMax(Heap* h, int* deleted_pos) {
	
	delete(h, deleted_pos);
	// Display deleted element:
	printf("%d  ",h->arr[*deleted_pos]);
	// Heapify it!
	heapifyMax(h, deleted_pos);

}

void displayLevelOrder(Heap* h) {
	int i = 0;
	while (i < h->size) {
		printf("%d  ",h->arr[i]);
		i++;
	}
	printf("\n");
}
