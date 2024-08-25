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

// Funkcija za umetanje elementa na kraj deka
void insert(Deque* deque, int item) {
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

// Funkcija za uklanjanje elementa sa kraja deka
void delete(Deque* deque) {
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

int get(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return INT_MIN;
    }
    return deque->rear->data;
}

int main() {
    Deque* deque = createDeque();

    insert(deque, 5);
    insert(deque, 10);

    printf("Element na kraju deka: %d\n", get(deque));

    delete(deque);

    printf("Element na kraju deka: %d\n", get(deque));


    return 0;
}