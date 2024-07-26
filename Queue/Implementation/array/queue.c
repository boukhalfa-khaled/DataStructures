#include "queue.h"


void InitializeQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void Append(QueueEntry e, Queue *pQueue)
{
    pQueue->rear = (pQueue->rear + 1) % MAXQUEUE;
    pQueue->entry[pQueue->rear] = e;
    pQueue->size++;
}
void Serve(QueueEntry *pe, Queue *pQueue)
{
    *pe=pQueue->entry[pQueue->front];
    pQueue->front =(pQueue->front+1) % MAXQUEUE;
    pQueue->size--;
}
int QueueEmpty(Queue *pQueue)
{
    return !pQueue->size;
}

int QueueFull(Queue *pQueue)
{
    return (pQueue->size == MAXQUEUE);
}
int QueueSize(Queue *pQueue )
{
    return pQueue->size; 
}

void ClearQueue(Queue *pQueue)
{
    pQueue->front=0;
    pQueue->rear=-1;
    pQueue->size=0;
}

void TraverseQueue(Queue *pQueue, void(*pFunction)(QueueEntry))
{
    int pos = pQueue->front;
    for(int i =0 ; i<pQueue->size; i++)
    {
        (*pFunction)(pQueue->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}
