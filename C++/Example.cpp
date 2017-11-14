#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<int>* list = new List<int>();

    for (int iCounter = 0; iCounter < 5; iCounter++)
    {
        ListUnit<int>* luNew = new ListUnit<int>(iCounter);
        list->push(luNew);

        printf("Length is %d.\n", list->length);

        ListUnit<int>* luCurrent = list->first;
        while (luCurrent != NULL)
        {
            printf("%d ", luCurrent->element);
            luCurrent = luCurrent->getNext();
        }

        printf("\n");
    }

    return 0;
}
