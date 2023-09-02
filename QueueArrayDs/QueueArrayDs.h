#ifndef QUEUEARRAYDS_H_INCLUDED
#define QUEUEARRAYDS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    unsigned int elemcount;
    unsigned int maxsize;
    int queuefront;
    int queuerear;
} queue_t;

typedef enum
{
    QUEUE_NOK = 0,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER,
    QUEUE_DESTROYED
} queuestatus_t;

queue_t *CreateQueue(queuestatus_t *ret_status);
queuestatus_t EnqueueElement(queue_t *queue_obj, int item);
int DequeueElement(queue_t *queue_obj, queuestatus_t *ret_status);
int QueueFront(queue_t *queue_obj, queuestatus_t *ret_status);
int QueueRear(queue_t *queue_obj, queuestatus_t *ret_status);
queuestatus_t GetQueueCount(queue_t *queue_obj, unsigned int *QueueCount);
queuestatus_t DestroyQueue(queue_t **queue_obj);

#endif // QUEUEARRAYDS_H_INCLUDED