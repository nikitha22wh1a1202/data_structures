#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* create()
{
    int input, data;
    printf("Do you want to add a node? (0 for NO and 1 for YES): ");
    scanf("%d", &input);

    if (!input)
    {
        return NULL;
    }
    else
    {
        struct node* newNode = malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
        newNode->data = data;

        printf("Left child of %d \n", newNode->data);
        newNode->left = create();

        printf("Right child of %d \n", newNode->data);
        newNode->right = create();

        return newNode;
    }
}

void display(struct node* root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main()
{
    struct node* root = create();

    printf("\nBinary Tree (inorder traversal): ");
    display(root);

    return 0;
}

