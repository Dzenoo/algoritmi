#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definicija strukture čvora
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definicija strukture reda
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Funkcija za kreiranje novog čvora
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Funkcija za kreiranje reda
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Funkcija za proveru da li je red prazan
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Funkcija za dodavanje elementa na kraj reda
void enqueue(Queue* queue, int item) {
    Node* newNode = createNode(item);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("%d dodato u red\n", item);
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d dodato u red\n", item);
}

// Funkcija za uklanjanje elementa sa početka reda
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Red je prazan\n");
        return INT_MIN;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    int item = temp->data;
    free(temp);
    return item;
}

// Funkcija za vraćanje elementa sa početka reda bez uklanjanja
int front(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return INT_MIN;
    }
    return queue->front->data;
}

// Glavni program za testiranje
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("%d uklonjeno iz reda\n", dequeue(queue));
    printf("Element na početku reda je %d\n", front(queue));

    return 0;
}