#ifndef LISTUNIT_H

    class ListUnit
    {
        private:
            ListUnit* next;
            ListUnit* previous;
        public:
            double element;
            ListUnit(double dElement);
            ListUnit* getNext();
            ListUnit* getPrevious();
            void setNext(ListUnit* luNext);
            void setPrevious(ListUnit* luPrevious);
    };

    #define LISTUNIT_H 1
    #include <stdlib.h>
    #include <stdio.h>
    #include "../Libraries/listunit.cpp"

#endif
