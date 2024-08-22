// MORA DA SE ZNA NAPAMET
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

typedef struct Queue {
    int front, rear, size;
    int array[MAX];
} Queue;

// Funkcija za kreiranje reda
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->size = 0;
    queue->rear = MAX - 1;
    return queue;
}

// Funkcija za proveru da li je red prazan
int isQueueEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Funkcija za proveru da li je red pun
int isQueueFull(Queue* queue) {
    return (queue->size == MAX);
}

// Funkcija za dodavanje elementa na kraj reda
void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Red je pun\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d dodato u red\n", item);
}

// Funkcija za uklanjanje elementa sa početka reda
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Red je prazan\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    return item;
}

// Funkcija za vraćanje elementa sa početka reda bez uklanjanja
int front(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return INT_MIN;
    }
    return queue->array[queue->front];
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