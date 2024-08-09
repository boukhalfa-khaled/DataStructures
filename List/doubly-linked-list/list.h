#include <stdio.h>
#include <stdlib.h>


// if your search based on int, float, char

#define EQ(a, b) ( (a) == (b) )
#define LT(a, b) ( (a) <  (b) )
#define LE(a, b) ( (a) <= (b) )
#define GT(a, b) ( (a) >  (b) )
#define GE(a, b) ( (a) >= (b) )


//if you serach based on strings uncomment these lines

// #define EQ(a, b) ( !strcmp( (a) , (b))      )
// #define LT(a, b) (  strcmp( (a) , (b)) <  0 )
// #define LE(a, b) (  strcmp( (a) , (b)) <= 0 )
// #define GT(a, b) (  strcmp( (a) , (b)) >  0 )
// #define GE(a, b) (  strcmp( (a) , (b)) >= 0 )




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
int SearchList(ListEntry target, List *pList);
