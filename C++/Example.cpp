#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<char>* list = new List<char>();

    list->fromString("This is string.");

    ListUnit<char>* luCurrent = list->first;
    printf("Length is %d.\n", list->length);
    while (luCurrent != NULL)
    {
        printf("%c", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    list->fromString("This is second string.");

    printf("Length is %d.\n", list->length);
    luCurrent = list->first;
    while (luCurrent != NULL)
    {
        printf("%c", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    return 0;
}
