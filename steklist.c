// MORA DA SE ZNA NAPAMET
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definicija strukture čvora
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Funkcija za kreiranje novog čvora
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Funkcija za proveru da li je stek prazan
int isEmpty(Node* root) {
    return !root;
}

// Funkcija za dodavanje elementa na stek
void push(Node** root, int data) {
    Node* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
    printf("%d dodato na stek\n", data);
}

// Funkcija za uklanjanje elementa sa steka
int pop(Node** root) {
    if (isEmpty(*root)) {
        printf("Stek je prazan\n");
        return INT_MIN;
    }
    Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Funkcija za vraćanje elementa sa vrha steka bez uklanjanja
int peek(Node* root) {
    if (isEmpty(root)) {
        return INT_MIN;
    }
    return root->data;
}

// Glavni program za testiranje
int main() {
    Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("%d uklonjeno sa steka\n", pop(&root));
    printf("Element na vrhu steka je %d\n", peek(root));

    return 0;
}