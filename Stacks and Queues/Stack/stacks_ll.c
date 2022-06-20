#include<stdio.h>
#include "def_for_stacks.h"

int main()
{
    Stack stck;
    status_code sc;
    Itemtype element;
    Initialise_Stack(&stck);
    int iterator;
    printf("Enter the number of item to be pushed into stack: ");
    scanf("%d",&iterator);
    for (int i = 0; i < iterator; i++)
    {
        printf("Enter the item to be pushed into stack: ");
        scanf("%d",&element);
        sc = Push(&stck, element);
    }
    sc = isStackEmpty(&stck);
    if (sc == 0)
    {
        printf("Stack is not emppty.\n");
    }
    else
    {
        printf("Stack is empty.\n");
    }

    printf("Enter the number of item to be poped out of stack: ");
    scanf("%d",&iterator);
    for (int i = 0; i < iterator; i++)
    {
        sc = Pop(&element, &stck);
        printf("The poped element is %d. \n",element);
    }
    return 0;
}