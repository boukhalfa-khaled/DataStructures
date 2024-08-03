#include "list.h"

void CreateList(List *pList)
{
    pList->head = NULL;
    pList->size = 0;
}
int  ListEmpty(List *pList)
{
    return !pList->size;
}

int  ListFull(List *pList)
{
    return 0;
}

int  ListSize(List *pList)
{
    return pList->size;
}


void DestroyList(List *pList)
{
    ListNode *pn;
    while(pList->head){
        pn = pList->head->next;
        free(pList->head);
        pList->head = pn;
    }
}





void InsertList(int position, ListEntry entry, List *pList)
{
    ListNode *qn = pList->head;
    ListNode *pn = ( ListNode * ) malloc( sizeof( ListNode ) );
    pn->entry = entry;
    pn->next = NULL;
    if(position == 0 ){
        pn->next = pList->head;
        pList->head = pn;
    }else{
        for( int i = 0 ; i < position-1; i++)
        {
            qn = qn->next;          
        }
        pn->next = qn->next;
        qn->next = pn;
    }
    pList->size++;
}



void DeleteList(int position, ListEntry *pEntry, List *pList)
{
    ListNode *qn, *pn = pList->head; 
    if(position == 0)
    {
        *pEntry = pList->head->entry;
        pList->head = pList->head->next;
        free(pn);
    }else{
        for(int i=0; i < position ; i++)
            pn = pn->next;
        *pEntry = pn->entry;
        qn = pn;
        pn->next = pn->next->next;
        free(qn);
    }
    pList->size--;
}

void ReplaceList(int position, ListEntry entry, List *pList){
    ListNode *pn = pList->head;
    for(int i = 0 ; i < position ; i++)
        pn = pn->next;
    pn->entry  = entry;
}


void RetriveList(int position, ListEntry *pEntry, List *pList)
{
    ListNode *pn = pList->head;
    for(int i=0 ; i < position ; i++)
        pn = pn->next;
    *pEntry = pn->entry;
}




void TraversList(List *pList, void(*pFunction)(ListEntry))
{
    ListNode *pn=pList->head ;
    while(pn){
        (*pFunction)(pn->entry);
        pn = pn->next;
    }
}
