#ifdef LIST_H

    listUnit* listPushSublist(list* lList, list* lSublist)
    {
        listUnit* lEnd = listGetLast(lList);
        listUnit* lNew = (listUnit*)malloc(sizeof(listUnit));
        *lNew = (listUnit){0, lSublist, lEnd, NULL};
        if (lEnd == NULL)
        {
            lList->next = lNew;
        }
        else
        {
            lEnd->next = lNew;
        }
        
        return lNew;
    }

    void multilistForEach(list* lList, void (*listProcessor)(list* lSublist, int iIndex))
    {
        listUnit* luUnit = lList->next;
        
        int iCounter = 0;
        while (luUnit != NULL)
        {
            (*listProcessor)(luUnit->sublist, iCounter);
            luUnit = luUnit->next;
            iCounter++;
        }
    }

#endif