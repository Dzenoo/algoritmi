// MORA DA SE ZNA NAPAMET
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Funkcija za kreiranje deka
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
    return deque;
}

// Funkcija za proveru da li je dek pun
int isFull(Deque* deque) {
    return (deque->size == MAX);
}

// Funkcija za proveru da li je dek prazan
int isEmpty(Deque* deque) {
    return (deque->size == 0);
}

// Funkcija za umetanje elementa na početak deka
void insertFront(Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Dek je pun\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX - 1;
    } else {
        deque->front = deque->front - 1;
    }
    deque->arr[deque->front] = item;
    deque->size++;
    printf("%d umetnuto na početak deka\n", item);
}

// Funkcija za umetanje elementa na kraj deka
void insertRear(Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Dek je pun\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX - 1) {
        deque->rear = 0;
    } else {
        deque->rear = deque->rear + 1;
    }
    deque->arr[deque->rear] = item;
    deque->size++;
    printf("%d umetnuto na kraj deka\n", item);
}

// Funkcija za uklanjanje elementa sa početka deka
void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return;
    }
    printf("%d uklonjeno sa početka deka\n", deque->arr[deque->front]);
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX - 1) {
        deque->front = 0;
    } else {
        deque->front = deque->front + 1;
    }
    deque->size--;
}

// Funkcija za uklanjanje elementa sa kraja deka
void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return;
    }
    printf("%d uklonjeno sa kraja deka\n", deque->arr[deque->rear]);
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX - 1;
    } else {
        deque->rear = deque->rear - 1;
    }
    deque->size--;
}

// Funkcija za vraćanje elementa sa početka deka bez uklanjanja
int getFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return -1;
    }
    return deque->arr[deque->front];
}

// Funkcija za vraćanje elementa sa kraja deka bez uklanjanja
int getRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return -1;
    }
    return deque->arr[deque->rear];
}

// Glavni program za testiranje
int main() {
    Deque* deque = createDeque();

    insertRear(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 30);
    insertFront(deque, 40);

    printf("Element na početku deka: %d\n", getFront(deque));
    printf("Element na kraju deka: %d\n", getRear(deque));

    deleteFront(deque);
    deleteRear(deque);

    printf("Element na početku deka: %d\n", getFront(deque));
    printf("Element na kraju deka: %d\n", getRear(deque));

    return 0;
}