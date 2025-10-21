#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue node for building tree
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

// Simple queue for tree nodes
struct Queue {
    struct QueueNode *front, *rear;
};

// Function declarations
void enqueue(struct Queue *q, struct TreeNode* node);
struct TreeNode* dequeue(struct Queue *q);
int isEmpty(struct Queue *q);

struct TreeNode* newNode(int val);
int max(int a, int b);
int maxPathDown(struct TreeNode* node);
int maxPathSum(struct TreeNode* root);
struct TreeNode* buildTree(int nodes[], int n);

int main() {
    int n;
    scanf("%d", &n);

    int *nodes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i]);
    }

    struct TreeNode* root = buildTree(nodes, n);
    int result = maxPathSum(root);
    printf("%d\n", result);

    free(nodes);
    return 0;
}