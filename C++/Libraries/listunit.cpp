#ifdef LISTUNIT_H

    ListUnit::ListUnit(double dElement)
    {
        this->element = dElement;
        this->next = NULL;
        this->previous = NULL;
    }
    ListUnit* ListUnit::getNext()
    {
        return this->next;
    }
    ListUnit* ListUnit::getPrevious()
    {
        return this->previous;
    }
    void ListUnit::setNext(ListUnit* luNext)
    {
        this->next = luNext;
    }
    void ListUnit::setPrevious(ListUnit* luPrevious)
    {
        this->previous = luPrevious;
    }

#endif
