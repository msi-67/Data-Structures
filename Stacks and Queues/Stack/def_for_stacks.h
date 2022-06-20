typedef int Itemtype;
typedef enum {FAILURE, SUCCESS} status_code;
typedef enum {FALSE, TRUE} boolean;

typedef struct Node_tag
{
    Itemtype data;
    struct Node_tag* next;
}Node;

typedef struct Stack_tag //Why was this initialise as a struct_tag why not just node* top ?
//there is only one element so why is the declaration a structure? Whats the problem in this case?
//1. Tomorrow if we have different stacks like stck1 and stck2 
//they will have different top as top is a field of struct stack.
//2. Everywhere where i wrote Stack i would have to write Node* top.
{
    Node* top;
}Stack;
 
void Initialise_Stack(Stack* stck_ptr);
boolean isStackFull(Stack* stck_ptr);
status_code Push(Stack* stck_ptr, Itemtype element);
boolean isStackEmpty(Stack* stck_ptr);
status_code Pop(Itemtype* elememt, Stack* stck_ptr);
