#include "Headers/list.h"

using namespace std;

int main()
{
    List list("d");

    list.push(0);
    list.push(10);
    list.push(-10);
    list.push(2);

    ListUnit* luCurrent = list.first;

    while (luCurrent != NULL)
    {
        printf("%d ", (int)luCurrent->element);
        luCurrent = luCurrent->getNext();
    }

    printf("\n");

    return 0;
}
