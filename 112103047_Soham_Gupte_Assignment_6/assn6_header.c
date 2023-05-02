#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include "assn6_header.h"

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

void displayLevelOrder(Heap* h) {
	int i = 0;
	while (i < h->size) {
		printf("%d  ",h->arr[i]);
		i++;
	}
	printf("\n");
}
