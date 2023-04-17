#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assn_2_header.h"

void initList(List* L) {
	L->head = NULL;
	L->count = 0;
}

void insertListNode(List* L, bstNode* x) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->next = NULL;
	temp->data = x;
	if (!L->head) {
		L->head = temp;
	}
	else {
		temp->next = L->head->next;
		L->head->next = temp;
	}
	L->count++;
}
	
void Inorder(bstNode* root) {
	if (!root) {
		return;
	}	
	else {
		Inorder(root->left);
		printf("%d\t",root->val);
		Inorder(root->right);
	}
}

bool isValidBST(bstNode* root, int minValue, int maxValue, List* L) {
	if (!root) {
		return true;
	}
	if (root->val > minValue && 
			 root->val < maxValue && 
			 isValidBST(root->left, minValue, root->val, L) && 
			 isValidBST(root->right, root->val, maxValue, L)) {

				return true;
			 }
	else {
		insertListNode(L, root);
		return true;
	}
}

bstNode* insert(bstNode* root, int x) {
        if (!root) {
                bstNode* temp = (bstNode*)malloc(sizeof(bstNode));
                temp->val = x;
                temp->left = temp->right = NULL;
                root = temp;
        }
        else if (x < root->val) {
                root->left = insert(root->left, x);
        }
        else {
                root->right = insert(root->right, x);
        }
        return root;
}

void swapVal(bstNode* p1, bstNode* p2) {
	p1->val = p1->val + p2->val;
	p2->val = p1->val - p2->val;
	p1->val = p1->val - p2->val;
}