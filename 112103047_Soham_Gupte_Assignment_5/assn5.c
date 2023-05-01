#include <stdio.h>
#include <stdlib.h>
#include "assn_5_header.h"

int main() {

    AVL_node* root;
    Queue Q;
    Q.front = Q.rear = NULL;
    Q.count = 0;

    int choice = 1;
    while (choice) {
        printf("1 - Initialise AVL tree\n");
        printf("2 - Insert node into AVL tree\n");
        printf("3 - Remove a node from the AVL tree\n");
        printf("4 - Display AVL tree using traversal methods\n");
        printf("5 - Destroy entire AVL tree\n");
        printf("0 - Quit the program\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
        case 0 :
            printf("Program has ended, thank you!\n");            
            break;

        case 1 :
            root = init_AVL(root);
            printf("AVL tree has been initialised!\n");
            break;

        case 2 :
            // Make sure AVL is initialised first!
            int x;
            printf("Enter data to be inserted into AVL tree: ");
            scanf("%d",&x);
            root = insert_AVL(root, x);
            break;

        case 3 :
            int target;
            printf("Enter element to be removed from AVL tree: ");
            scanf("%d",&target);
            root = delete_AVL(root, target);
            break;

        case 4 :
            printf("Level order traversal along with balance factors: \n");
            LevelOrder(root, &Q);
            break;

        case 5 :
            root = destroy_AVL(root);
            printf("AVL tree has been successfully destroyed!\n");
            break;

        }

    }
    return 0;

}