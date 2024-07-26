#include <stdio.h> 
#include <stdlib.h>

typedef int QueueEntry;

typedef struct queuenode{
     QueueEntry entry;
     struct queuenode *next;
} QueueNode;

typedef struct queue{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void CreateQueue(Queue *pq)
{
    pq->front=NULL;
    pq->rear= NULL;
    pq->size=0;
}

void Append(QueueEntry e, Queue *pq)
{
    QueueNode *pn = (QueueNode*) malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;
    if(!pq->front)
        pq->front = pn;
    else
        pq->rear->next = pn;
    pq->rear = pn;  
    pq->size++;
}



int main() 
{
    printf("Hello World!\n");
    return 0;
}
