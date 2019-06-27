#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "generico.h"
#include "valid.h"

int main()
{
    LinkedList* lista = ll_newLinkedList();

    if(!controller_loadFromText("data.csv", lista))
    {
        controller_saveAsText("atr.txt", lista);
    }
    return 0;
}
