/*
 * About: Simple Hashmap Implementation
 * Author: Bradley Reeves
 * Date: 04/07/2021
 * 
 * init: initialize hashmap.
 * keyIndex: new element index.
 * put: insert node into hashmap.
 * get: retrieve node from hashmap.
 * clear: free the hashmap from memory.
 */

#define INITIAL_SIZE 1u

struct Node {
    int key;
    int val;
    struct Node *next;
};

struct Hashmap {
    int size;
    struct Node *data;
};

void init(struct Hashmap *self);
int keyIndex(struct Hashmap *self, int key);
void put(struct Hashmap *self, int key, int val);
int get(struct Hashmap *self, int key);
void clear(struct Hashmap *self);