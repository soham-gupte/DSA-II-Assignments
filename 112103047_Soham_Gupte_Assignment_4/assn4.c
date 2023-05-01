#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "assn_4_header.h"

int main() {
	bstArray t;
	int n, x;
	printf("Enter the number of elements you want to add in the BST: ");
	scanf("%d",&n);
	init_bst(&t, n);
    printf("Elements that you want in BST: ");
	while (n) {
		scanf("%d",&x);
		if (!x) {
			break;
		}
		insert_bst(&t, x);
		n--;
	}
	printf("Level Order display of BST: ");
	LevelOrder(&t);

	printf("Height of BST: %d\n",height_bst(&t));
	printf("Count of leaf nodes of BST: %d\n",leaf_nodes(&t));
	printf("Is BST Complete? ==> %d\n",isComplete_bst(&t));

	return 0;
}
