#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstNode {
    int val;
    struct bstNode* left;
    struct bstNode* right;
}bstNode;

typedef struct ListNode {
	bstNode* data;
	struct ListNode* next;
}ListNode;

typedef struct List {
	ListNode* head;
	int count;
}List;

void initList(List* L);
void insertListNode(List* L, bstNode* x);
void Inorder(bstNode* root);
bool isValidBST(bstNode* root, int minValue, int maxValue, List* L);
bstNode* insert(bstNode* root, int x);
void swapVal(bstNode* p1, bstNode* p2);