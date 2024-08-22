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

// Funkcija za umetanje novog čvora u binarno stablo
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

// Funkcija za preorder obilazak stabla
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Funkcija za inorder obilazak stabla
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Funkcija za postorder obilazak stabla
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Funkcija za pretragu čvora u binarnom stablu
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// NE MORA DA SE ZNA NAPAMET

// Funkcija za brisanje čvora iz BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Čvor sa jednom ili nijednom decom
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Čvor sa dva deteta: uzmi inorder naslednika (najmanji u desnom podstablu)
        Node* temp = findMin(root->right);

        // Kopiraj inorder naslednikov sadržaj u ovaj čvor
        root->data = temp->data;

        // Obriši inorder naslednika
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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

    printf("Preorder obilazak: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder obilazak: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder obilazak: ");
    postorderTraversal(root);
    printf("\n");

    Node* found = search(root, 40);
    if (found != NULL) {
        printf("Čvor sa vrednošću 40 pronađen.\n");
    } else {
        printf("Čvor sa vrednošću 40 nije pronađen.\n");
    }

    return 0;
}