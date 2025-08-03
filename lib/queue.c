#include "../include/queue.h"
#include "stdbool.h"
#include <stdlib.h>
#include <string.h>

bool enqueue(Queue *queue, char *value) {
    QueueNode *first = queue->front;
    QueueNode *new_el = malloc(sizeof(QueueNode));
    new_el->next = NULL;

    if (new_el == NULL) {
        return false;
    }

    new_el->value = value;

    if (queue->size == 0) {
        queue->front = new_el;
        queue->rear = new_el;
    } else {
        queue->rear->next = new_el;
        queue->rear = new_el;
    }

    queue->size++;

    return true;
    //   }
}

QueueStatus dequeue(Queue *queue) {
    QueueStatus status = {.data = NULL, .error = QUEUE_EMPTY};

    if (queue->size == 0) {
        return status;
    }

    if (queue->size == 1) {
        queue->front->next = NULL;
        queue->rear = NULL;
    }

    QueueNode *first = queue->front;
    queue->front = first->next;

    status.data = first->value;
    status.error = NO_QUEUE_ERR;

    free(first);

    queue->size--;

    return status;
}

QueueStatus queue_peek(Queue *queue) {
    QueueStatus status = {.data = NULL, .error = QUEUE_EMPTY};

    if (queue->size == 0) {
        return status;
    }

    status.data = _strdup(queue->front->value);
    if (status.data == NULL) {
        status.error = QUEUE_MEM_ERR;
        return status;
    }

    return status;
}

Queue *create_queue() {
    Queue *queue = malloc(sizeof(Queue));

    //   queue->capacity = DEFAULT_QUEUE_SIZE;
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}