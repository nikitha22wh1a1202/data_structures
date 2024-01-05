#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    // If the tree is empty or the key is present at the root
    // or if the key is in the left or right subtree
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than the root's key
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than the root's key
    return search(root->left, key);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    int n, key;

    // Get the number of nodes from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Insert nodes into the BST based on user input
    printf("Enter the key values:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Ask the user for the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Search for the key in the BST
    struct Node* result = search(root, key);

    // Display the search result
    if (result != NULL) {
        printf("Key %d found in the BST.\n", key);
    } else {
        printf("Key %d not found in the BST.\n", key);
    }

    return 0;
}

