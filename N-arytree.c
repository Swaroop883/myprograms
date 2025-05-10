#include <stdio.h>
#include <stdlib.h>

// Define structure for a tree node
struct Node {
    int value;
    int numChildren;
    struct Node** children;  // Pointer to array of child node pointers
};

// Function to create a new node
struct Node* createNode(int value, int numChildren) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->numChildren = numChildren;

    if (numChildren > 0) {
        newNode->children = (struct Node**)malloc(numChildren * sizeof(struct Node*));
    } else {
        newNode->children = NULL;
    }

    return newNode;
}

// Function to add a child node at given index
void addChild(struct Node* parent, struct Node* child, int index) {
    if (parent != NULL && parent->children != NULL && index < parent->numChildren) {
        parent->children[index] = child;
    }
}

// Recursive function to print the tree (preorder)
void printTree(struct Node* root, int level) {
    if (root == NULL) return;

    // Indent for tree structure
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("Node: %d\n", root->value);

    // Recursively print children
    for (int i = 0; i < root->numChildren; i++) {
        printTree(root->children[i], level + 1);
    }
}

// Recursive function to free memory
void deleteTree(struct Node* root) {
    if (root == NULL) return;

    for (int i = 0; i < root->numChildren; i++) {
        deleteTree(root->children[i]);
    }

    free(root->children);  // Free the array of children
    free(root);            // Free the node itself
}

// MAIN function
int main() {
    // Create root node
    struct Node* root = createNode(1, 3); // Node 1 with 3 children

    // Create children of root
    struct Node* child1 = createNode(2, 2); // Node 2 with 2 children
    struct Node* child2 = createNode(3, 0); // Node 3 with no children
    struct Node* child3 = createNode(4, 1); // Node 4 with 1 child

    // Add children to root
    addChild(root, child1, 0);
    addChild(root, child2, 1);
    addChild(root, child3, 2);

    // Create more nodes
    struct Node* child1_1 = createNode(5, 0);
    struct Node* child1_2 = createNode(6, 0);
    struct Node* child3_1 = createNode(7, 0);

    // Add children to node 2 and node 4
    addChild(child1, child1_1, 0);
    addChild(child1, child1_2, 1);
    addChild(child3, child3_1, 0);

    // Print the tree
    printf("Tree Structure:\n");
    printTree(root, 0);

    // Free memory
    deleteTree(root);

    return 0;
}
