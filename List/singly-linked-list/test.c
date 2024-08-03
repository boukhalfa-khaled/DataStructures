#include <stdio.h>
#include "list.h"


void printlist(ListEntry e){
    printf("-----> %d \n", e);
}

int main()
{

    List l;
    CreateList(&l);
    printf("List Empty before adding %d\n", ListEmpty(&l));
    InsertList(0, 10, &l);
    InsertList(1, 20, &l);
    InsertList(2, 30, &l);
    InsertList(3, 40, &l);
    printf("List Empty After adding %d\n", ListEmpty(&l));
    printf("List Size : %d\n", ListSize(&l));
    int a;
    DeleteList(0,&a, &l);
    printf(" Delete List = %d\n", a);
    printf("List Size After Deleteing one element: %d\n", ListSize(&l));
    TraversList(&l, &printlist);
    return 0;
}
