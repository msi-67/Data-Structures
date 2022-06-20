#include<stdio.h>
#define QSIZE 100
typedef enum {FALSE, TRUE} Boolean;
typedef enum {FAILURE, SUCCESS} status_code;
typedef int Item_type;

typedef struct Queue_tag
{
    int front;
    int rear;
    int count;
    Item_type elements[QSIZE];
}Queue;

void Initialise_Queue(Queue *q_ptr)
{
    q_ptr->front = 0;
    q_ptr->rear = -1;
    q_ptr->count = 0;
}

int NumElementsinQ(Queue *q_ptr)
{
    int retval;
    if (q_ptr->rear >= q_ptr->front)
    {
        retval = q_ptr->rear - q_ptr->front + 1;
    }
    else
    {
        retval = q_ptr->rear - q_ptr->front + 1 + QSIZE;
    }
    return retval;    
}

Boolean isQueueFull(Queue *q_ptr)
{
    Boolean retval;
    if (q_ptr->count == QSIZE)
    {    
        retval = TRUE;
    }
    else
    {
        retval = FALSE;
    }
    return retval;
}

Boolean isQueueEmpty(Queue *q_ptr)
{
    Boolean retval;
    if (q_ptr->count == 0)
    {
        retval = TRUE;
    }
    else
    {
        retval = FALSE;
    }
    return retval;
}

status_code InsertQ(Item_type e, Queue *q_ptr)
{
    status_code retval = SUCCESS;
    if (isQueueFull(q_ptr))
    {
        retval = FAILURE;
    }
    else
    {
        q_ptr->rear = (q_ptr->rear + 1)%QSIZE;
        q_ptr->elements[q_ptr->rear] = e;
        q_ptr->count = q_ptr->count + 1;
    }
    return retval;
}

status_code DeleteQ(Item_type *eptr, Queue *q_ptr)
{
    status_code retval = SUCCESS;
    if (isQueueEmpty(q_ptr))
    {
        retval = FAILURE;
    }
    else
    {
        *eptr = q_ptr->elements[q_ptr->front];
        q_ptr->front = (q_ptr->front+1)%QSIZE;
        q_ptr->count = q_ptr->count - 1;
    }
    return retval;
}

int main()
{
    Queue Q1;
    status_code sc;
    Item_type e;
    int a;
    Initialise_Queue(&Q1);
    sc = InsertQ(10, &Q1);
    sc = InsertQ(20, &Q1);
    sc = InsertQ(30, &Q1);
    sc = DeleteQ(&e, &Q1);
    printf("%d\n",e);
    sc = DeleteQ(&e, &Q1);
    printf("%d\n",e);
    sc = DeleteQ(&e, &Q1);
    printf("%d\n",e);
}