typedef int Itemtype;
typedef enum {FAILURE, SUCCESS} status_code;
typedef enum {FALSE, TRUE} boolean;

typedef struct Node_tag
{
    Itemtype element;
    struct Node_tag* next;
}Node;

typedef struct Queue_tag
{
    Node* front;
    Node* rear;
}Queue;

void Initialise_Queue(Queue* qptr);
boolean IsQueueEmpty(Queue* ptr);
status_code Insert(Queue* qptr, Itemtype data);  // Insert at end
//We didnt do insert at start and delete at end because 
//if we tred to delete at end we have to know the prev pointer to set it to null.
status_code Delete(Queue* qptr, Itemtype* data);// Delete at start