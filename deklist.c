// MORA DA SE ZNA NAPAMET
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definicija strukture čvora
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Definicija strukture deka
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Funkcija za kreiranje novog čvora
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Funkcija za kreiranje deka
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// Funkcija za proveru da li je dek prazan
int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

// Funkcija za umetanje elementa na početak deka
void insertFront(Deque* deque, int item) {
    Node* newNode = createNode(item);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("%d umetnuto na početak deka\n", item);
}

// Funkcija za umetanje elementa na kraj deka
void insertRear(Deque* deque, int item) {
    Node* newNode = createNode(item);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("%d umetnuto na kraj deka\n", item);
}

// Funkcija za uklanjanje elementa sa početka deka
void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return;
    }
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    printf("%d uklonjeno sa početka deka\n", temp->data);
    free(temp);
}

// Funkcija za uklanjanje elementa sa kraja deka
void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return;
    }
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    printf("%d uklonjeno sa kraja deka\n", temp->data);
    free(temp);
}

// Funkcija za vraćanje elementa sa početka deka bez uklanjanja
int getFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return INT_MIN;
    }
    return deque->front->data;
}

int getRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return INT_MIN;
    }
    return deque->rear->data;
}

int main() {
    Deque* deque = createDeque();

    insertRear(deque, 5);
    insertRear(deque, 10);
    insertFront(deque, 15);
    insertFront(deque, 20);

    printf("Element na početku deka: %d\n", getFront(deque));
    printf("Element na kraju deka: %d\n", getRear(deque));

    deleteFront(deque);
    deleteRear(deque);

    printf("Element na početku deka: %d\n", getFront(deque));
    printf("Element na kraju deka: %d\n", getRear(deque));

    // Oslobađanje memorije
    while (!isEmpty(deque)) {
        deleteFront(deque);
    }
    free(deque);

    return 0;
}