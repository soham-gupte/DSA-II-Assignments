#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct bstArray {
	int* tree;
	int size;
}bstArray;

void init_bst(bstArray* t, int n);
bool isEmpty_bst(bstArray* t);
void insert_bst(bstArray* t, int x);

int height_bst(bstArray* t);

int leaf_nodes(bstArray* t);

bool isComplete_bst(bstArray* t);

void LevelOrder(bstArray* t);