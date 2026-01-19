#include <stdio.h>
#include <stdlib.h>

/* BST Node definition */
struct Node {
    int imageID;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int id) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->imageID = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert image ID into BST */
struct Node* insert(struct Node *root, int id) {
    if (root == NULL)
        return createNode(id);

    if (id < root->imageID)
        root->left = insert(root->left, id);
    else if (id > root->imageID)
        root->right = insert(root->right, id);

    return root;
}

/* Preorder traversal: Root -> Left -> Right */
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->imageID);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Find the largest image ID */
int findLargest(struct Node *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }

    while (root->right != NULL)
        root = root->right;

    return root->imageID;
}

int main() {
    struct Node *root = NULL;
    int n, id;

    printf("Enter number of CT images: ");
    scanf("%d", &n);

    printf("Enter image IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        root = insert(root, id);
    }

    printf("\nPreorder Traversal (Indexed Image IDs): ");
    preorder(root);

    int largest = findLargest(root);
    if (largest != -1)
        printf("\nLargest Image ID: %d\n", largest);

    return 0;
}
