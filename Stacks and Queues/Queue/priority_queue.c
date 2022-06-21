#include<stdio.h>
#include<stdlib.h>
#include "def_for_queues.h"
#define NUM_PRIORITIES 100
typedef struct PG_tag
{
    Queue Priority_Queue_Array[NUM_PRIORITIES];
    int num_prior;
} PriorityQueue;

void InitialisePriorityQueues(PriorityQueue* pq)
{
    //pq->num_prior = NUM_PRIORITIES;
    for (int i = 0; i < NUM_PRIORITIES; i++)
    {
        Initialise_Queue(&pq->Priority_Queue_Array[i]);
    }
}
status_code Insert_process(PriorityQueue *pq, int pr, int data) // pr is the priority number data is data
{
    status_code sc;
    int rank = pr;
    int d = data;
    sc = Insert(&pq->Priority_Queue_Array[rank], d);
    return sc;
}

status_code Delete_Process(PriorityQueue *pq, Itemtype* pb, int* pr)
{
    int i = 0;
    status_code sc = SUCCESS;
    while (i<NUM_PRIORITIES && (IsQueueEmpty(&pq->Priority_Queue_Array[i])))
    {
        i++;
    }

    if(i < NUM_PRIORITIES)
    {
        Delete(&pq->Priority_Queue_Array[i], pb);
        *pr = i;
    }
    else
    {
        sc = FAILURE;
    }
    return sc;
}
//Array of queses

int main()
{
    PriorityQueue pq;
    InitialisePriorityQueues(&pq);
    status_code sc;
    Itemtype element;
    int pr;
    int iterator;
    printf("Enter the number of item to be inserted into priority queue with their priority: ");
    scanf("%d",&iterator);
    for (int i = 0; i < iterator; i++)
    {
        printf("Enter the priority of the item to be inserted into priority queue: ");
        scanf("%d",&pr);
        printf("Enter the data of the item to be inserted into priority queue: ");
        scanf("%d",&element);
        sc = Insert_process(&pq,pr,element);
    }
    printf("Enter the number of processes to be deleted out of the Priority Queue: ");
    scanf("%d",&iterator);
    for (int i = 0; i < iterator; i++)
    {
        sc = Delete_Process(&pq, &element, &pr);
        printf("The deleted element is %d with %d priority. \n",element, pr);
    }
    return 0;   
}