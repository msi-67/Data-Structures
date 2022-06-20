#include<stdio.h>
#define MAXSTACK 100

typedef enum {FAILURE, SUCCESS} status_code;
typedef enum {FALSE, TRUE} Boolean;
typedef int Item_type;

typedef struct Stack_tag
{
    int top;
    Item_type elements[MAXSTACK];
}Stack;

void Initialise_stack(Stack *stck_ptr)
{
    stck_ptr->top = -1;   
} 

Boolean isStackFull(Stack *stck_ptr)
{
    Boolean retval;
    if (stck_ptr->top == MAXSTACK - 1)
    {
        retval = TRUE;
    }
    else
    {
        retval = FALSE;
    }
    return retval;
    
}

Boolean isStackEmpty(Stack *stck_ptr)
{
    Boolean retval;
    if (stck_ptr->top == -1)
    {
        retval = TRUE;
    }
    else
    {
        retval = FALSE;
    }
    return retval;
}

status_code Push(Item_type e, Stack *stck_ptr)
{
    status_code retval = SUCCESS;
    if (isStackFull(stck_ptr))
    {
        retval = FAILURE;
    }
    else
    {
        stck_ptr->top = stck_ptr->top + 1;
        stck_ptr->elements[stck_ptr->top] = e;
    }
    return retval;
}

status_code Pop(Item_type *eptr, Stack *stck_ptr)
{
    status_code retval = SUCCESS;
    if (isStackEmpty(stck_ptr))
    {
        retval = FAILURE;
    }
    else
    {
        *eptr = stck_ptr->elements[stck_ptr->top];
        stck_ptr->top = stck_ptr->top - 1;
    }
    return retval;
}

int main()
{
    Stack mystack;
    status_code sc;
    Item_type e;
    Initialise_stack(&mystack);
    sc = Push(10, &mystack);
    sc = Push(20, &mystack);
    sc = Pop(&e, &mystack);
    printf("%d\n", e);
    sc = Pop(&e, &mystack);
    printf("%d\n", e);
    return 0;
}
