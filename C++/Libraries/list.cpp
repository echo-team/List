#ifdef LIST_H

    using namespace std;

    template <typename tType>
    class List
    {
        public:
            ListUnit<tType>* first;
            ListUnit<tType>* last;
            long int length;
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
            void copy(List<tType>* lCopy)
            {
                if (lCopy->first != NULL)
                {
                    return;
                }

                ListUnit<int>* luCurrent = this->first;
                while (luCurrent != NULL)
                {
                    lCopy->push(luCurrent->copy());
                    luCurrent = luCurrent->getNext();
                }
            }
            List<tType>* copy()
            {
                List<tType>* lCopy = (List<tType>*)malloc(sizeof(List<tType>));
                lCopy = new List();
                this->copy(lCopy);

                return lCopy;
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
            void insert(ListUnit<tType>* luNext, List<tType>* lInserting)
            {
                ListUnit<tType>* luCurrent = lInserting->first;
                while (luCurrent != NULL)
                {
                    this->insert(luNext, luCurrent->copy());
                    luCurrent = luCurrent->getNext();
                }
            }
            void insert(int iIndex, List<tType>* lInserting)
            {
                ListUnit<tType>* luOnPosition = this->onPosition(iIndex);
                this->insert(luOnPosition, lInserting);
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
            void from(char* sConverting)
            {
                if (this->first != NULL)
                {
                    return;
                }

                for (int iCounter = 0; iCounter < strlen(sConverting); iCounter++)
                {
                    this->push(sConverting[iCounter]);
                }
            }
            void from(string sConverting)
            {
                if (this->first != NULL)
                {
                    return;
                }

                for (int iCounter = 0; iCounter < sConverting.length(); iCounter++)
                {
                    this->push(sConverting[iCounter]);
                }
            }
            void from(tType* atConverting, int iLength)
            {
                if (this->first != NULL)
                {
                    return;
                }

                for (int iCounter = 0; iCounter < iLength; iCounter++)
                {
                    this->push(atConverting[iCounter]);
                }
            }
            void from(List<tType>* lConverting)
            {
                if (this->first != NULL)
                {
                    return;
                }

                lConverting = lConverting->copy();
                this->insert((ListUnit<tType>*)NULL, lConverting);
            }
            List()
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;
            }
            List(char* sConverting)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(sConverting);
            }
            List(string sConverting)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(sConverting);
            }
            List(tType* atConverting, int iLength)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(atConverting, iLength);
            }
            List(List<tType>* lConverting)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(lConverting);
            }

    };


#endif
