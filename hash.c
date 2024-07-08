#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Funkcija za kreiranje novog čvora
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Funkcija za kreiranje hash tabele
HashTable* createTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Funkcija heširanja
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Funkcija za umetanje elementa u hash tabelu
void insert(HashTable* hashTable, int key, int value) {
    int hashIndex = hashFunction(key);
    Node* newNode = createNode(key, value);

    if (hashTable->table[hashIndex] == NULL) {
        hashTable->table[hashIndex] = newNode;
    } else {
        Node* temp = hashTable->table[hashIndex];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Element sa ključem %d i vrednošću %d umetnut.\n", key, value);
}

// Funkcija za pretragu elementa u hash tabeli
int search(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key);
    Node* temp = hashTable->table[hashIndex];

    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Element nije pronađen
}

// Funkcija za brisanje elementa iz hash tabele
void delete(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key);
    Node* temp = hashTable->table[hashIndex];
    Node* prev = NULL;

    while (temp) {
        if (temp->key == key) {
            if (prev == NULL) {
                hashTable->table[hashIndex] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Element sa ključem %d obrisan.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element sa ključem %d nije pronađen.\n", key);
}

// Glavni program za testiranje
int main() {
    HashTable* hashTable = createTable();

    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 42, 30);

    printf("Vrednost sa ključem 2: %d\n", search(hashTable, 2));
    printf("Vrednost sa ključem 42: %d\n", search(hashTable, 42));

    delete(hashTable, 1);
    printf("Vrednost sa ključem 1: %d\n", search(hashTable, 1));

    // Oslobađanje memorije
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable->table[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(hashTable);

    return 0;
}