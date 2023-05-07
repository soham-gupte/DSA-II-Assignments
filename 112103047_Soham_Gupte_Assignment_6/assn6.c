#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include "assn6_header.h"

int main() {
	srand(time(0));
	Heap max_h, min_h;
	int n, x;
	printf("Enter number of elements to insert into heap: ");
	scanf("%d",&n);

	initHeap(&max_h, n);
        initHeap(&min_h, n);
	
	printf("Elements randomly generated: ");
	while (n--) {
		x = rand()%100;
	       	printf("%d  ",x);
		insertMinHeap(&min_h, x);
		insertMaxHeap(&max_h, x);
	}
	printf("\n");
	n++;
	printf("Level order display of MIN heap:\n");
	displayLevelOrder(&min_h);
	printf("Level order display of MAX heap:\n");
        displayLevelOrder(&max_h);
	printf("After deletion (MIN): ");
	int deleted_pos = min_h.size;
	while (n < min_h.size) {
		deleteMin(&min_h, &deleted_pos);
		n++;
	}
	printf("\n");
	printf("After deletion (MAX): ");
	deleted_pos = max_h.size;
	while (n) {
		deleteMax(&max_h, &deleted_pos);
		n--;
	}
	printf("\n");
	return 0;
}