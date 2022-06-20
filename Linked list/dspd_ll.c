#include<stdio.h>
#include<string.h>
#include "dspd_ll.h"

void Get_Prof_Data(Professional_Contact *nptr)
{
 //   getchar();
    printf("Enter the name to be stored :(Preferably full name)");
    scanf("%s",nptr->name);
    printf("Enter the mobile number to be stored :");
    scanf("%s",nptr->mob);
    printf("Enter the email to be stored :");
    scanf("%s",nptr->email);
    printf("Enter the office address to be entered :");
    getchar();
    gets(nptr->Address);
    printf("Enter the office Number : ");
    scanf("%s",nptr->Office_Number);
}

void Get_Personal_Data(Personal_Contact *nptr)
{
   // getchar();
    printf("Enter the name to be stored :(Preferably full name):");
    scanf("%s",nptr->name);
    //printf("Enter the last name to be stored :");
    //gets(nptr->last_name);
    printf("Enter the mobile number to be stored :");
    scanf("%s",nptr->mob);
    printf("Enter the email to be stored :");
    scanf("%s",nptr->email);
}

Personal_Contact* Create_Per_Node()
{
    Personal_Contact* nptr;
    nptr = (Personal_Contact*)malloc(sizeof(Personal_Contact));
    if(nptr != NULL)
    {
        //getchar();
        Get_Personal_Data(nptr);
        nptr->next = NULL;        
    }
    return nptr;
}

Professional_Contact* Create_Prof_Node()
{
    Professional_Contact* nptr;
    nptr = (Professional_Contact*)malloc(sizeof(Professional_Contact));
    if(nptr != NULL)
    {
        //getchar();
        fflush(stdin);
        Get_Prof_Data(nptr);
        nptr->next = NULL;        
    }
    return nptr;
}

void Insert_in_Per_Con_sorted(Personal_Contact *nptr, Personal_Contact **pptr)
{
    Personal_Contact *head = *pptr;
    Personal_Contact *curr = head;
    Personal_Contact *prev_node = NULL;
    nptr->next = NULL;
    int done = 0;
    int new_head = 0;
    if (head == NULL)
    {
        head = nptr;
    }
    else
    {
        while (!done && curr != NULL)
        {
            if (strcasecmp(nptr->name,curr->name)> 0)
            {
                prev_node = curr;
                curr = curr->next;
            }
            else if (strcasecmp(nptr->name, curr->name)<0)
            {
                if(prev_node != NULL)
                    prev_node->next = nptr;
                else
                    new_head = 1;
                nptr->next = curr;
                done = 1;
            }
            else if (strcasecmp(nptr->name, curr->name) == 0)
            {
                if (strcmp(nptr->mob, curr->mob) > 0)
                {
                    if (curr->next == NULL)
                    {
                        curr->next = nptr;
                        done = 1;
                    }
                    else
                    {
                        nptr->next = curr->next;
                        curr->next = nptr;
                        done = 1;
                    }
                }
                else
                {
                    if (prev_node != NULL)
                    {
                        prev_node->next = nptr;
                    }
                    else
                    {
                        new_head = 1;
                    }
                    nptr->next = curr;
                    done = 1;
                }
            }
        }
        if (curr == NULL)
        {
            prev_node->next = nptr;
        }
        if (new_head == 1)
        {
            head = nptr;
        }
    }
    *pptr = head;
}

void Insert_in_Prof_Con_sorted(Professional_Contact *nptr, Professional_Contact **pptr)
{
    Professional_Contact *head = *pptr;
    Professional_Contact *curr = head;
    Professional_Contact *prev_node = NULL;
    nptr->next = NULL;
    int done = 0;
    int new_head = 0;
    if (head == NULL)
    {
        head = nptr;
    }
    else
    {
        while (!done && curr != NULL)
        {
            if (strcasecmp(nptr->name,curr->name)> 0)
            {
                prev_node = curr;
                curr = curr->next;
            }
            else if (strcasecmp(nptr->name, curr->name)<0)
            {
                if(prev_node != NULL)
                    prev_node->next = nptr;
                else
                    new_head = 1;
                nptr->next = curr;
                done = 1;
            }
            else if (strcasecmp(nptr->name, curr->name) == 0)
            {
                if (strcmp(nptr->mob, curr->mob) > 0)
                {
                    if (curr->next == NULL)
                    {
                        curr->next = nptr;
                        done = 1;
                    }
                    else
                    {
                        nptr->next = curr->next;
                        curr->next = nptr;
                        done = 1;
                    }
                }
                else
                {
                    if (prev_node != NULL)
                    {
                        prev_node->next = nptr;
                    }
                    else
                    {
                        new_head = 1;
                    }
                    nptr->next = curr;
                    done = 1;
                }
            }
        }
        if (curr == NULL)
        {
            prev_node->next = nptr;
        }
        if (new_head == 1)
        {
            head = nptr;
        }
    }
    *pptr = head;
}

//Main insert function
status_code Insert_a_per_con(Personal_Contact **pptr)
{
    status_code sc = SUCCESS;
    Personal_Contact* nptr;
    nptr = Create_Per_Node();
    if (nptr == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        Insert_in_Per_Con_sorted(nptr, pptr);
    }
    return sc;
}

//Main Insert function
status_code Insert_a_prof_con(Professional_Contact **pptr)
{
    status_code sc = SUCCESS;
    Professional_Contact* nptr;
    nptr = Create_Prof_Node();
    if (nptr == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        Insert_in_Prof_Con_sorted(nptr, pptr);
    }
    return sc;
}

void Print_Personal_Data(Personal_Contact *nptr)
{
    if (nptr != NULL)
    {
        puts(nptr->name);
        //puts(nptr->name);
        puts(nptr->mob);
        puts(nptr->email);
    }
    else
    {
        printf("The node does not exist.");
    }
}

void Print_Prof_Data(Professional_Contact *nptr)
{
    if (nptr != NULL)
    {
        puts(nptr->name);
        //puts(nptr->name);
        puts(nptr->mob);
        puts(nptr->email);
        puts(nptr->Office_Number);
        puts(nptr->Address);
    }
    else
    {
        printf("The node does not exist.");
    }
}

//display
void Print_All_Personal_Contact(Personal_Contact* pptr)
{
    Personal_Contact* nptr = pptr;
    if (nptr == NULL)
    {
        printf("Emppty personal Contact List.");
    }
    while (nptr != NULL)
    {
        Print_Personal_Data(nptr);
        printf("\n");
        nptr = nptr->next;
    }
}

//display
void Print_All_Prof_Contact(Professional_Contact* pptr)
{
    Professional_Contact* nptr = pptr;
    if (nptr == NULL)
    {
        printf("Emppty proffessional Contact List.");
    }
    while (nptr != NULL)
    {
        Print_Prof_Data(nptr);
        printf("\n");
        nptr = nptr->next;
    }
}

//search
Personal_Contact* Search_for_contact(Personal_Contact* pptr,char name[SIZE], char mob[SIZE])
{
    Personal_Contact* nptr = pptr;
    Personal_Contact* data = NULL;
    int found = 0;
    while (nptr != NULL && !found)
    {
        if (strcasecmp(name,nptr->name) == 0 && strcmp(mob, nptr->mob) == 0)
        {
            found = 1;
            data = nptr;
        }
        nptr = nptr->next;
    }
    if (found == 0)
    {
        printf("No such contact exists. Please mmention correct name and mobile number.");
    }
    return data;
}

//search
Professional_Contact* Search_for_prof_contact(Professional_Contact* pptr,char name[SIZE], char mob[SIZE])
{
    Professional_Contact* nptr = pptr;
    Professional_Contact* data = NULL;
    int found = 0;
    while (nptr != NULL && !found)
    {
        if (strcasecmp(name,nptr->name) == 0 && strcmp(mob, nptr->mob) == 0)
        {
            found = 1;
            data = nptr;
        }
        nptr = nptr->next;
    }
    if (found == 0)
    {
        printf("No such contact exists. Please mmention correct name and mobile number.");
    }
    return data;
}

//Delete function
status_code Delete_per_Contact(Personal_Contact **pptr, char name[SIZE], char mob[SIZE])
{
    status_code sc = SUCCESS;
    Personal_Contact *nptr = *pptr;
    Personal_Contact *prev_node = NULL, *curr = nptr;
    //int ishead = 0;
    int done = 0;
    while (!done && curr != NULL)
    {
        if (strcasecmp(curr->name, name) == 0 && strcmp(curr->mob, mob) == 0)
        {
            if (prev_node == NULL)
            {
                nptr = curr->next;
                free(curr);
            }
            else if (curr->next == NULL)
            {
                prev_node->next = NULL;
                free(curr);
            }
            else
            {
                prev_node->next = curr->next;
                free(curr);
            }
            done = 1;
        }
        prev_node = curr;
        curr = curr->next;
    }
    if (done == 0)
    {
        printf("Contact not found.\n");
        sc = FAILURE;
    }
    *pptr = nptr;
    return sc;
}

//Delete function
status_code Delete_prof_Contact(Professional_Contact **pptr, char name[SIZE], char mob[SIZE])
{
    status_code sc = SUCCESS;
    Professional_Contact *nptr = *pptr;
    Professional_Contact *prev_node = NULL, *curr = nptr;
    //int ishead = 0;
    int done = 0;
    while (!done && curr != NULL)
    {
        if (strcasecmp(curr->name, name) == 0 && strcmp(curr->mob, mob) == 0)
        {
            if (prev_node == NULL)
            {
                nptr = curr->next;
                free(curr);
            }
            else if (curr->next == NULL)
            {
                prev_node->next = NULL;
                free(curr);
            }
            else
            {
                prev_node->next = curr->next;
                free(curr);
            }
            done = 1;
        }
        prev_node = curr;
        curr = curr->next;
    }
    if (done == 0)
    {
        printf("Contact not found.\n");
        sc = FAILURE;
    }
    *pptr = nptr;
    return sc;
}
//Edits function

void Delete_per_entire(Personal_Contact **pptr)
{
    Personal_Contact* nptr = *pptr;
    Personal_Contact* ptr;
    if (nptr == NULL)
    {
        printf("List is alreadt empty");
    }
    else
    {
        while (nptr != NULL)
        {
            ptr = nptr;
            nptr = nptr->next;
            *pptr = nptr;
            free(ptr);
        }
    }
}

void Delete_prof_entire(Professional_Contact **pptr)
{
    Professional_Contact* nptr = *pptr;
    Professional_Contact* ptr;
    if (nptr == NULL)
    {
        printf("List is alreadt empty");
    }
    else
    {
        while (nptr != NULL)
        {
            ptr = nptr;
            nptr = nptr->next;
            *pptr = nptr;
            free(ptr);
        }
    }
}

status_code Edit_per_Contact_completely(Personal_Contact **pptr, char name[SIZE], char mob[SIZE])
{
    status_code sc = SUCCESS;;
    Personal_Contact* nptr;
    nptr = Create_Per_Node();
    if (nptr == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        Delete_per_Contact(pptr, name, mob);
        Insert_in_Per_Con_sorted(nptr, pptr);
    }
    return sc;
}

status_code Edit_prof_Contact_completely(Professional_Contact **pptr, char name[SIZE], char mob[SIZE])
{
    status_code sc = SUCCESS;;
    Professional_Contact* nptr;
    nptr = Create_Prof_Node();
    if (nptr == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        Delete_prof_Contact(pptr, name, mob);
        Insert_in_Prof_Con_sorted(nptr, pptr);
    }
    return sc;
}

status_code Edit_per_Contact(Personal_Contact *pptr, char name[SIZE], char mob[SIZE])
{
    status_code sc = SUCCESS;;
    Personal_Contact* nptr;
    nptr = Search_for_contact(pptr, name, mob);
    int i = 0;
    if (nptr != NULL)
    {
        printf("Are you sure you want to edit contact?\nPress 0 to cancel or any other number to continue :");
        scanf("%d",&i);
        if (i == 0)
        {
            sc = FAILURE;
        }
        else
        {
            fflush(stdin);
            getchar();
            //fgets(nptr->email,SIZE,stdin);
            printf("Enter the email to be modified :");
            gets(nptr->email);
        }
    }
    else
    {
        printf("Contact does not exist.\n");
        sc = FAILURE;
    }
    return sc;
}

status_code Edit_prof_Contact(Professional_Contact *pptr, char name[SIZE], char mob[SIZE])
{
    status_code sc = SUCCESS;;
    Professional_Contact* nptr;
    nptr = Search_for_prof_contact(pptr, name, mob);
    int i = 0;
    if (nptr != NULL)
    {
        printf("Are you sure you want to edit contact?\nPress 0 to cancel or any other number to continue :");
        scanf("%d",&i);
        if (i == 0)
        {
            sc = FAILURE;
        }
        else
        {
            fflush(stdin);
            getchar();
            //fgets(nptr->email,SIZE,stdin);
            printf("Enter the email to be modified :");
            gets(nptr->email);
            printf("Enter the office address to be modified :");
            gets(nptr->Address);
            printf("Enter the office number to be modified :");
            gets(nptr->Office_Number); 
        }
    }
    else
    {
        printf("Contact does not exist.\n");
        sc = FAILURE;
    }
    return sc;
}
//Edit complete
//Remove duplicates
void Remove_duplicates_in_per(Personal_Contact* pptr)
{
    Personal_Contact* nptr = pptr;
    if (nptr != NULL)
    {
        Personal_Contact* curr = nptr->next, *prev = nptr;
        while (curr != NULL)
        {
            if (strcasecmp(prev->name, curr->name) == 0 && strcasecmp(prev->mob, curr->mob) == 0 &&strcasecmp(prev->email, curr->email) == 0)
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

void Remove_duplicates_in_prof(Professional_Contact* pptr)
{
    Professional_Contact* nptr = pptr;
    if (nptr != NULL)
    {
        Professional_Contact* curr = nptr->next, *prev = nptr;
        while (curr != NULL)
        {
            if (strcasecmp(prev->name, curr->name) == 0 && strcasecmp(prev->mob, curr->mob) == 0 &&strcasecmp(prev->email, curr->email) == 0 && strcasecmp(prev->Address, curr->Address) == 0 && strcasecmp(prev->Office_Number, curr->Office_Number) == 0)
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}
//Union
Personal_Contact* Merge_of_Per(Personal_Contact* pptr1, Personal_Contact* pptr2)
{
    Personal_Contact* pptf = NULL, *curr = NULL;
    Personal_Contact* nptr1 = pptr1;
    Personal_Contact* nptr2 = pptr2;
    if (nptr1 != NULL && nptr2 != NULL)
    {
        if (strcasecmp(nptr1->name,nptr2->name) > 0)
        {
            pptf = nptr2;
            curr = pptf;
            nptr2 = nptr2->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) < 0)
        {
            pptf = nptr1;
            curr = pptf;
            nptr1 = nptr1->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) == 0)
        {
            if (strcmp(nptr1->mob, nptr2->mob) > 0)
            {
                pptf = nptr2;
                curr = pptf;
                nptr2 = nptr2->next;
            }
            else
            {
                pptf = nptr1;
                curr = pptf;
                nptr1 = nptr1->next;
            }
        }
    }
    else if(nptr1 == NULL)
    {
        pptf = nptr2;
    }    
    else if (nptr2 == NULL)
    {
        pptf = nptr1;
    }
    
    while (nptr1 != NULL && nptr2 != NULL)
    {
        if (strcasecmp(nptr1->name,nptr2->name) > 0)
        {
            curr->next = nptr2;
            curr = nptr2;
            nptr2 = nptr2->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) < 0)
        {
            curr->next = nptr1;
            curr = nptr1;
            nptr1 = nptr1->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) == 0)
        {
            if (strcmp(nptr1->mob, nptr2->mob) > 0)
            {
                curr->next = nptr2;
                curr = nptr2;
                nptr2 = nptr2->next;
            }
            else
            {
                curr->next = nptr1;
                curr = nptr1;
                nptr1 = nptr1->next;
            }
        }
    }
    if (nptr1 == NULL)
    {
        curr->next = nptr2;
    }
    else
    {
        curr->next = nptr1;
    }
    return pptf;
}

Professional_Contact* Merge_of_Prof(Professional_Contact* pptr1, Professional_Contact* pptr2)
{
    Professional_Contact* pptf = NULL, *curr = NULL;
    Professional_Contact* nptr1 = pptr1;
    Professional_Contact* nptr2 = pptr2;
    if (nptr1 != NULL && nptr2 != NULL)
    {
        if (strcasecmp(nptr1->name,nptr2->name) > 0)
        {
            pptf = nptr2;
            curr = pptf;
            nptr2 = nptr2->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) < 0)
        {
            pptf = nptr1;
            curr = pptf;
            nptr1 = nptr1->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) == 0)
        {
            if (strcmp(nptr1->mob, nptr2->mob) > 0)
            {
                pptf = nptr2;
                curr = pptf;
                nptr2 = nptr2->next;
            }
            else
            {
                pptf = nptr1;
                curr = pptf;
                nptr1 = nptr1->next;
            }
        }
    }
    else if(nptr1 == NULL)
    {
        pptf = nptr2;
    }    
    else if (nptr2 == NULL)
    {
        pptf = nptr1;
    }
    
    while (nptr1 != NULL && nptr2 != NULL)
    {
        if (strcasecmp(nptr1->name,nptr2->name) > 0)
        {
            curr->next = nptr2;
            curr = nptr2;
            nptr2 = nptr2->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) < 0)
        {
            curr->next = nptr1;
            curr = nptr1;
            nptr1 = nptr1->next;
        }
        else if (strcasecmp(nptr1->name, nptr2->name) == 0)
        {
            if (strcmp(nptr1->mob, nptr2->mob) > 0)
            {
                curr->next = nptr2;
                curr = nptr2;
                nptr2 = nptr2->next;
            }
            else
            {
                curr->next = nptr1;
                curr = nptr1;
                nptr1 = nptr1->next;
            }
        }
    }
    if (nptr1 == NULL)
    {
        curr->next = nptr2;
    }
    else
    {
        curr->next = nptr1;
    }
    return pptf;
}

void Reverse_Personal_List(Personal_Contact** pptr)
{
    Personal_Contact* prev = NULL;
    Personal_Contact* curr = *pptr;
    if (curr != NULL)
    {
        Personal_Contact *nextp = curr->next;
        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = nextp;
            if (nextp != NULL)
                nextp = nextp->next;
        }
    }
    *pptr = prev;
}

void Reverse_Prof_List(Professional_Contact** pptr)
{
    Professional_Contact* prev = NULL;
    Professional_Contact* curr = *pptr;
    if (curr != NULL)
    {
        Professional_Contact *nextp = curr->next;
        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = nextp;
            if (nextp != NULL)
                nextp = nextp->next;
        }
    }
    *pptr = prev;
}

void Print_Personal_in_reverse(Personal_Contact* pptr)
{
    Personal_Contact* nptr = pptr;
    if (nptr == NULL)
    {
        return;
    }
    else
    {
        Print_Personal_in_reverse(nptr->next);
        Print_Personal_Data(nptr);
    }
}

void Print_Prof_in_reverse(Professional_Contact* pptr)
{
    Professional_Contact* nptr = pptr;
    if (nptr == NULL)
    {
        return;
    }
    else
    {
        Print_Prof_in_reverse(nptr->next);
        Print_Prof_Data(nptr);
    }
}

void Split_Per_in_two(Personal_Contact* nptr ,Personal_Contact** front, Personal_Contact** back)
{
    Personal_Contact* fast;
    Personal_Contact* slow;
    slow = nptr;
    fast = nptr->next;
    while (fast != NULL) 
    {
        fast = fast->next;
        if (fast != NULL) 
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = nptr;
    *back = slow->next;
    slow->next = NULL;
}

void Split_Prof_in_two(Professional_Contact* nptr ,Professional_Contact** front, Professional_Contact** back)
{
    Professional_Contact* fast;
    Professional_Contact* slow;
    slow = nptr;
    fast = nptr->next;
    while (fast != NULL) 
    {
        fast = fast->next;
        if (fast != NULL) 
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = nptr;
    *back = slow->next;
    slow->next = NULL;
}

void merge_sort_for_Personal(Personal_Contact** pptr)
{
    Personal_Contact *nptr = *pptr;
    Personal_Contact *front = NULL;
    Personal_Contact *back = NULL;

    if (nptr == NULL || nptr->next == NULL)
    {
        return;
    }
    Split_Per_in_two(nptr,&front,&back);
    merge_sort_for_Personal(&front);
    merge_sort_for_Personal(&back);

    *pptr = Merge_of_Per(front,back);
}

void merge_sort_for_Prof(Professional_Contact** pptr)
{
    Professional_Contact *nptr = *pptr;
    Professional_Contact *front = NULL;
    Professional_Contact *back = NULL;

    if (nptr == NULL || nptr->next == NULL)
    {
        return;
    }
    Split_Prof_in_two(nptr,&front,&back);
    merge_sort_for_Prof(&front);
    merge_sort_for_Prof(&back);

    *pptr = Merge_of_Prof(front,back);
}

Personal_Contact* Create_Unsorted_Personal(int num_nodes, int dur)
{
    Personal_Contact* pptr = NULL, *nptr = NULL, *prev = NULL;
    int i = 0;
    while (i < num_nodes)
    {
        if (i == 0)
        {
            pptr = Create_Per_Node();
            if (dur == 1)
            {
                printf("Enter the duration you spoke to this contact :");
                scanf("%d",&pptr->duration);
            }
            prev = pptr;
        }
        else
        {
            nptr = Create_Per_Node();
            if (dur == 1)
            {
                printf("Enter the duration you spoke to this contact :");
                scanf("%d",&nptr->duration);
            }
            prev->next = nptr;
            prev = nptr;
        }
        i++;
    }
    return pptr;
}

Professional_Contact* Create_Unsorted_Prof(int num_nodes, int dur)
{
    Professional_Contact* pptr = NULL, *nptr = NULL, *prev = NULL;
    int i = 0;
    while (i < num_nodes)
    {
        if (i == 0)
        {
            pptr = Create_Prof_Node();
            if (dur == 1)
            {
                printf("Enter the duration you spoke to this contact :");
                scanf("%d",&pptr->duration);
            }
            prev = pptr;
        }
        else
        {
            nptr = Create_Prof_Node();
            if (dur == 1)
            {
                printf("Enter the duration you spoke to this contact :");
                scanf("%d",&nptr->duration);
            }
            prev->next = nptr;
            prev = nptr;
        }
        i++;
    }
    return pptr;
}

void Get_Phonebook_Data(Phonebook *nptr)
{
    //getchar();
    printf("Enter the name to be stored :(Preferably full name)");
    scanf("%s",nptr->name);
    //printf("Enter the last name to be stored :");
    //gets(nptr->last_name);
    printf("Enter the mobile number to be stored :");
    scanf("%s",nptr->mob);
    printf("Enter the address to be stored :");
    getchar();
    gets(nptr->add);
}

Phonebook* Create_Phone_Node()
{
    Phonebook* nptr;
    nptr = (Phonebook*)malloc(sizeof(Phonebook));
    if(nptr != NULL)
    {
        Get_Phonebook_Data(nptr);
        nptr->left_per = NULL;
        nptr->right_prof = NULL;
        nptr->next = NULL;        
    }
    return nptr;
}

void Print_data_of_Phonebook(Phonebook *ph)
{
    printf("Details of phonebook owner :\n");
    puts(ph->name);
    puts(ph->mob);
    puts(ph->add);
    printf("Details of the personal contacts of owner : \n");
    Personal_Contact* nptr1 = ph->left_per;
    while (nptr1 != NULL)
    {
        Print_Personal_Data(nptr1);
        printf("%d\n",nptr1->duration);
        nptr1 = nptr1->next;
    }
    printf("Details of the proffessional contacts of owner : \n");
    Professional_Contact* nptr2 = ph->right_prof;
    while (nptr2 != NULL)
    {
        Print_Prof_Data(nptr2);
        printf("%d\n",nptr2->duration);
        nptr2 = nptr2->next;
    }
}

void print_phonebook(Phonebook *ph)
{
    Phonebook* p = ph;
    if (p == NULL)
    {
        return;
    }
    else
    {
        while (p != NULL)
        {
            Print_data_of_Phonebook(p);
            p = p->next;
        }
    }
}

Personal_Contact* Merge_of_Per_phbook(Personal_Contact* pptr1, Personal_Contact* pptr2)
{
    Personal_Contact* pptf = NULL, *curr = NULL;
    Personal_Contact* nptr1 = pptr1;
    Personal_Contact* nptr2 = pptr2;
    if (nptr1 != NULL && nptr2 != NULL)
    {
        if (nptr1->duration > nptr2->duration)
        {
            pptf = nptr1;
            curr = pptf;
            nptr1 = nptr1->next;
        }
        else 
        {
            pptf = nptr2;
            curr = pptf;
            nptr2 = nptr2->next;
        }
    }
    else if(nptr1 == NULL)
    {
        pptf = nptr2;
    }    
    else if (nptr2 == NULL)
    {
        pptf = nptr1;
    }
    
    while (nptr1 != NULL && nptr2 != NULL)
    {
        if (nptr2->duration < nptr1->duration)
        {
            curr->next = nptr1;
            curr = nptr1;
            nptr1 = nptr1->next;
        }
        else 
        {
            curr->next = nptr2;
            curr = nptr2;
            nptr2 = nptr2->next;
        }
    }
    if (nptr1 == NULL)
    {
        curr->next = nptr2;
    }
    else
    {
        curr->next = nptr1;
    }
    return pptf;
}

void merge_sort_for_Personal_phbook(Personal_Contact** pptr)
{
    Personal_Contact *nptr = *pptr;
    Personal_Contact *front = NULL;
    Personal_Contact *back = NULL;

    if (nptr == NULL || nptr->next == NULL)
    {
        return;
    }
    Split_Per_in_two(nptr,&front,&back);
    merge_sort_for_Personal(&front);
    merge_sort_for_Personal(&back);

    *pptr = Merge_of_Per_phbook(front,back);
}

Professional_Contact* Merge_of_Prof_phbook(Professional_Contact* pptr1, Professional_Contact* pptr2)
{
    Professional_Contact* pptf = NULL, *curr = NULL;
    Professional_Contact* nptr1 = pptr1;
    Professional_Contact* nptr2 = pptr2;
    if (nptr1 != NULL && nptr2 != NULL)
    {
        if (nptr1->duration > nptr2->duration)
        {
            pptf = nptr1;
            curr = pptf;
            nptr1 = nptr1->next;
        }
        else 
        {
            pptf = nptr2;
            curr = pptf;
            nptr2 = nptr2->next;
        }
    }
    else if(nptr1 == NULL)
    {
        pptf = nptr2;
    }    
    else if (nptr2 == NULL)
    {
        pptf = nptr1;
    }
    
    while (nptr1 != NULL && nptr2 != NULL)
    {
        if (nptr2->duration < nptr1->duration)
        {
            curr->next = nptr1;
            curr = nptr1;
            nptr1 = nptr1->next;
        }
        else 
        {
            curr->next = nptr2;
            curr = nptr2;
            nptr2 = nptr2->next;
        }
    }
    if (nptr1 == NULL)
    {
        curr->next = nptr2;
    }
    else
    {
        curr->next = nptr1;
    }
    return pptf;
}

void merge_sort_for_Prof_phbook(Professional_Contact** pptr)
{
    Professional_Contact *nptr = *pptr;
    Professional_Contact *front = NULL;
    Professional_Contact *back = NULL;

    if (nptr == NULL || nptr->next == NULL)
    {
        return;
    }
    Split_Prof_in_two(nptr,&front,&back);
    merge_sort_for_Prof(&front);
    merge_sort_for_Prof(&back);

    *pptr = Merge_of_Prof_phbook(front,back);
}

status_code Insert_At_start_in_Phonebook(Phonebook** phtr)
{
    Phonebook* nptr;
    int num_per_contacts;
    int num_prof_contacts;
    status_code sc = SUCCESS;
    nptr = Create_Phone_Node();
    if (nptr == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        nptr->next = *phtr;
        *phtr = nptr;
        printf("Enter the number of personal contacts in this phonebook :");
        scanf("%d",&num_per_contacts);
        nptr->left_per = Create_Unsorted_Personal(num_per_contacts,1);
        merge_sort_for_Personal_phbook(&nptr->left_per);
        //Reverse_Personal_List(&nptr->left_per);
        printf("Enter the number of professional contacts in this phonebook :");
        scanf("%d",&num_prof_contacts);
        nptr->right_prof = Create_Unsorted_Prof(num_prof_contacts,1);
        merge_sort_for_Prof_phbook(&nptr->right_prof);
        //Reverse_Prof_List(&nptr->right_prof);
    }
    return sc;
}

void Delete_Entire_Phonebook(Phonebook **ph)
{
    Phonebook *p = *ph;
    Phonebook *ptr;
    while (p!= NULL)
    {
        ptr = p;
        Delete_per_entire(&ptr->left_per);
        Delete_prof_entire(&ptr->right_prof);
        p = p->next;
        *ph = p;
        free(ptr);
    }
}

