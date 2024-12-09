#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100 

typedef struct CompleteBinaryTree {
    int arr[SIZE];
    int size; 
} CompleteBinaryTree;


void initializeTree(CompleteBinaryTree* tree) {
    tree->size = 0;
}


void insert(CompleteBinaryTree* tree, int value) {
    if (tree->size== SIZE) {
        printf("Tree is full!\n");
        return;
    }
    tree->arr[tree->size++]= value;
    printf("Inserted %d\n", value);
}


int getLastIndex(CompleteBinaryTree* tree) {
    return tree->size- 1;
}


void deleteNode(CompleteBinaryTree* tree) {
    if(tree->size== 0) {
        printf("Tree is empty!\n");
        return;
    }
    int lastValue= tree->arr[getLastIndex(tree)];
    tree->size--;
    printf("Deleted node with value %d\n",lastValue);
}


void inorderTraversal(CompleteBinaryTree* tree, int index) {
    if(index >= tree->size) return;

    inorderTraversal(tree, 2 * index + 1); 
    printf("%d ", tree->arr[index]);
    inorderTraversal(tree, 2 * index + 2);  
}


void preorderTraversal(CompleteBinaryTree* tree, int index) {
    if (index>= tree->size) return;

    printf("%d ",tree->arr[index]);
    preorderTraversal(tree, 2 * index + 1);  
}


void postorderTraversal(CompleteBinaryTree* tree, int index) {
    if(index >= tree->size) return;

    postorderTraversal(tree, 2 * index + 1);  
    postorderTraversal(tree, 2 * index + 2);  
    printf("%d ",tree->arr[index]);
}


void levelOrderTraversal(CompleteBinaryTree* tree) {
    if(tree->size == 0) {
        printf("Tree is empty!\n");
        return;
    }
    printf("Level Order: ");
    for(int i = 0; i < tree->size; i++) {
        printf("%d ", tree->arr[i]);
    }
    printf("\n");
}


void search(CompleteBinaryTree* tree, int value) {
    for(int i = 0; i < tree->size; i++) {
        if(tree->arr[i]== value) {
            printf("Element %d found at position %d\n",value, i + 1);
            return;
        }
    }
    printf("Element %d not found in the tree.\n", value);
}

int main() {
    CompleteBinaryTree tree;
    initializeTree(&tree);

    int choice, value;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Level Order Traversal\n");
        printf("7. Search\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&tree, value);
                break;

            case 2:
                deleteNode(&tree);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(&tree, 0);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(&tree, 0);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorderTraversal(&tree, 0);
                printf("\n");
                break;

            case 6:
                levelOrderTraversal(&tree);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d",&value);
                search(&tree,value);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
