#include "list.h"

void
CreateList(List *pList){
    pList->size = 0;
}

int
ListEmpty(List *pList)
{
    return !pList->size;
}

int
ListFull(List *pList)
{
    return pList->size == MAXLIST;
}

int
ListSize(List *pList)
{
    return pList->size;
}

void
DestroyList(List *pList)
{
    pList->size = 0;
}


void
InsertList(int position, ListEntry entry, List *pList)
{
    for(int i=pList->size; i > position; i--){
        pList->entry[i+1] = pList->entry[i];
    }
    pList->entry[position] = entry; 
    pList->size++;
}   

void
DeleteList(int position, ListEntry *pEntry, List *pList)
{
   *pEntry= pList->entry[position]; 
   for(int i=position  ; i<pList->size-1 ;i++) {
        pList->entry[i] =  pList->entry[i+1];
   }
   pList->size--;
}
void
RetriveList(int position, ListEntry *pEntry, List *pList)
{
    *pEntry = pList->entry[position];
}

void
ReplaceList(int position, ListEntry entry, List *pList)
{
    pList->entry[position] = entry;
}

void
TraversList(List *pList, void(*pFunction)(ListEntry))
{
    for(int i = 0 ; i < pList->size; i++)
    {
        (*pFunction)(pList->entry[i]);
    }
}

