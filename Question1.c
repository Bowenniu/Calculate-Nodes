#include <stdio.h>
#include <stdlib.h>

// Definition of a TreeNode struct for binary tree nodes.
struct TreeNode {
    int value; // Value of the node
    struct TreeNode* left; // Left child
    struct TreeNode* right; // Right child
};
// Create new TreeNode with the given value
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode -> value = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
// Create function to count the total number of nodes in the binary tree
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
    return 0;
    }
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}
// Create function to count the number of the leaf nodes
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root -> left == NULL && root -> right == NULL) {
        return 1;
    }
    return countLeafNodes(root -> left) + countLeafNodes(root -> right);
}
// Create function to print a binary tree in a preorder traversal with identification
void printTree (struct TreeNode* root, int level) {
    if (root == NULL)
        return;
    printTree(root -> right, level + 1); //Print right subtree
    printf("%d ", root -> value); // Print the root
    for (int i = 0; i < level; i++)
        printf(" "); // Print identation based on the level
    printTree(root -> left, level + 1); // Print the left subtree
}

int main() { 
    // Build a binary tree
    struct TreeNode* root = createNode(1);
    root -> left = createNode(2);
    root -> right = createNode(3);
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);
    // Print the number of nodes and leaf nodes
    printf("Total nodes: %d\n", countNodes(root));
    printf("Leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}

/*
This program is designed to handle and display a binary tree. First, define a struct called TreeNode which represents 
each node in the binary tree. Each node has an integer value, along with two pointers that point to its left child and right child, 
respectively. Then, create a function createNode which is used to create a new node, initializing its value and setting both its 
left and right child pointers to NULL. 
The TreeNode struct encapsulates the basic properties of a node in a binary tree: its integer value and pointers to its left and right 
children. The createNode function dynamically allocates memory for a new TreeNode instance, initializes its value to the given integer, 
and sets its left and right child pointers to NULL, indicating it is initially a leaf node with no children.
*/