/**
 * Entry Implementation file created for the Networking library
 *
 * Creator - Nilay Nath Sharan
 * 15th Dec,2023.
 */

#include "Entry.h"
#include <stdlib.h>
#include <string.h>

/**
 * Constructor for entry struct
 * @param key - void pointer to the key
 * @param key_size - size of the key
 * @param value - void pointer to the value
 * @param value_size - size of the value
 * @return Entry
 */
struct Entry entry_constructor(void *key, unsigned long key_size , void *value, unsigned long value_size){
    struct Entry entry;

    // allocating memory
    entry.key = malloc(key_size);
    entry.value = malloc(value_size);

    // copying the data
    memcpy(entry.key,key,key_size);
    memcpy(entry.value,value,value_size);

    return entry;
};

/**
 * Destroys the entry
 * @param entry
 */
void entry_destructor(struct Entry *entry) {
    free(entry->key) ;
    free(entry->value);
    free(entry);
}
