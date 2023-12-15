#include <string.h>
#include "Node.h"


/**
 * Dynamically memory allocates the data
 * @param data
 * @param size
 * @return
 */
struct Node node_constructor(void *data, int size)
{
    if (size < 1)
    {
        printf("Invalid data size for node...\n");
        exit(1);
    }
    struct Node node;

    // Allocating space for data
    node.data = malloc(size) ;
    memcpy(node.data, data, size);
    node.next = NULL;
    node.previous = NULL ;
    return node;
}

/**
 * Frees the data memory allocation then deletes the node
 */
void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}