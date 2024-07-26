#include <stdio.h>

/*
 * Array Implementation of the Queue
 * before using the Queue define the size of the Queue
 * and the type of the Queue Entry here.
*/

#define MAXQUEUE 10
typedef int QueueEntry;



typedef struct queue
{
    int front, rear ,size;
    QueueEntry entry[MAXQUEUE];
} Queue;

void InitializeQueue(Queue *);
void Append(QueueEntry , Queue *);
void Serve(QueueEntry *, Queue *);
int QueueEmpty(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void(*)(QueueEntry));


