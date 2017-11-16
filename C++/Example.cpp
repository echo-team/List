#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<int>* lList = new List<int>();

    lList->push(0);
    lList->push(1);
    lList->push(2);
    lList->push(3);

    lList->remove(-1, 2);

    ListUnit<int>* luCurrent = lList->first;
    printf("Length is %d.\n", lList->length);
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
