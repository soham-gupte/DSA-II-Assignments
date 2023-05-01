#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "assn_4_header.h"

void init_bst(bstArray* t, int n) {
	t->tree = (int*)malloc(sizeof(int)*n);
	t->size = n;
	for (int i=0;i<n;i++) {
		t->tree[i] = INT_MIN;
	}
}

bool isEmpty_bst(bstArray* t) {
	if (!t->size) {
		return true;
	}
	return false;
}

void insert_bst(bstArray* t, int x) {
	int i=0;
	while ((i<t->size) && (t->tree[i] != INT_MIN)) {
		if (t->tree[i] == x) {
		        return;
		}
 		else if (t->tree[i] > x) {
			i = 2*i + 1;
		}
		else {
			i = 2*i + 2;
		}
	}
	if (i < t->size) {
		t->tree[i] = x;
	}
}	

// 1. Height of BST:



int height_bst(bstArray* t) {
	if (isEmpty_bst(t)) {
		return -1;
	}
	int key = (t->size)-1;
	int height = 0;
	while (t->size >= 0) {
		if (t->tree[key] != INT_MIN) {
			break;
		}
		key--;
	}
	key = key + 1;
	while (key > 1) {
		key = key/2;
		height++;
	}
	return height;
}

// 2. Count of Leaf Nodes

int leaf_nodes(bstArray* t) {
	int count = 0;
	int i = 0;
	while (i < t->size) {
		if (t->tree[i] != INT_MIN && 2*i + 1 >= t->size) {
			count++;
		}
		else if ((t->tree[i] != INT_MIN) && (t->tree[2*i+1] == INT_MIN) && (t->tree[2*i+2] == INT_MIN)) {
			count++;
	        }
		i++;
	}
	return count;
}

// 3. Is Complete?

bool isComplete_bst(bstArray* t) {
	if (isEmpty_bst(t)) {
		return true;
	}
	int i=1;
	while (i < t->size) {
		if (t->tree[i] == INT_MIN && t->tree[i-1] != INT_MIN) {
		       	return false;
		}
		i++;
	}
	return true;	
}	

// 4. Level Order

void LevelOrder(bstArray* t) {
	int i=0;
	while (i < t->size) {
		if (t->tree[i] != INT_MIN) {
			printf("%d\t",t->tree[i]);
		}
		i++;
	}
    printf("\n");
}
