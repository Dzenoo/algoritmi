// MORA DA SE ZNA NAPAMET
#include <stdio.h>
#include <stdlib.h>

// Definicija strukture čvora
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Funkcija za kreiranje novog čvora
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Funkcija za umetanje novog čvora u BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Funkcija za pretragu čvora u BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Funkcija za pronalaženje minimuma u BST
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Funkcija za brisanje čvora iz BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Funkcija za inorder obilazak BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Glavni program za testiranje
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder obilazak pre brisanja: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("Inorder obilazak nakon brisanja 20: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("Inorder obilazak nakon brisanja 30: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("Inorder obilazak nakon brisanja 50: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}