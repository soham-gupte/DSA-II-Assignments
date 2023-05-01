#include <stdio.h>
#include <stdlib.h>
#include "assn1_header.h"

int main() {
        Queue Q;
        initQueue(&Q);
	int size, element;
        bstNode* root = NULL; // Consider a sample binary tree
	printf("Enter number of elements to insert in BST: ");
	scanf("%d",&size);
	printf("Enter elements: ");
	while (size) {
		scanf("%d",&element);
		root = insert(root, element);
		size--;
	}
        //root = insert(root, 20);
//        root = insert(root, 10);
  //      root = insert(root, 40);
    //    root = insert(root, 30);
      //  root = insert(root, 60);
	printf("Output level order: ");
        LevelOrderDisplay(root, &Q);
}

