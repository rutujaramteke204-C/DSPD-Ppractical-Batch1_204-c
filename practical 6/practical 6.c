#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function to insert a node into BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to search for a value in BST
void search(struct node* root, int key) {
    if (root == NULL) {
        printf("Value %d not found in the tree.\n", key);
        return;
    }

    if (root->data == key) {
        printf("Value %d found in the tree.\n", key);
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Function to delete only leaf nodes
struct node* deleteLeaf(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else if (root->left == NULL && root->right == NULL) {
        printf("Deleting leaf node with value %d\n", key);
        free(root);
        return NULL;
    } else {
        printf("Node %d is not a leaf node. Cannot delete.\n", key);
    }

    return root;
}

// Function for inorder traversal (for checking)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Search\n2. Insert\n3. Delete Leaf Node\n4. Display (Inorder)\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 2:
                printf("Enter values to insert (-1 to stop): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1)
                        break;
                    root = insert(root, value);
                }
                break;

            case 3:
                printf("Enter leaf value to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}