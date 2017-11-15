#include <stdio.h>
#include "Headers/list.h"

using namespace std;

int main()
{
    List<char>* lList = new List<char>();
    string sFrom = "It is List from string.";

    lList->from(sFrom);
    /*List<int>* lInserting = new List<int>();

    lList->push(0);
    lList->push(1);
    lInserting->push(2);
    lInserting->push(3);

    lList->insert(0, lInserting);*/

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
