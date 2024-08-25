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

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
    return deque;
}

int isFull(Deque* deque) {
    return (deque->size == MAX);
}

int isEmpty(Deque* deque) {
    return (deque->size == 0);
}

void insert(Deque* deque, int item) {
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

void delete(Deque* deque) {
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

int get(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Dek je prazan\n");
        return -1;
    }
    return deque->arr[deque->rear];
}

int main() {
    Deque* deque = createDeque();

    insert(deque, 10);
    insert(deque, 20);

    printf("Element na kraju deka: %d\n", get(deque));

    delete(deque);

    printf("Element na kraju deka: %d\n", get(deque));

    return 0;
}