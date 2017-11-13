#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<int>* list = new List<int>();

    list->push(0);
    list->push(10);
    list->push(-10);
    list->push(2);

    ListUnit<int>* luCurrent = list->first;
    ListUnit<int>* luRemove = NULL;
    while (luCurrent != NULL)
    {
        printf("%d ", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    luRemove = list->onPosition(1);
    printf("Removing %d...\n", luRemove->element);
    list->remove(luRemove);
    luCurrent = list->first;
    while (luCurrent != NULL)
    {
        printf("%d ", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    return 0;
}
