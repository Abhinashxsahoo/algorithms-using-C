#include <stdio.h>
#include <stdlib.h>
typedef struct Node {int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return NULL;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            Node* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}
void printTree(Node* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main() {
    Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);
    printf("Original tree: ");
    printTree(root);
    printf("\n");

    root = deleteNode(root, 5);

    root = deleteNode(root, 3);
    printf("Tree after deletion: ");
    printTree(root);
    printf("\n");

    return 0;
}
