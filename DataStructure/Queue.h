/**
 * Queue
 * Data Structure Library created for Networking library
 * 
 * Created by Nilay Nath Sharan 
 * 15th Dec 2023. 
*/

#ifndef Queue_h
#define Queue_h

#include "LinkedList.h"


struct Queue
{

    /**
     * The linked list that will be used to implement the queue
    */
    struct LinkedList list;

    /**
     * The push function that will be used to push data into the queue
     * @param data - The pointer to the data to be pushed into the queue
     * @param queue - The pointer to the queue in which the data is to be pushed
     * @param data_type
     * @param size
     * @return void
    */
    void (*push)(void *data, struct Queue *queue, int data_type , int size);

    /**
     * The pop function that will be used to pop data from the queue
     * @param queue - The pointer to the queue from which the data is to be popped
     * @return void * - The pointer to the data popped from the queue
    */
    void (*pop)(struct Queue *queue);

    /**
     * Will return whatever value is at the front of the queue
     * @param queue
     * @return
     */
    void * (*peek) (struct Queue *queue) ;
};

/**
 * queue_constructor - Constructs a queue
 * @param void - No parameters
 * @return struct Queue - The constructed queue
*/
struct Queue queue_constructor(void);

/**
 * queue_destructor - Destroys the given queue
 * @param queue - The queue to be destroyed
 * @return void
*/
void queue_destructor(struct Queue *queue);

#endif /* Queue_h */