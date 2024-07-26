#include <stdio.h>

/* this code will be in the HEADER File*/
#define MAXQUEUE 10
typedef int QueueEntry;
/* HEADER FILE End */

typedef struct queue{
    int front, rear, size;
    QueueEntry entry[MAXQUEUE];
} Queue;

void InitializeQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void Append(QueueEntry e, Queue *pq)
{
    // this allow for Circular Implementaion
    // when we reach the end we will start from 0
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}

void Serve (QueueEntry *pe,Queue *pq)
{
    *pe=pq->entry[pq->front];
    pq->front=(pq->front +1) % MAXQUEUE;
    pq->size--;
}

int QueueEmpty(Queue *pq)
{
    return !pq->size;
}

int QueueFull(Queue *pq)
{
    return (pq->size == MAXQUEUE);
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void ClearQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void TraverseQueue(Queue *pq, void(*pfn)(QueueEntry))
{
    int pos = pq->front;
    for(int i =0; i < pq->size;i++)
    {
        (*pfn)(pq->entry[pos]);
        pos =(pos + 1) % MAXQUEUE ;
    }
}

void printQueue(QueueEntry e)
{
    printf("%d\n",e);
}




int main ()
{
    Queue q;
    InitializeQueue(&q);
    int a,b,c;
    printf("QueueEmpty : %d\n",QueueEmpty(&q));
    Append(1, &q);
    Append(2, &q);
    Append(3, &q);
    Append(4, &q);
    Serve(&a,&q);
    Append(5, &q);
    Append(6, &q);
    c = QueueSize(&q);
    printf("a: %d\n", a);
    printf("size : %d\n", c);
    printf("QueueEmpty : %d\n", QueueEmpty(&q));
    printf("QueueFull: %d\n", QueueFull(&q));

    TraverseQueue(&q, &printQueue);
    return 0;
}
