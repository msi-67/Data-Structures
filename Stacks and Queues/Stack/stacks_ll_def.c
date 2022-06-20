#include<stdio.h>
#include<stdlib.h>
//#include "def.h"
#include "def_for_stacks.h"

void Initialise_Stack(Stack* stck_ptr)
{
    stck_ptr->top = NULL;
}

boolean isStackFull(Stack* stck_ptr)
{
    return FALSE;
}

status_code Push(Stack* stck_ptr, Itemtype element)
{
    Node* nptr;
    status_code sc = SUCCESS;
    nptr = (Node*)malloc(sizeof(Node));
    if (nptr == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        nptr->data = element;
        nptr->next = stck_ptr->top;
        stck_ptr->top = nptr;
    }
    return sc;
}

boolean isStackEmpty(Stack* stck_ptr)
{
    boolean b = FALSE;
    if (stck_ptr->top == NULL)
    {
        b = TRUE;
    }
    return b;
}

status_code Pop(Itemtype* element, Stack* stck_ptr)
{
    Node* nptr;
    status_code sc = SUCCESS;
    if (isStackEmpty(stck_ptr))
    {
        printf("Deleting Empty Stack not possible.");
        sc = FAILURE;
    }
    else
    {
        nptr = stck_ptr->top;
        *element = nptr->data;
        stck_ptr->top = (stck_ptr->top)->next;
        free(nptr);
    }
    return sc;
}