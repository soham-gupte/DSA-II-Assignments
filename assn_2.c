#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assn_2_header.h"

int main() {
	List L;
	initList(&L);

	bstNode* root = NULL; // Consider a sample binary tree
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 60);

	root->left->val = root->val;
	root->val =  10;
	Inorder(root);
	printf("\n");
	insertListNode(&L, root);
	isValidBST(root, INT_MIN, INT_MAX, &L);
	bstNode* p1 = NULL;
	bstNode* p2 = NULL;
	if (L.count == 3) {
		p1 = L.head->next->data;
		p2 = L.head->next->next->data;
	}
	else if (L.count == 2) {
		p1 = L.head->data;
		p2 = L.head->next->data;
	}
	else {
		printf("No change in BST!\n");
	}
	swapVal(p1, p2);
	Inorder(root);
}
