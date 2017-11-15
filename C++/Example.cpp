#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<int>* lTo = new List<int>();
    List<int>* lList = new List<int>();

    lList->push(0);
    lList->push(1);
    lList->push(2);
    lList->push(3);

    lTo->from(lList);

    ListUnit<int>* luCurrent = lTo->first;
    printf("Length is %d.\n", lTo->length);
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
