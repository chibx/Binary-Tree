#pragma once
#include "stdbool.h"

// #define DEFAULT_Queue_SIZE 10;
#define NO_QUEUE_ERR 0
#define QUEUE_EMPTY 1
#define QUEUE_MEM_ERR 2

// typedef enum { Queue_SUCCESS,
//                Queue_ERROR } QueueStatus;

typedef struct {
    char *data;
    int error;
} QueueStatus;

typedef struct QueueNode {
    struct QueueNode *next;
    char *value;
} QueueNode;

typedef struct {
    //   int capacity;
    int size;
    QueueNode *front;
    QueueNode *rear;
} Queue;

bool enqueue(Queue *queue, char *value);

QueueStatus dequeue(Queue *queue);

QueueStatus queue_peek(Queue *queue);

Queue *create_queue();