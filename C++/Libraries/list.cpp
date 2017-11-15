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
            void push(ListUnit<tType>* luPushing)
            {
                ListUnit<tType>* luEnd = this->last;

                if (luEnd == NULL)
                {
                    this->first = luPushing;
                }
                else
                {
                    luEnd->setNext(luPushing);
                    luPushing->setPrevious(luEnd);
                }

                this->last = luPushing;
                this->length++;
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
            void insert(ListUnit<tType>* luNext, ListUnit<tType>* luInserting)
            {
                if (luNext == NULL)
                {
                    this->push(luInserting);
                }
                else
                {
                    ListUnit<tType>* luPrevious = luNext->getPrevious();

                    if (luPrevious == NULL)
                    {
                        this->first = luInserting;
                    }
                    else
                    {
                        luPrevious->setNext(luInserting);
                    }

                    luNext->setPrevious(luInserting);
                    luInserting->setNext(luNext);
                    luInserting->setPrevious(luPrevious);
                    this->length++;
                }
            }
            void insert(ListUnit<tType>* luNext, tType tElement)
            {
                ListUnit<tType>* luInserting = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luInserting = new ListUnit<tType>(tElement);

                this->insert(luNext, luInserting);
            }
            void insert(int iIndex, ListUnit<tType>* luInserting)
            {
                ListUnit<tType>* luOnPosition = this->onPosition(iIndex);
                this->insert(luOnPosition, luInserting);
            }
            void insert(int iIndex, tType tElement)
            {
                ListUnit<tType>* luOnPosition = this->onPosition(iIndex);
                ListUnit<tType>* luInserting = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luInserting = new ListUnit<tType>(tElement);

                this->insert(luOnPosition, luInserting);
            }
            void remove(ListUnit<tType>* luRemoving)
            {
                if (luRemoving == NULL)
                {
                    return;
                }

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
            void remove(int iIndex)
            {
                ListUnit<tType>* luRemoving = this->onPosition(iIndex);
                this->remove(luRemoving);
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
