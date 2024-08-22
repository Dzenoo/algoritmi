// 1 Zadatak
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 100

// STEK
typedef struct Stack {
    int top;
    int array[MAX];
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if(isFull(stack)) {
        printf("Stek je pun");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stek je prazan");
        return;
    }
    return stack->array[stack->top--];
}


int peek(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stek je prazan");
        return;
    }
    return stack->array[stack->top];
}

// LISTA
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// RED
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue createQueue() {
    Queue* queue = (Queue)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
} 

void enqueue(Queue* queue, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL; 

    if(queue->rear == NULL) {
        queue->front = queue-rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Dodato u red");
}

int dequeue(Queue* queue) {
    if(isQueueEmpty(queue)) {
       printf("Red je prazan\n");
       return;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if(queue->front == NULL) {
        queue->rear = NULL;
    }

    int item = temp-> data;
    free(temp);
    return item;
}

void fillStackWithRandomNumbers(Stack* stack) {
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        int num = rand() % 100 + 1; // Generiše broj između 1 i 100
        push(stack, num);
    }
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void transferPrimesFromStackToQueue(Stack* stack, Queue* queue) {
    while (!isEmpty(stack)) {
        int num = pop(stack);
        if (isPrime(num)) {
            enqueue(queue, num);
        }
    }
}

int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();

    fillStackWithRandomNumbers(stack);
    printf("\nPrebacivanje prostih brojeva iz steka u red:\n");
    transferPrimesFromStackToQueue(stack, queue);

    printf("\nElementi u redu:\n");
    while (!isQueueEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    // Oslobađanje memorije
    free(stack);
    free(queue);

    return 0;
}

// 2 Zadatak
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

SNode* createSNode(int data) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEndS(SNode** head, int data) {
    SNode* newNode = createSNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = *head;
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp-next = newNode;
}

void printList(SNode* head) {
    SNode temp = head;
    while(temp != NULL) {
        printf("%d ->", temp->data);
    }
}

DNode createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
} 

void insertAtEndD(DNode** head, int data) {
    DNode* newNode = createDNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = *head;
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printDList(DNode* head) {
    DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void transferOddPositions(DNode* dHead, SNode* sHead) {
    int position = 1;
    DNode* temp = dHead;

    while(temp != NULL) {
        if(position % 2 !== 0) {
            insertAtEndS(sHead, temp->data);
        }
            temp = temp->next;
            position++;
    }
}

int main() {
    DNode* dHead = NULL;  // Dvostruko ulančana lista
    SNode* sHead = NULL;  // Jednostruko ulančana lista

    // Dodavanje elemenata u dvostruko ulančanu listu
    insertAtEndD(&dHead, 10);
    insertAtEndD(&dHead, 20);
    insertAtEndD(&dHead, 30);
    insertAtEndD(&dHead, 40);
    insertAtEndD(&dHead, 50);

    printf("Dvostruko ulančana lista:\n");
    printDList(dHead);

    // Prebacivanje elemenata sa neparnih pozicija u jednostruko ulančanu listu
    transferOddPositions(dHead, &sHead);

    printf("Jednostruko ulančana lista sa elementima sa neparnih pozicija:\n");
    printSList(sHead);

    return 0;
}

