#include <table.h>

// Create a new hash table.
struct Table * table_create (uint32_t bucket_count)
{
    Table *table = (Table *)malloc(sizeof(Table));

    table->bucket_count = bucket_count;

    table->buckets = (TableEntry **)malloc(sizeof(TableEntry *) * bucket_count);

    for (int i = 0; i < bucket_count; i++) {
        table->buckets[i] = NULL;
    }

    return table;
}

uint32_t table_hash (
    Table *table,
    const char *str
)
{
    return djb2(str) % table->bucket_count;
}

// Create a new entry in the hash table
TableEntry *table_create_entry(
    const char *key,
    const char *value
) {
    TableEntry *entry = (TableEntry *)malloc(sizeof(TableEntry));

    entry->key = strdup(key);
    entry->value = strdup(value);
    entry->next = NULL;

    return entry;
}

// Insert a key-value pair into the hash table
void table_insert(
    Table *table,
    const char *key,
    const char *value
)
{
    uint32_t hash_index = table_hash(table, key);
    TableEntry *new_entry = table_create_entry(key, value);

    // Collision resolution using chaining (linked list)
    TableEntry *current = table->buckets[hash_index];

    if (current == NULL) {
        table->buckets[hash_index] = new_entry;
    } else {
        // Traverse to the end of the linked list
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_entry;
    }
}

// Search for a value by key in the hash table
char *table_search(
    Table *table,
    const char *key
)
{
    uint32_t hash_index = table_hash(table, key);

    TableEntry *current = table->buckets[hash_index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Key found, return the associated value
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return NULL;
}

// Delete a key-value pair from the hash table
void table_delete(
    Table *table,
    const char *key
)
{
    uint32_t hash_index = table_hash(table, key);
    TableEntry *current = table->buckets[hash_index];
    TableEntry *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[hash_index] = current->next;  // Remove the entry from the list
            } else {
                prev->next = current->next;  // Bypass the current entry
            }

            free(current->key);
            free(current->value);
            free(current);

            return;
        }
        prev = current;
        current = current->next;
    }
}

// Free the memory allocated for the hash table
void table_free(
    Table *table
)
{
    for (int i = 0; i < table->bucket_count; i++) {
        TableEntry *current = table->buckets[i];

        while (current != NULL) {
            TableEntry *temp = current;
            current = current->next;

            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(table->buckets);
    free(table);
}
