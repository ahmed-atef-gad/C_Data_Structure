#include "QueueArrayDs.h"

static char queueisfull(queue_t *queue_obj)
{
    return (queue_obj->elemcount == queue_obj->maxsize);
}

static char queueisempty(queue_t *queue_obj)
{
    return (queue_obj->elemcount == 0);
}

queue_t *CreateQueue(queuestatus_t *ret_status)
{
    queue_t *myqueue = NULL;
    if(NULL == ret_status)
    {
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        myqueue = (queue_t *)malloc(sizeof(queue_t));
        if(!myqueue)
        {
            *ret_status = QUEUE_NOK;
            myqueue = NULL;
        }
        else
        {
            printf("Please enter number of elements in Queue : ");
            scanf("%i", &(myqueue->maxsize));
            myqueue->data = (int *)calloc(myqueue->maxsize, sizeof(int));

            if(NULL == myqueue->data)
            {
                free(myqueue);
                *ret_status = QUEUE_NOK;
                myqueue = NULL;
            }
            else
            {
                myqueue->elemcount = 0;
                myqueue->queuefront = -1;
                myqueue->queuerear = -1;
                *ret_status = QUEUE_OK;
            }
        }
    }
    return myqueue;
}

queuestatus_t EnqueueElement(queue_t *queue_obj, int item)
{
    queuestatus_t ret_status = QUEUE_NOK;
    if(NULL == queue_obj)
    {
        ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queueisfull(queue_obj))
        {
            ret_status = QUEUE_FULL;
        }
        else
        {
            (queue_obj->queuerear)++;
            if(queue_obj->queuerear == queue_obj->maxsize)
            {
                queue_obj->queuerear = 0;
            }
            if(queue_obj->queuefront == -1)
            {
                queue_obj->queuefront = 0;
            }
            queue_obj->data[queue_obj->queuerear] = item;
            (queue_obj->elemcount)++;
            ret_status = QUEUE_OK;
        }
    }
    return ret_status;
}

int DequeueElement(queue_t *queue_obj, queuestatus_t *ret_status)
{
    int element = -1;
    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queueisempty(queue_obj))
        {
            *ret_status = QUEUE_EMPTY;
        }
        else
        {
            element = queue_obj->data[queue_obj->queuefront];
            (queue_obj->queuefront)++;
            if(queue_obj->queuefront == queue_obj->maxsize)
            {
                queue_obj->queuefront = 0;
            }
            (queue_obj->elemcount)--;
            if(queue_obj->elemcount == 0)
            {
                queue_obj->queuefront = -1;
                queue_obj->queuerear = -1;
            }
            *ret_status = QUEUE_OK;
        }
    }
    return element;
}

int QueueFront(queue_t *queue_obj, queuestatus_t *ret_status)
{
    int element = -1;
    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queueisempty(queue_obj))
        {
            *ret_status = QUEUE_EMPTY;
        }
        else
        {
            element = queue_obj->data[queue_obj->queuefront];
            *ret_status = QUEUE_OK;
        }
    }
    return element;
}

int QueueRear(queue_t *queue_obj, queuestatus_t *ret_status)
{
    int element = -1;
    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queueisempty(queue_obj))
        {
            *ret_status = QUEUE_EMPTY;
        }
        else
        {
            element = queue_obj->data[queue_obj->queuerear];
            *ret_status = QUEUE_OK;
        }
    }
    return element;
}

queuestatus_t GetQueueCount(queue_t *queue_obj, unsigned int *QueueCount)
{
    queuestatus_t ret_status = QUEUE_NOK;
    if((NULL == queue_obj) || (NULL == QueueCount))
    {
        ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queueisempty(queue_obj))
        {
            ret_status = QUEUE_EMPTY;
            *QueueCount = 0;
        }
        else
        {
            *QueueCount = queue_obj->elemcount;
            ret_status = QUEUE_OK;
        }
    }
    return ret_status;
}

queuestatus_t DestroyQueue(queue_t **queue_obj)
{
    queuestatus_t ret_status = QUEUE_NOK;
    if(NULL == *queue_obj)
    {
        ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        free((*queue_obj)->data);
        free(*queue_obj);
        *queue_obj = NULL;
        ret_status = QUEUE_DESTROYED;
    }
    return ret_status;
}
