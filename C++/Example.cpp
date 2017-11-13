#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<double>* list = new List<double>();

    list->push(0);
    list->push(10);
    list->push(-10);
    list->push(2);
    printf("%d\n", sizeof(list->first->element));

    ListUnit<double>* luCurrent = list->first;

    while (luCurrent != NULL)
    {
        printf("%lf ", luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    return 0;
}
