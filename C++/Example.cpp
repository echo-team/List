#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<int>* list = new List<int>();

    list->push(0);
    list->push(1);
    list->push(2);
    list->push(3);

    list->insert(0, -1);

    ListUnit<int>* luCurrent = list->first;
    printf("Length is %d.\n", list->length);
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
