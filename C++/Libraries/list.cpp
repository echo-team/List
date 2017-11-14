#ifdef LIST_H

    template <typename tType>
    class List
    {
        public:
            ListUnit<tType>* first;
            ListUnit<tType>* last;
            long int length;
            List()
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;
            }
            void push(tType tElement)
            {
                ListUnit<tType>* luEnd = this->last;
                ListUnit<tType>* luNewEnd = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luNewEnd = new ListUnit<tType>(tElement);

                if (luEnd == NULL)
                {
                    this->first = luNewEnd;
                }
                else
                {
                    luEnd->setNext(luNewEnd);
                    luNewEnd->setPrevious(luEnd);
                }

                this->last = luNewEnd;
                this->length++;
            }
            ListUnit<tType>* onPosition(int iIndex)
            {
                if (iIndex < 0 || iIndex >= this->length)
                {
                    return NULL;
                }

                ListUnit<tType>* luFounding = this->first;

                for (int iCounter = 0; iCounter < iIndex && luFounding != NULL; iCounter++)
                {
                    luFounding = luFounding->getNext();
                }

                return luFounding;
            }
            void insert(int iIndex, tType tElement)
            {
                ListUnit<tType>* luOnPosition = this->onPosition(iIndex);
                ListUnit<tType>* luInserting = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luInserting = new ListUnit<tType>(tElement);

                if (luOnPosition == NULL)
                {
                    if (iIndex == 0)
                    {
                        ListUnit<tType>* luFirst = this->first;

                        this->first = luInserting;
                        luOnPosition->setPrevious(luInserting);
                        luInserting->setNext(luOnPosition);

                        this->length++;
                    }
                    else if (iIndex == this->length)
                    {
                        this->push(luInserting->element); //Fixme!!
                        delete luInserting;
                        return;
                    }
                    else
                    {
                        delete luInserting;
                        return;
                    }
                }
                else
                {
                    ListUnit<tType>* luPrevious = luOnPosition->getPrevious();

                    luOnPosition->setPrevious(luInserting);
                    luInserting->setNext(luOnPosition);
                    luInserting->setPrevious(luPrevious);
                    luPrevious != NULL ? luPrevious->setNext(luInserting) : (void)NULL;

                    if (iIndex == 0)
                    {
                        this->first = luInserting;
                    }

                    this->length++;
                }
            }
            void remove(ListUnit<tType>* luRemoving)
            {
                ListUnit<tType>* luPrevious = luRemoving->getPrevious();
                ListUnit<tType>* luNext = luRemoving->getNext();
                this->length--;
                delete luRemoving;

                if (luPrevious == NULL)
                {
                    this->first = luNext;
                }
                else
                {
                    luPrevious->setNext(luNext);
                }

                if (luNext == NULL)
                {
                    this->last = luPrevious;
                }
                else
                {
                    luNext->setPrevious(luPrevious);
                }
            }
            void fromString(char* sConverting)
            {
                if (this->last != NULL)
                {
                    return;
                }

                for (int iCounter = 0; iCounter < strlen(sConverting); iCounter++)
                {
                    this->push(sConverting[iCounter]);
                }
            }
    };


#endif
