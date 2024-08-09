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
    InsertOrderList(40, &l);
    InsertOrderList(20, &l);
    InsertOrderList(30, &l);
    InsertOrderList(10, &l);

    printf("List Empty After adding %d\n", ListEmpty(&l));
    printf("List Size : %d\n", ListSize(&l));
    int a;
    DeleteList(0,&a, &l);
    printf(" Delete List = %d\n", a);
    printf("List Size After Deleteing one element: %d\n", ListSize(&l));
    TraversList(&l, &printlist);
    int index = SearchList(30, &l);
    if(index == -1) 
        printf("don't found \n");
    else{
         int b;
         RetriveList(index, &b ,&l);
         printf(" 30 founded in %d : \n",index);
         printf("retrive list in index %d, is : %d\n", index, b);
    }


    return 0;
}
