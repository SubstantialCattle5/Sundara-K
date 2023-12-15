#include <stdio.h>
#include "DataStructure/list/Queue.h"

#include <time.h>

int main()
{
    struct Queue list = queue_constructor();

    for (int i = 0; i < 10; i++)
    {
        char x[3] = "xyz";
        list.push(&x,&list, 3);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", ((char *)list.peek(&list))[0]);
        printf("%c\n", ((char *)list.peek(&list))[1]);

        list.pop(&list);
    }

    queue_destructor(&list);
}