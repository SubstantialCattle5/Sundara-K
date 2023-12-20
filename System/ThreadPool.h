//
// Created by nilay on 12/20/23.
//

#ifndef NETWORKING_THREADPOOL_H
#define NETWORKING_THREADPOOL_H


#include "../DataStructure/list/Queue.h"

#include <pthread.h>

// MARK: DATA TYPES

struct ThreadJob
{
    // The function to be executed.
    void * (*job)(void *arg);
    // The argument to be passed.
    void *arg;
};

struct ThreadPool
{
    // The number of threads in the pool.
    int num_threads;
    // A control switch for the thread pool.
    int active;
    // A queue to store work.
    struct Queue work;
    // Mutices for making the pool thread-safe.
    pthread_t *pool;
    pthread_mutex_t lock;
    pthread_cond_t signal;
    // A function for safely adding work to the queue.
    void (*add_work)(struct ThreadPool *thread_pool, struct ThreadJob thread_job);
};

// MARK: CONSTRUCTORS

struct ThreadPool thread_pool_constructor(int num_threads);
struct ThreadJob thread_job_constructor(void * (*job)(void *arg), void *arg);

void thread_pool_destructor(struct ThreadPool *thread_pool);

#endif //NETWORKING_THREADPOOL_H
