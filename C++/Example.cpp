#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<int>* lList = new List<int>();
    List<int>* lCopy = new List<int>();

    lList->push(0);
    lList->push(1);
    lList->push(2);
    lList->push(3);

    lList->copy(lCopy);

    ListUnit<int>* luCurrent = lCopy->first;
    printf("Length is %d.\n", lCopy->length);
    while (luCurrent != NULL)
    {
        printf("%d ", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    lList->push(4);

    luCurrent = lList->first;
    printf("Length is %d.\n", lCopy->length);
    while (luCurrent != NULL)
    {
        printf("%d ", luCurrent->element);
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
