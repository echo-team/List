#ifdef LIST_H

    list* listCreate(char* sType)
    {
        list* lCreated = (list*)malloc(sizeof(list));
        *lCreated = (list){NULL, NULL, sType};
        return lCreated;
    }

    list* listCreateSlice(char* sType, listUnit* luFirst, listUnit* luLast)
    {
        list* lSlice = listCreate(sType);
        listUnit* luCurrent = luFirst;

        while (luCurrent != NULL && luCurrent != luLast)
        {
            listPush(lSlice, luCurrent->element);
            luCurrent = luCurrent->next;
        }
        
        listPush(lSlice, luLast->element);
        
        return lSlice;
    }

    list* listFromString(char* sString)
    {
        list *lList = listCreate("c");
        
        for (int iCounter = 0; sString[iCounter] != '\0'; iCounter++)
        {
            listPush(lList, sString[iCounter]);
        }
        
        return lList;
    }

    listUnit* listUnitAt(list* lList, int iIndex)
    {
        listUnit* lToIndex = lList->next;

        while (lToIndex != NULL && lToIndex->next != NULL && iIndex > 0)
        {
            lToIndex = lToIndex->next;
            iIndex--;
        }

        return lToIndex;
    }

    listUnit* listGetLast(list *lList)
    {
        return lList->last;
    }

    void listPush(list* lList, double cElement)
    {
        listUnit* lEnd = listGetLast(lList);
        listUnit* lNewEnd = (listUnit*)malloc(sizeof(listUnit));
        *lNewEnd = (listUnit){cElement, NULL, lEnd, NULL};
        if (lEnd == NULL)
        {
            lList->next = lNewEnd;
        }
        else
        {
            lEnd->next = lNewEnd;
        }
        lList->last = lNewEnd;
    }

    void listPushBefore(list* lList, double cElement, int iIndex)
    {
        listUnit* lIndex = listUnitAt(lList, iIndex);
        
        if (lIndex != NULL)
        {
            listUnit* lPrevious = lIndex->previous;
            listUnit* lNew = (listUnit*)malloc(sizeof(listUnit));
            *lNew = (listUnit){cElement, NULL, lPrevious, lIndex};
            lIndex->previous = lNew;

            if (lPrevious != NULL)
            {
                lPrevious->next = lNew;
            }
            else
            {
                lList->next = lNew;
            }
        }
    }

    void listRemove(list* lList, listUnit* lIndex)
    {
        listUnit* lNext = lIndex->next;
        listUnit* lPrevious = lIndex->previous;
        
        if (lPrevious == NULL)
        {
            lList->next = lNext;
        }
        else
        {
            lPrevious->next = lNext;
        }
        
        if (lNext != NULL)
        {
            lNext->previous = lPrevious;
        }
        else
        {
            lList->last = lPrevious;
        }

        free(lIndex);
    }

    void listForEach(list* lList, void (*listProcessor)(double dElement, int iIndex, char* sType))
    {
        listUnit* luUnit = lList->next;
        
        int iCounter = 0;
        while (luUnit != NULL)
        {
            (*listProcessor)(luUnit->element, iCounter, lList->type);
            luUnit = luUnit->next;
            iCounter++;
        }
    }

    void listElementPrint(double dElement, int iIndex, char* sType)
    {
        printf("%c", (char)dElement);
    }

    void listPrint(list* lList)
    {
        listForEach(lList, listElementPrint);
        printf("\n");
    }

#endif