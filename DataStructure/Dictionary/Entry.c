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
struct Entry entry_constructor(void *key, int key_size , void *value, int value_size){
    struct Entry entry;
    entry.key = malloc(key_size);
    entry.value = malloc(value_size);
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
