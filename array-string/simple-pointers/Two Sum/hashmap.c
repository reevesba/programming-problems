/*
 * Simple Hashmap Implementation
 * Bradley Reeves
 * 04/07/2021
 */

#include <stdlib.h>
#include <stdio.h>
#include "hashmap.h"

// Initialize hashmap
void init(struct Hashmap *self) {
    self->size = INITIAL_SIZE;
    self->data = malloc(sizeof(struct Node)*self->size);

    for (int i = 0; i < self->size; i++)
        self->data[i].next = NULL;
}

// New element key index
int keyIndex(struct Hashmap *self, int key) {
    return abs(key) % self->size;
}

// Add new key/value pair to hashmap
void put(struct Hashmap *self, int key, int val) {
    struct Node *ptr = self->data + keyIndex(self, key);
    struct Node *new = malloc(sizeof(struct Node));

    new->key = key;
    new->val = val;
    new->next = ptr->next;
    ptr->next = new;
}

// Retrieve value given key
int get(struct Hashmap *self, int key) {
    struct Node *ptr = self->data + keyIndex(self, key);

    while (ptr->next != NULL) {
        ptr = ptr->next;
        if (ptr->key == key)
            return ptr->val;
    }
    return -1;
}

// Free hashmap from memory
void clear(struct Hashmap *self) {
    for (int i = 0; i < self->size; i++)
        while (self->data[i].next != NULL) {
            struct Node *ptr = self->data[i].next;
            self->data[i].next = ptr->next;
            free(ptr);
        }
    free(self->data);
}