#include <stdio.h>
#include <stdlib.h>

typedef int ListEntry;

typedef struct listnode{
    ListEntry entry;
    struct listnode *next, *previous; 
} ListNode;

typedef struct list{
    ListNode *head, *currentNode;
    int size, currentPos;
}List;

void CreateList(List *pList);
int  ListEmpty(List *pList);
int  ListFull(List *pList);
int  ListSize(List *pList);
void DestroyList(List *pList);
void InsertList(int position, ListEntry entry, List *pList);
void DeleteList(int position, ListEntry *pEntry, List *pList);
void RetriveList(int position, ListEntry *pEntry, List *pList);
void ReplaceList(int position, ListEntry entry, List *pList);
void TraversList(List *pList, void(*pFunction)(ListEntry));
