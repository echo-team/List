#ifdef LIST_H


    List::List(char *sType)
    {
        this->type = sType;
        this->first = NULL;
        this->last = NULL;
    }
    void List::push(double dElement)
    {
        ListUnit* luEnd = this->last;
        ListUnit* luNewEnd = (ListUnit*)malloc(sizeof(ListUnit));
        luNewEnd = new ListUnit(dElement);

        if (luEnd == NULL)
        {
            this->first = luNewEnd;
        }
        else
        {
            luEnd->setNext(luNewEnd);
        }

        this->last = luNewEnd;
    }

#endif
