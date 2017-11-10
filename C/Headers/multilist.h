#ifndef MULTILIST_H

    #ifndef LIST_H
        #include "list.h"
    #endif

    listUnit* listPushSublist(list* lList, list* lSublist);
    void multilistForEach(list* lList, void (*listProcessor)(list* lSublist, int iIndex));

    #define MULTILIST_H 1
    #include "../Libraries/multilist.c"

#endif