#include <stdio.h>

typedef int ListEntry;
#define MAXLIST 10

typedef struct List 
{
    ListEntry entry[MAXLIST];
    int size; 
} List;

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

