#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assn3_header.h"

void initStack(Stack *S)
{
        S->top = NULL;
}

void initStackChar(StackChar *S)
{
        S->top = NULL;
}

void push(Stack *S, bstNode *x)
{
        StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
        temp->data = x;
        temp->next = NULL;
        if (!S->top)
        {
                S->top = temp;
        }
        else
        {
                temp->next = S->top;
                S->top = temp;
        }
}

void pushChar(StackChar *S, char x)
{
        StackNodeChar *temp = (StackNodeChar *)malloc(sizeof(StackNodeChar));
        temp->data = x;
        temp->next = NULL;
        if (!S->top)
        {
                S->top = temp;
        }
        else
        {
                temp->next = S->top;
                S->top = temp;
        }
}

bstNode *pop(Stack *S)
{
        if (!S->top)
        {
                return '\0';
        }
        else
        {
                StackNode *temp = S->top;
                bstNode *temp0 = temp->data;
                S->top = S->top->next;
                temp->next = NULL;
                free(temp);
                return temp0;
        }
}

char popChar(StackChar *S)
{
        if (!S->top)
        {
                return '\0';
        }
        else
        {
                StackNodeChar *temp = S->top;
                char temp0 = temp->data;
                S->top = S->top->next;
                temp->next = NULL;
                free(temp);
                return temp0;
        }
}

bstNode *createNode(char x)
{
        bstNode *temp = (bstNode *)malloc(sizeof(bstNode));
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
}

bool isOperand(char x)
{
        if (x >= '0' && x <= '9')
        {
                return true;
        }
        return false;
}

bstNode *buildExpressionTree(Stack *S, char *arr)
{
        int iter = 0;
        while (arr[iter] != '\0')
        {
                if (isOperand(arr[iter]))
                {
                        bstNode *temp = createNode(arr[iter]);
                        push(S, temp);
                }
                else
                {
                        bstNode *temp_root = createNode(arr[iter]);
                        temp_root->right = pop(S);
                        temp_root->left = pop(S);
                        push(S, temp_root);
                }
                iter++;
        }
        return pop(S);
}

char *infix_to_postfix(StackChar *S, char *arr)
{
        int iter = 0;
        int postfix_iter = 0;
        char *postfix_expr = (char *)malloc(sizeof(arr) + 1);
        while (arr[iter] != '\0')
        {
                if (arr[iter] == '(')
                {
                        pushChar(S, arr[iter]);
                }
                else if (arr[iter] == ')')
                {
                        while (S->top && (S->top->data != '('))
                        {
                                postfix_expr[postfix_iter++] = popChar(S);
                        }
                        popChar(S);
                }
                else if (arr[iter] == '*' || arr[iter] == '/')
                {
                        if (S->top && (S->top->data == '*' || S->top->data == '/'))
                        {
                                postfix_expr[postfix_iter++] = popChar(S);
                        }
                        pushChar(S, arr[iter]);
                }
                else if (arr[iter] == '-' || arr[iter] == '+')
                {
                        if (S->top && (S->top->data == '*' || S->top->data == '/'))
                        {
                                postfix_expr[postfix_iter++] = popChar(S);
                        }
                        if (S->top && (S->top->data == '+' || S->top->data == '-'))
                        {
                                postfix_expr[postfix_iter++] = popChar(S);
                        }
                        pushChar(S, arr[iter]);
                }
                else
                {
                        postfix_expr[postfix_iter++] = arr[iter];
                }
                iter++;
        }
        while (S->top)
        {
                postfix_expr[postfix_iter++] = popChar(S);
        }
        postfix_expr[postfix_iter] = '\0';
        return postfix_expr;
}

void displayInorder(bstNode *root)
{
        if (!root)
        {
                return;
        }
        else
        {
                displayInorder(root->left);
                printf("%c ", root->data);
                displayInorder(root->right);
        }
}