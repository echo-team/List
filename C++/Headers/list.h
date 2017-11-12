#ifndef LIST_H

    #include "listunit.h"

    class List
    {
        private:
            char* type;
        public:
            ListUnit* first;
            ListUnit* last;
            List(char *sType);
            void push(double dElement);
    };

    #define LIST_H 1
    #include <stdlib.h>
    #include <stdio.h>
    #include "../Libraries/list.cpp"

#endif
