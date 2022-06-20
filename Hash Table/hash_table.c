#include<stdlib.h>
#include<stdio.h>
#define HASHSIZE 997
typedef int ITEM_TYPE;
typedef struct node
{
    ITEM_TYPE key;
    ITEM_TYPE info;
}data;

typedef struct node_tag
{
    data info;
    struct node_tag *next;
}list;

list *hash[HASHSIZE];

int hash_fn(int key)
{
    return key%HASHSIZE;
}

void initialise_hash()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        hash[i] = NULL;
    }
}

list* create_list_node()
{
    list* nptr = (list*)malloc(sizeof(list));
    if(nptr!= NULL)
    {
        nptr->next = NULL;
    }
    return nptr;
}

void insert(list* node)
{
    int search_index;
    search_index = hash_fn(node->info.key);
    node->next = hash[search_index];
    hash[search_index] = node;
}

void view()
{
    int a;
    list* nptr, *pptr;
    for(int i = 0; i < HASHSIZE; i++)
    {
        if(hash[i] != NULL)
        {
            nptr = hash[i];
            while (nptr != NULL)
            {
                printf("The info at key %d is %d\n",nptr->info.key, nptr->info.info);
                nptr = nptr->next;
            }
        }
    }   
}

void search(int key)
{
    int index = hash_fn(key);
    list* nptr = hash[index];
    while (nptr != NULL && nptr->info.key != key)
    {
        nptr = nptr->next;
    }
    if( nptr!= NULL)
    {
        printf("Info at %d key requested is %d.\n",nptr->info.key, nptr->info.info);
    }
    else
    {
        printf("The key couldnot be found.\n");
    }
}

void delete_by_index(int key)
{
    int index = hash_fn(key);
    list* nptr = hash[index], *lptr;
    while (nptr != NULL)
    {
        printf("Deleting data at %d key.%d\n",nptr->info.key, nptr->info.info);
        lptr = nptr;
        nptr = nptr->next;
        free(lptr);
    }
}

void delete_by_key(int key)
{
    list* prev, *curr;
    int ind = hash_fn(key);
    curr = hash[ind];
    if(curr == NULL)
    {
        printf("Key not present.\n");
        return;
    }
    while (curr != NULL && curr->info.key != key)
    {
        prev = curr;
        curr = curr->next;    
    }
    if(curr != NULL)
    {
        prev->next = curr->next;
        printf("Deleting info %d at key %d.\n",curr->info.info, curr->info.key);
        free(curr); 
    }
    else
    {
        printf("Key not found.");
    }
}

void delete_all()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        delete_by_index(i);
    }   
}

list* Create_Record(int key, int info)
{
    list* nptr = create_list_node();
    nptr->info.info = info;
    nptr->info.key = key;
    return nptr;
}

int main()
{
    int key, info;
    list *pptr;
    int num;
    initialise_hash();
    printf("Enter the number of data you want to enter :");
    scanf("%d",&num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter the key of the number : ");
        scanf("%d",&key);
        printf("Enter the info to be kept at the key : ");
        scanf("%d",&info);
        pptr = Create_Record(key,info);
        insert(pptr);
    }
    view();
    int ser;
    printf("Enter the key you wish to search : ");
    scanf("%d",&ser);
    search(ser);
    printf("Enter the key you wish to delete : ");
    scanf("%d",&ser);
    delete_by_key(ser);
    view();       
    delete_all();
}