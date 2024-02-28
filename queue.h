#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/**
 * struct queue_s - Queue structure
 *
 * @data: Pointer to the data
 * @next: Pointer to the next element in the queue
 */
typedef struct queue_s
{
    void *data;
    struct queue_s *next;
} queue_t;

queue_t *queue_create(void);
void queue_push(queue_t *queue, void *data);
void *queue_front(const queue_t *queue);
void queue_pop(queue_t *queue);
int queue_is_empty(const queue_t *queue);
void queue_delete(queue_t *queue);

#endif /* QUEUE_H */
