#ifdef LIST_H

    template <typename tType>
    class List
    {
        public:
            ListUnit<tType>* first;
            ListUnit<tType>* last;
            List()
            {
                this->first = NULL;
                this->last = NULL;
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
                }

                this->last = luNewEnd;
            }
    };


#endif
