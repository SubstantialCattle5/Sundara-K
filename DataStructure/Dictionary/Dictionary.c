/**
 * Dict implementation file for the networking library
 * Creator - nilay nath sharan
 * 16th Dec 2023.
 */

#include "Dictionary.h"

#include <stdlib.h>
#include <string.h>

// MARK : PRIVATE MEMBER FUNCTIONS

// Recursive algorithm to destroy the nodes in a dictionary - overrides the destructor of a BinarySearchTree
void recursive_dictionary_destroy(struct Node *cursor);

// MARK: PUBLIC FUNCTION PROTOTYPES

// Insert adds items to the dictionary - the user does not need to implement Elements themselves.
void insert_dict(struct Dictionary *dictionary, void *key, unsigned long key_size, void *value, unsigned long value_size);

// Search finds the value for a given key in the Dictionary.
void * search_dict(struct Dictionary *dictionary, void *key, unsigned long key_size);

// MARK: CONSTRUCTORS
struct Dictionary dictionary_constructor(int (*compare)(void *key_one, void *key_two))
{
    struct Dictionary dictionary;
    dictionary.binary_search_tree = binary_search_tree_constructor(compare);
    dictionary.insert = insert_dict;
    dictionary.search = search_dict;
    return dictionary;
}

// MARK : PRIVATE MEMBER FUNCTIONS
/**
 * deletes the dictionary
 * @param dictionary
 */
void dictionary_destructor(struct Dictionary *dictionary)
{
    recursive_dictionary_destroy(dictionary->binary_search_tree.head);
}

/**
 * Recursively calls the dict to delete all the cursor elements
 * @param cursor
 */
void recursive_dictionary_destroy(struct Node *cursor)
{
    if (cursor->previous)
    {
        recursive_dictionary_destroy(cursor->previous);
    }
    if (cursor->next)
    {
        recursive_dictionary_destroy(cursor->next);
    }
    entry_destructor((struct Entry *)cursor->data);
    free(cursor->data);
    free(cursor);
}

// MARK: PUBLIC MEMBER FUNCTIONS
/**
 * Searches the dict and returns a void pointer could be either null or the entry value of the result
 * @param dictionary - pointer to the dictionary
 * @param key - pointer to the key
 * @param key_size - size of the key
 * @return
 */
void * search_dict(struct Dictionary *dictionary, void *key, unsigned long key_size)
{
    int dummy_value = 0;
    struct Entry searchable = entry_constructor(key, key_size, &dummy_value, sizeof(dummy_value));
    // Use the iterate function of the BinarySearchTree to find the desired element.
    void * result = dictionary->binary_search_tree.search(&dictionary->binary_search_tree, &searchable);
    // Return either the value for that key or NULL if not found.
    if (result)
    {
        printf("Found the result!\n");
        return ((struct Entry *)result)->value;
    }
    else
    {
        return NULL;
    }
}

/**
 * Inserts the value in the dict
 * @param dictionary
 * @param key
 * @param key_size
 * @param value
 * @param value_size
 */
void insert_dict(struct Dictionary *dictionary, void *key, unsigned long key_size, void *value, unsigned long value_size)
{
    // Create a new Entry.
    struct Entry entry = entry_constructor(key, key_size, value, value_size);
    // Insert that entry into the tree.
    dictionary->binary_search_tree.insert(&dictionary->binary_search_tree, &entry, sizeof(entry));
}



// MARK: PUBLIC HELPER FUNCTIONS
int compare_string_keys(void *entry_one, void *entry_two)
{
    if (strcmp((char *)(((struct Entry *)entry_one)->key), (char *)(((struct Entry *)entry_two)->key)) > 0)
    {
        return 1;
    }
    else if (strcmp((char *)(((struct Entry *)entry_one)->key), (char *)(((struct Entry *)entry_two)->key)) < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}