#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Za korišćenje INT_MIN

#define MAX 1000 // Maksimalna veličina steka

typedef struct Stack {
    int top;
    int array[MAX];
} Stack;

// Funkcija za kreiranje steka
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Funkcija za proveru da li je stek pun
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Funkcija za proveru da li je stek prazan
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Funkcija za dodavanje elementa na stek
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stek je pun\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d dodato na stek\n", item);
}

// Funkcija za uklanjanje elementa sa steka
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stek je prazan\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Funkcija za vraćanje elementa sa vrha steka bez uklanjanja
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

// Glavni program za testiranje
int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d uklonjeno sa steka\n", pop(stack));
    printf("Element na vrhu steka je %d\n", peek(stack));

    return 0;
}