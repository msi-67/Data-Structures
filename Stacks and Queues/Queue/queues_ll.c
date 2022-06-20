#include<stdio.h>
#include "def_for_queues.h"

int main()
{
    Queue q1;
    status_code sc;
    Itemtype element;
    Initialise_Queue(&q1);
    int iterator;
    printf("Enter the number of item to be inserted into queue: ");
    scanf("%d",&iterator);
    for (int i = 0; i < iterator; i++)
    {
        printf("Enter the item to be inserted into queue: ");
        scanf("%d",&element);
        sc = Insert(&q1, element);
    }
    sc = IsQueueEmpty(&q1);
    if (sc == 0)
    {
        printf("Queue is not empty.\n");
    }
    else
    {
        printf("Queue is empty.\n");
    }

    printf("Enter the number of item to be deleted out of Queue: ");
    scanf("%d",&iterator);
    for (int i = 0; i < iterator; i++)
    {
        sc = Delete(&q1, &element);
        printf("The deleted element is %d. \n",element);
    }
    return 0;
}