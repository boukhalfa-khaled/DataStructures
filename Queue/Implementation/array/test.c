#include <stdio.h>
#include "queue.h"


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
