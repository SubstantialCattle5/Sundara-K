/**
 * Declaration file for Entry in a Dictionary created for the library Networking
 *
 * Created by - Nilay Nath Sharan
 * 15th Dec 2023.
 */

#ifndef NETWORKING_ENTRY_H
#define NETWORKING_ENTRY_H


/**
 * entry_object {
 *  key : value
 * }
 */
struct Entry {
    void *key;
    void *value ;
};

/**
 * Constructor for entry struct
 * @param key - void pointer to the key
 * @param key_size - size of the key
 * @param value - void pointer to the value
 * @param value_size - size of the value
 * @return Entry
 */
struct Entry entry_constructor(void *key, int key_size, void *value, int value_size) ;

void entry_destructor(struct Entry *entry) ;
#endif //NETWORKING_ENTRY_H
