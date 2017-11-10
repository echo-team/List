#ifndef LIST_H

    struct list
    {
        struct listUnit* next;
        struct listUnit* last;
        char* type;
    };
    typedef struct list list;

    struct listUnit
    {
        double element;
        struct list* sublist;
        struct listUnit* previous;
        struct listUnit* next;
    };
    typedef struct listUnit listUnit;

    struct listSlice
    {
        struct listUnit* first;
        struct listUnit* last;
    };
    typedef struct listSlice listSlice;

    list* listCreate(char* type);
    list* listFromString(char* sString);
    list* listCreateSlice(char* sType, listUnit* luFirst, listUnit* luLast);
    listUnit* listGetLast(list *lList);
    void listPush(list* lList, double cElement);
    void listPushBefore(list* lList, double cElement, int iIndex);
    void listRemove(list* lList, listUnit* lIndex);
    void listForEach(list* lList, void (*listProcessor)(double dElement, int iIndex, char* sType));
    void listElementPrint(double dElement, int iIndex, char* sType);
    void listPrint(list* lList);

    #define LIST_H 1
    #include <stdlib.h>
    #include <stdio.h>
    #include "../Libraries/list.c"

#endif