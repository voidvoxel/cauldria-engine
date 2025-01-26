#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hash.h>

// Define the structure of an entry in the hash table
typedef struct TableEntry {
    char *key;
    char *value;
    struct TableEntry *next;  // For handling collisions (linked list)
} TableEntry;

// Define the hash table
typedef struct Table {
    uint32_t bucket_count;
    TableEntry **buckets;
} Table;

// Create a new hash table.
struct Table * table_create (
    uint32_t bucket_count
);

uint32_t table_hash (
    struct Table *table,
    const char *str
);

// Create a new entry in the hash table
TableEntry *table_create_entry(
    const char *key,
    void *value
);

// Insert a key-value pair into the hash table
void table_insert(
    struct Table *table,
    const char *key,
    void *value
);

// Search for a value by key in the hash table
char *table_search(
    struct Table *table,
    const char *key
);

// Delete a key-value pair from the hash table
void table_delete(
    struct Table *table,
    const char *key
);

// Free the memory allocated for the hash table
void table_free(
    struct Table *table
);

#endif
