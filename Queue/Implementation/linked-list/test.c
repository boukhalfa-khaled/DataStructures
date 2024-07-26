#include <stdio.h>
#include <stdlib.h>

// Header file
typedef int QueueEntry;
// Header file

typedef struct queuenode{
    QueueEntry entry;
    struct queuenode *next;
} QueueNode;
typedef struct queue{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void InitializeQueue(Queue *pQueue)
{
    pQueue->front=NULL;
    pQueue->rear=NULL;
    pQueue->size=0;
}
void Append(QueueEntry e, Queue *pQueue)
{
    QueueNode *pn =(QueueNode*) malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;
    //if(!pQueue->rear) // the same 
    if(!pQueue->front)
        pQueue->front = pn;
    else 
        pQueue->rear->next = pn;


    pQueue->rear = pn;
    pQueue->size++;

}
void Serve(QueueEntry *pe, Queue *pQueue)
{
    QueueNode *pn =  pQueue->front;
    *pe = pQueue->front->entry;
    //*pe = pn->entry; the same 
    pQueue->front = pQueue->front->next;
    // pQueue->front = pn->next; the same
    if(pn == pQueue->rear)
       pQueue->rear = NULL;
    //if(!pQueue->front)
     //   pQueue->rear = NULL;
    free(pn);

    pQueue->size--;
}
int QueueEmpty(Queue *pQueue)
{
    return !pQueue->size;
}

int QueueFull(Queue *pQueue)
{
    return 0;
}
int QueueSize(Queue *pQueue )
{
    return pQueue->size;
}

void ClearQueue(Queue *pQueue)
{
    while(!pQueue->front)
    {
        pQueue->rear = pQueue->front->next;
        free(pQueue->front);
        pQueue->front = pQueue->rear;
    }
    pQueue->size = 0;
}

void TraverseQueue(Queue *pQueue, void(*pFunction)(QueueEntry))
{
    QueueNode *pn = pQueue->front;
    while(pn)
    {
        (*pFunction)(pn->entry);   
        pn = pn->next;
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

