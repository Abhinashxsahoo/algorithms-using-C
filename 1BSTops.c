#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *newNode(int data) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(int data, struct node *root) {
    if (root == NULL) 
        return newNode(data);
    if (data < root->data)
        root->left = insert(data, root->left);
    else if (data > root->data)
        root->right = insert(data, root->right);
    return root;
}

struct node *Min(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node *deletenode(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deletenode(root->left, data);
    } else if (data > root->data) {
        root->right = deletenode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = Min(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(struct node *root) {
    if(root != NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root=insert(100,root);
    root=insert(80,root);
    root=insert(120,root);
    root=insert(60,root);
    root=insert(90,root);
    root=insert(110,root);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    root = deletenode(root, 100);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal after deletion: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal after deletion: ");
    postorder(root);
    printf("\n");

    return 0;
}