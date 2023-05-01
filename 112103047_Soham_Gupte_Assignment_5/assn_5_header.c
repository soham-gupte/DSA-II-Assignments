#include <stdio.h>
#include <stdlib.h>
#include "assn_5_header.h"

AVL_node* init_AVL(AVL_node* root) {
	return NULL;
} 

void enqueue(Queue* Q, AVL_node* x) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = x;
	temp->next = NULL;
	if (!Q->count) {
		Q->front = Q->rear = temp;
	}
	else {
		Q->rear->next = temp;
		Q->rear = Q->rear->next;
	}
	Q->count++;
}

AVL_node* dequeue(Queue* Q) {
    if (Q->count) {
        QueueNode* temp = Q->front;
        AVL_node* x = temp->data;
        Q->front = Q->front->next;
        temp->next = NULL;
        free(temp);
        Q->count--;
        return x;
    }
    else {
        return NULL;
    }
}

int max(int a, int b) {
	if (a>b) {
		return a;
	}
	return b;
}

int height(AVL_node* root) {
	if (!root) {
		return -1;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

AVL_node* update_bf(AVL_node* root) {
    root->bf = height(root->left) - height(root->right);
    return root;
}

AVL_node* LL_rotate(AVL_node* x) {
    AVL_node* y = x->left;
    AVL_node* a = y->right;
    y->right = x;
    x->left = a;
    update_bf(x);
    update_bf(y);
    return y;
}

AVL_node* RR_rotate(AVL_node* x) {
    AVL_node* y = x->right;
    AVL_node* a = y->left;
    y->left = x;
    x->right = a;
    update_bf(x);
    update_bf(y);
    return y;
}

AVL_node* LR_rotate(AVL_node* x) {
    x->left = RR_rotate(x->left);
    return LL_rotate(x);
}

AVL_node* RL_rotate(AVL_node* x) {
    x->right = LL_rotate(x->right);
    return RR_rotate(x);
}

AVL_node* insert_AVL(AVL_node* root, int x) {
    if (!root) {
        AVL_node* temp = (AVL_node*)malloc(sizeof(AVL_node));
        temp->bf = 0;
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (x < root->data) {
        root->left = insert_AVL(root->left, x);
    }
    else if (x > root->data) {
        root->right = insert_AVL(root->right, x);
    } 

    root = update_bf(root);

    // LL Rotation
    if ((root->bf > 1) && (x < root->left->data)) {
        return LL_rotate(root);
    }
    // RR Rotation
    else if ((root->bf < -1) && (x > root->right->data)) {
        return RR_rotate(root);
    }
    // LR Rotation
    else if ((root->bf > 1) && (x > root->left->data)) {
        return LR_rotate(root);
    }
    // RL Rotation
    else if ((root->bf < -1) && (x < root->right->data)) {
        return RL_rotate(root);
    }

    return root;

}

AVL_node* FindMin(AVL_node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

AVL_node* delete_AVL(AVL_node* root, int target) {
    if (!root) {
        return root;
    }
    else if (target < root->data) {
        root->left = delete_AVL(root->left, target);
    }
    else if (target > root->data) {
        root->right = delete_AVL(root->right, target);
    }
    else {
        // Case 1:
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        // Case 2: 
        else if (root->left && !root->right) {
            AVL_node* temp1 = root;
            AVL_node* temp2 = temp1->left; 
            temp1->left = NULL;
            free(temp1);
            return temp2;
        }
        else if (!root->left && root->right) {
            AVL_node* temp1 = root;
            AVL_node* temp2 = temp1->right; 
            temp1->right = NULL;
            free(temp1);
            return temp2;
        }
        // Case 3:
        else if (root->left && root->right) {
            AVL_node* temp1 = FindMin(root->right);
            root->data = temp1->data;
            root->right = delete_AVL(temp1, temp1->data);
        }
    }

    update_bf(root);

    if ((root->left) && (root->bf > 1) && (root->left->bf >= 0)) {
        return LL_rotate(root);
    }
    else if ((root->left) && (root->bf > 1) && (root->left->bf < 0)) {
        return LR_rotate(root);
    }
    else if ((root->right) && (root->bf < -1) && (root->right->bf > 0)) {
        return RR_rotate(root);
    }
    else if ((root->right) && (root->bf < -1) && (root->right->bf <= 0)) {
        return RL_rotate(root);
    }

    return root;

}

void Inorder(AVL_node* root) {
    if (root) {
        Inorder(root->left);
        printf("%d - %d\n",root->data, root->bf);
        Inorder(root->right);
    }
}

void Preorder(AVL_node* root) {
    if (root) {
        printf("%d\n",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(AVL_node* root) {
    if (root) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\n",root->data);
    }
}

void LevelOrder(AVL_node* root, Queue* Q) {
	while (root) {
		printf("%d - %d\n",root->data, root->bf);
		if (root->left) {
			enqueue(Q, root->left);
		}
		if (root->right) {
			enqueue(Q, root->right);
		}
		root = dequeue(Q);
	}
}

AVL_node* destroy_AVL(AVL_node* root) {
    free(root);
    return NULL;
}
