#include <stdio.h>
#include <stdlib.h>

/* Linked List Implementation of the Queue
 * before using the Queue define the type of the queue entry here.
*/
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
void InitializeQueue(Queue *);
void Append(QueueEntry , Queue *);
void Serve(QueueEntry *, Queue *);
int QueueEmpty(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void(*)(QueueEntry));
