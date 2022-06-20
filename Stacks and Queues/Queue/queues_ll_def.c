#include<stdio.h>
#include<stdlib.h>
#include "def_for_queues.h"

void Initialise_Queue(Queue* qptr)
{
    qptr->front = NULL;
    qptr->rear = NULL;
}

boolean IsQueueEmpty(Queue* qptr)
{
    return (qptr->front == NULL && qptr->rear == NULL);
}

status_code Insert(Queue* qptr, Itemtype data)
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
        nptr->element = data;
        nptr->next = NULL;
        if (IsQueueEmpty(qptr))
        {
            qptr->rear = nptr;
            qptr->front = nptr;
        }
        else
        {
            qptr->rear->next = nptr;
            qptr->rear = nptr;
        }
    }
    return sc;
}

status_code Delete(Queue* qptr, Itemtype* data)
{
    Node* nptr;
    status_code sc = SUCCESS;
    if (IsQueueEmpty(qptr))
    {
        sc = FAILURE;
        printf("Deleting Empty Queue not possible. \n");
    }
    else
    {
        nptr = qptr->front;
        *data = nptr->element;
        qptr->front = (qptr->front)->next; // In a single node case hee front will become NULL.
        if (qptr->front == NULL)
        {
            qptr->rear = NULL;
        }
        free(nptr);
    }
    return sc;
}