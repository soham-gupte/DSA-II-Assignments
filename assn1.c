#include <stdio.h>
#include <stdlib.h>
#include "assn1_header.h"

int main() {
        Queue Q;
        initQueue(&Q);
        bstNode* root = NULL; // Consider a sample binary tree
        root = insert(root, 20);
        root = insert(root, 10);
        root = insert(root, 40);
        root = insert(root, 30);
        root = insert(root, 60);
        LevelOrderDisplay(root, &Q);
}

