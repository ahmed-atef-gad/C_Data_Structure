#include <stdio.h>
#include <stdlib.h>
#include "QueueArrayDs.h"

queue_t *Queue1;
int QueueRetVal;

unsigned int QueueCount;

int main()
{
    queuestatus_t ReturnQueueStatus = QUEUE_NOK;
    Queue1 = CreateQueue(&ReturnQueueStatus);

    for(int i=0; i<Queue1->maxsize; i++)
    {
        ReturnQueueStatus = EnqueueElement(Queue1, 11*(i+1));
        printf("=> %i \n", ReturnQueueStatus);
    }
    ReturnQueueStatus = EnqueueElement(Queue1, 66);
    printf("=> %i \n", ReturnQueueStatus);

    ReturnQueueStatus = GetQueueCount(Queue1, &QueueCount);
    printf("=> %i \n", ReturnQueueStatus);
    printf("Count = %i \n", QueueCount);

    QueueRetVal = QueueRear(Queue1, &ReturnQueueStatus);
    printf("=> %i \n", ReturnQueueStatus);
    printf("QueueRear = %i \n", QueueRetVal);

    for(int i=0; i<Queue1->maxsize; i++)
    {
        QueueRetVal = QueueFront(Queue1, &ReturnQueueStatus);
        printf("=> %i \n", ReturnQueueStatus);
        printf("Value = %i \n", QueueRetVal);

        QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus);
        printf("=> %i \n", ReturnQueueStatus);
        printf("Value = %i \n", QueueRetVal);
    }
    QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus);
    printf("=> %i \n", ReturnQueueStatus);
    printf("Value = %i \n", QueueRetVal);

    ReturnQueueStatus = GetQueueCount(Queue1, &QueueCount);
    printf("=> %i \n", ReturnQueueStatus);
    printf("Count = %i \n", QueueCount);

    ReturnQueueStatus = DestroyQueue(&Queue1); printf("=> %i \n", ReturnQueueStatus);
    if(!Queue1){
        printf("Queue destroyed\n");
    }


    return 0;
}
