#include <stdio.h>

//  HEADER FILE
#define MAXQUEUE 10
typedef int QueueEntry;
//  HEADER FILE

typedef struct queue{
    int front, rear ,size;
    QueueEntry entry[MAXQUEUE];
} Queue;

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


// USER SPACE

void printQueue(QueueEntry e)
{
    printf("%d\n", e);
}



int main()
{
    Queue q;
    InitializeQueue(&q);
    int a,b,c;
    printf("QueueEmpty : %d\n", QueueEmpty(&q));
    Append(1, &q);
    Append(2, &q);
    Append(3, &q);
    Append(4, &q);
    Serve(&a, &q);
    Append(5, &q);
    Append(6, &q);
    printf("Serve(&a, &q): %d\n", a);
    printf("size : %d\n",QueueSize(&q));
    printf("QueueEmpty : %d\n",QueueEmpty(&q));
    printf("QueueFull: %d\n", QueueFull(&q));
    TraverseQueue(&q, &printQueue);
    return 0;
}

