#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstNode
{
        char data;
        struct bstNode *left;
        struct bstNode *right;
} bstNode;

typedef struct StackNode
{
        bstNode *data;
        struct StackNode *next;
} StackNode;

typedef struct Stack
{
        StackNode *top;
} Stack;

typedef struct StackNodeChar
{
        char data;
        struct StackNodeChar *next;
} StackNodeChar;

typedef struct StackChar
{
        StackNodeChar *top;
} StackChar;

void initStack(Stack *S);
void initStackChar(StackChar *S);
void push(Stack *S, bstNode *x);
void pushChar(StackChar *S, char x);
bstNode *pop(Stack *S);
char popChar(StackChar *S);
bstNode *createNode(char x);
bool isOperand(char x);
bstNode *buildExpressionTree(Stack *S, char *arr);
char *infix_to_postfix(StackChar *S, char *arr);
void displayInorder(bstNode *root);