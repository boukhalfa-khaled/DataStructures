#include "list.h"


void CreateList(List *pList)
{
    pList->head = NULL;
    pList->currentNode= NULL;
    pList->size = 0;
    pList->currentPos = 0;
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
    pList->currentNode = NULL;
    pList->currentPos = 0;
    pList->size = 0;
}

void InsertList(int position, ListEntry entry, List *pList) {
    ListNode *pn = ( ListNode * ) malloc( sizeof( ListNode ) );
    pn->entry = entry;
    pn->next = NULL;
    pn->previous = NULL;

    if(position == 0 ){
        pn->next = pList->head;
        if(pList->head){
            pList->head->previous = pn;
        }
        pList->head = pn;
        pList->currentNode = pn;
        pList->currentPos = 0;
    }else{
        if(position - pList->currentPos == 1)
        {
            pn->next = pList->currentNode->next;
            pn->previous = pList->currentNode;
            pList->currentNode->next = pn;
            if(pn->next){
                pn->next->previous = pn;
            }
            pList->currentPos++;
            pList->currentNode = pn;
        }else if (position - pList->currentPos == -1){
            pn->next = pList->currentNode;   
            pn->previous = pList->currentNode->previous;
            pList->currentNode->previous->next = pn;
            pList->currentPos--;
            pList->currentNode = pn;
        }else {
            if(position == pList->currentPos){
                pList->currentNode = pList->head;
                pList->currentPos = 0;
            }
            if(position > pList->currentPos){

                for(; pList->currentPos < position-1; pList->currentPos++)
                    pList->currentNode = pList->currentNode->next;
                
                pn->next = pList->currentNode->next;
                pList->currentNode->next->previous = pn;
                pn->previous = pList->currentNode;
                pList->currentNode->next = pn; 

            }else{

                for(; pList->currentPos > position+1; pList->currentPos--)
                    pList->currentNode = pList->currentNode->previous;
                pn->previous = pList->currentNode->previous;
                pList->currentNode->previous->next= pn;
                pn->next = pList->currentNode;
                pList->currentNode->previous= pn; 

            }

        }

    }

    pList->size++;
}

void DeleteList(int position, ListEntry *pEntry, List *pList)
{
    ListNode  *pn; 
    if(position == 0)
    {
      *pEntry = pList->head->entry; 
       pList->currentNode = pList->head->next;
       if(pList->currentNode){
        pList->currentNode->previous = NULL;
       } 
       free(pList->head);
       pList->head = pList->currentNode;
       pList->currentPos = 0;
       
    }else{
        if(pList->currentPos == position)
        {
            pList->currentPos = 0;
            pList->currentNode= pList->head;
        }
        if( position > pList->currentPos) {
            for(; pList->currentPos < position - 1 ; pList->currentPos++)
                pList->currentNode = pList->currentNode->next;
            
            
             pn = pList->currentNode->next;
            *pEntry = pn->entry;
            pList->currentNode->next =  pn->next;
            if(pn->next)
                pn->next->previous = pList->currentNode;

        }else {
            for(; pList->currentPos > position + 1 ; pList->currentPos--)
                pList->currentNode = pList->currentNode->previous;

             pn = pList->currentNode->previous;
            *pEntry = pn->entry;
            pList->currentNode->previous=  pn->previous;
            if(pn->previous)
                pn->previous->next = pList->currentNode;

        }

        free(pn);

    }

    pList->size--;

}

void ReplaceList(int position, ListEntry entry, List *pList){
            if(pList->currentPos == position)
            {
                pList->currentNode->entry = entry;
            }else if( position > pList->currentPos) {
                for(; pList->currentPos < position  ; pList->currentPos++)
                    pList->currentNode = pList->currentNode->next;
                pList->currentNode->entry = entry;
            }else {
                for(; pList->currentPos > position ; pList->currentPos--)
                    pList->currentNode = pList->currentNode->previous;
                pList->currentNode->entry = entry;
            }
}

void RetriveList(int position, ListEntry *pEntry, List *pList)
{
        if(pList->currentPos == position)
        {
            *pEntry = pList->currentNode->entry;
        }else if( position > pList->currentPos) {
            for(; pList->currentPos < position  ; pList->currentPos++)
                pList->currentNode = pList->currentNode->next;
            *pEntry = pList->currentNode->entry;
        }else {
            for(; pList->currentPos > position ; pList->currentPos--)
                pList->currentNode = pList->currentNode->previous;
            *pEntry = pList->currentNode->entry;
        }
}

void TraversList(List *pList, void(*pFunction)(ListEntry))
{
    ListNode *pn=pList->head ;
    while(pn){
        (*pFunction)(pn->entry);
        pn = pn->next;
    }
}

// SEARCH USING LINEAR SERACH in array implementation we used binary Search
int SearchList(ListEntry target, List *pList)
{   
    int current ,  s=ListSize(pList);
    ListEntry currentEntry;
    for(current=0; current < s; current++) {
        RetriveList(current, &currentEntry, pList);
        if(EQ(target, currentEntry))
            return current;
    }
    return -1;
}
