#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<char>* lList = new List<char>("Hello, world!");

    ListUnit<char>* luFounded = lList->find("wo");
    printf("\nFound on %c.\n", luFounded->element);

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
