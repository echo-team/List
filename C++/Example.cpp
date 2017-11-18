#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<char>* lList = new List<char>("Hello, world!");

    /*List<int>* lCopy = lList->copy(0, 3);

    ListUnit<int>* luCurrent = lList->first;
    printf("Length is %d.\n", lList->length);
    while (luCurrent != NULL)
    {
        printf("%d ", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");*/

    ListUnit<char>* luCurrent = lList->first;
    printf("Length is %d.\n", lList->length);
    while (luCurrent != NULL)
    {
        printf("%c", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    /*for (int iCounter = 0; iCounter < 5; iCounter++)
    {
        ListUnit<int>* luNew = new ListUnit<int>(iCounter);
        list->push(luNew);
    }*/

    return 0;
}
