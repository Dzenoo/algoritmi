// MORA DA SE ZNA NAPAMET
#include <stdio.h>
#include <stdlib.h>

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

// Funkcija za dodavanje čvora na kraj liste
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Funkcija za ispis liste
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// NE MORA DA SE ZNA NAPAMET

// Brisanje cvora sa odredjene pozicije
void deleteNode(Node** head, int position) {
    if (*head == NULL) return;

    Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Pretraga cvora
int searchNode(Node* head, int key) {
    Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Vrednost nije pronađena
}


// Funkcija za sortiranje liste koristeći Bubble Sort
void sortList(Node** head) {
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    if (*head == NULL) return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Funkcija za pronalaženje maksimalnog elementa u kružno ulančanoj listi
int findMax(Node* head) {
    if (head == NULL) {
        printf("Lista je prazna.\n");
        return -1;
    }

    int max = head->data;
    Node* temp = head->next;

    while (temp != head) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

// Glavni program za testiranje
int main() {
    Node* head = NULL; // Inicijalizacija prazne liste

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    printList(head); // Ispis liste

    return 0;
}