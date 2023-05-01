#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assn3_header.h"

int main()
{
        int n = 0;
        printf("Input size of input (should be ATLEAST the length of the desired output) : ");
        scanf("%d", &n);

        printf("Input the string: ");
        char *s = (char *)malloc(n + 1);
        scanf("%s", s);

        // char s[] = "2-3/(5*2)+1";
        printf("String taken as input: %s\n", s);
        StackChar S1; // Initialising stack for converting infix to postfix expression
        Stack S2;     // Initialising stack for inserting nodes in bst
        initStackChar(&S1);
        initStack(&S2);

        char *postfix_arr = (char *)malloc(sizeof(s) + 1); // Mallocing space to store postfix expression
        postfix_arr = infix_to_postfix(&S1, s);
        printf("Postfix conversion: %s\n", postfix_arr);

        bstNode *root = NULL;
        root = buildExpressionTree(&S2, postfix_arr); // Creating the expression tree using postfix expression
        printf("Inorder display of expression tree: ");
        displayInorder(root); // Inorder Traversal display
        printf("\n");
        return 0;
}
