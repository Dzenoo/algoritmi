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

#define MAX 10

typedef struct Stack {
    int top;
    int arr[MAX];
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* head) {
   return head->top == MAX - 1;
}

int isEmpty(Stack* head) {
    return head->top == -1;
}

void push(Stack* head, int data) {
    if(isFull(head)) {
        printf("Stack je vec pun");
        return;
    }
    head->arr[++head->top] = data;
}

void pop(Stack* head) {
    if(isEmpty(head)) {
        printf("Stack je vec prazan");
        return;
    }
    head->arr[head->top--];
}

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front, rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

int isQueueEmpty(Queue* queue) {
   return queue->front == NULL;
}

void enqueue(Queue* head, int data) {
    Node* newNode = createNode(data);
    if(head->rear == NULL) {
        head->front = head->rear = newNode;
        return;
    }
    head->rear->next = newNode;
    head->rear = newNode;
} 

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void transfer(Stack* stack, Queue* queue) {
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

    for(int i = 0; i < 10; i++) {
        push(stack, rand());
    }

    transfer(stack, queue);
}

typedef struct Node {
    int data;
    Node* left;
    Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int data) {
    if(node == NULL) {
        return createNode(data);
    }
    if(data < node->data) {
        return insert(node->left, data)
    } else {
        return insert(node->right, data)
    }
    return node;
}

void preorderTraversal(Node* node) {
    if(node != NULL) {
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void postorderTraversal(Node* node) {
    if(node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->data);
    }
}
// Funkcija za ručni unos čvorova u obično binarno stablo
Node* createBinaryTree() {
    int data;
    printf("Unesite vrednost (-1 za kraj unosa): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    Node* root = createNode(data);
    printf("Unos levog deteta od %d\n", data);
    root->left = createBinaryTree();
    printf("Unos desnog deteta od %d\n", data);
    root->right = createBinaryTree();
    return root;
}

int main() {
    Node* binaryTree = NULL;
    Node* binarySearchTree = NULL;
    int choice, data;

    printf("Odaberite opciju:\n");
    printf("1. Kreiraj obično binarno stablo\n");
    printf("2. Kreiraj binarno stablo pretraživanja\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Kreiraj obično binarno stablo:\n");
            binaryTree = createBinaryTree();
            printf("Preorder ispis obicnog binarnog stabla:\n");
            preorder(binaryTree);
            printf("\n");
            break;

        case 2:
            printf("Unesite elemente za binarno stablo pretraživanja (-1 za kraj unosa):\n");
            while (1) {
                scanf("%d", &data);
                if (data == -1) break;
                binarySearchTree = insertBST(binarySearchTree, data);
            }
            printf("Postorder ispis binarnog stabla pretraživanja:\n");
            postorder(binarySearchTree);
            printf("\n");
            break;

        default:
            printf("Neispravan izbor!\n");
    }

    return 0;
}

typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

CNode* createCNode(int data) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtEnd(CNode* head, int data) {
    CNode* newNode = createCNode(data)
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        CNode* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void printCList(CNode* head) {
    CNode* temp = head;
    do {
        temp = temp->next;
    } while (temp != head);
}

DNode* convertToDList(CNode* head) {
    if (head == NULL) return NULL;

    DNode* dHead = NULL;
    DNode* dTail = NULL;
    CNode* temp = head;

    do {
        DNode* newNode = createDNode(temp->data);
        if (dHead == NULL) {
            dHead = newNode;
            dTail = newNode;
        } else {
            dTail->next = newNode;
            newNode->prev = dTail;
            dTail = newNode;
        }
        temp = temp->next;
    } while (temp != head);

    return dHead;
}

void printDList(DNode* head) {
    DNode* temp = head;
    while (temp != NULL) {
        temp = temp->next;
    }
}

int main() {
    CNode* cHead = NULL; 

    insertAtEnd(&cHead, 10);
    insertAtEnd(&cHead, 20);
    insertAtEnd(&cHead, 30);
    insertAtEnd(&cHead, 40);

    printf("Kruzno ulančana lista:\n");
    printCList(cHead);

    DNode* dHead = convertToDList(cHead);

    printf("Dvostruko ulančana lista:\n");
    printDList(dHead);

    return 0;
}

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head* = newNode;
}

void insertRear(Node* node, int data) {
    if(node->next == NULL) {
        node = createNode(data);
        return;
    }
    Node* temp = head;
    while(temp->next == NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* node) {
    if(node == NULL) {
        return;
    }
    printf("%d ", node->data);
}

int searchNode(Node* head, int key) {
    Node* temp = head;
    int position = 0;
    while(temp != NULL) {
        if(temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

void sortList(Node* head) {
    Node* current;
    Node* nextNode;
    int temp;
    int swapped;

    do { 
        swapped = 0;
        current = head;

        while(current->head !== NULL) {
            nextNode = current->next;
            if(current->data > nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                swapped = 1;
            }
            current = nextNode;
        }
    } while (swapped);
}

int main() {
    Node* node = createNode();
}

typedef struct Stack {
    int top;
    int arr[MAX];
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

void push(Stack* stack, int data) {
    if(isFull(stack)) {
        return;
    }
    stack->arr[++stack->top];
}

void pop(Stack* stack) {
    if(isEmpty(stack)) {
        return;
    }
    stack->arr[stack->top--];
}

int isOperator(char ch) {
    return (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^");
}

void infixToPrefix(char* infix, char* prefix, int* index) {
    char ch = infix[index];
    index--;

    if(isOperator(ch)) {
        infixToPrefix(infix, prefix, index);
        infixToPrefix(infix, prefix, index);
        strncat(prefix, &ch, 1);
    } else {
        strncat(prefix, &ch, 1);
    }

}

typedef struct Queue {
    int front, rear, size;
    int arr[size];
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->size = 0;
    newQueue->rear = MAX - 1;
    return newQueue;
}

int isFull(Queue* queue) {
    return queue->size == MAX;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int data) {
    if(isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % MAX
    queue->array[queue->rear] = data;
    queue->size++;
}

void dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        return;
    }
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) % MAX;
    queue->size--; 
}

int main() {
    Queue* queue1 = createQueue();
    Queue* queue2 = createQueue();

    int count = 0;
    int num = 2018;
    while(count < 11) {
        enqueue(queue1, num);
        num += 2018;
        count++;
    }

    while(!isEmpty(queue1)) {
        int value = dequeue(queue1);
        if(value % 6 == 0) {
            enqueue(queue2, value);
        }
    }

    return 0;
}

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        head* = createNode(data);
    }
    Node* temp = head;
    while(temp->next == NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

Node* lista_parnih(Node* head) {
    Node* evenList = NULL;
    Node* temp = head;

    while(temp != NULL) {
        if(temp->data % 2 == 0) {
            insert(evenList, temp->data);
        }
    }
    return evenList;
}

int main() {
    Node* head  = NULL;
    Node* evenList = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);

    evenList = lista_parnih(head);

    return 0;
}

typedef struct Queue {
    int front, rear, size;
    int array[size];
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->size = 0;
    newQueue->rear = MAX - 1;
    return newQueue;
}

int isFull(Queue* queue) {
    return queue->size == MAX;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int data) {
    if(isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear - 1) % MAX;
    queue->array[queue->rear] = data;
    queue->size++;
    sort(queue);
}

void sort(Queue* head) {
    if(isEmpty(head)) {
        return;
    }
    for(int i = head->front; i <= head->rear - 1; i++) {
        for(int j = head->front; j <= head->rear; j++) {
            if(q->array[j] < q->array[j + 1]) {
                int temp = q->array[j];
                q->array[j] = q->array[j + 1];
                q->array[j + 1] = temp;
            }
        }
    }

}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 5);
    enqueue(queue, 3);
    enqueue(queue, 8);
    enqueue(queue, 1);
    enqueue(queue, 7);

    return 0;
}