#include <stdio.h>
#include "dspd_ll.h"
#include <string.h>
int main()
{
  Professional_Contact *pr1 = NULL, *pr2 = NULL, *pr3 = NULL,*pr4 = NULL, *res = NULL;
  Personal_Contact *pptr = NULL;
  Professional_Contact *prptr = NULL;
  Personal_Contact *nptr;
  Personal_Contact *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *final = NULL;
  Phonebook *ph = NULL;
  int op, ch, op2;
  char name[SIZE], mob[SIZE];
  status_code sc = SUCCESS;
  do
  {
    printf("-------Welcome--------\n ");
    printf("1.Create or Insert\n2.Edit\n3.Delete\n4.Search\n5.Sort\n6.Display\n7.Remove duplicates\n8.Union\n9.Phonebook");
    printf("\nEnter your choice:\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\nPress 1 to insert or create personal contact or 2 to insert or create professional contact\n");
      scanf("%d", &op2);
      switch (op2)
      {
      case 1:
        sc = Insert_a_per_con(&p1);
        if (sc == SUCCESS)
        {
          printf("Personal Contact inserted.\n");
        }
        break;
      case 2:
        sc = Insert_a_prof_con(&pr1);
        if (sc == SUCCESS)
        {
          printf("Proffessional Contact inserted.\n");
        }
        break;
      default:
        printf("Invalid option.\n");
        break;
      }
      break;
    case 2:
      printf("\nPress 1 to edit all fields except name and mob no.\n Press 2 to edit each content of the contact.\n");
      scanf("%d",&op2);
      if (op2 == 1)
      {
        printf("\nPress 1 to edit in Personal Contact.\nPress 2 to edit in Proffessional Contact.\n");
        int op3;
        scanf("%d",&op3);
        if (op3 == 1)
        {
          printf("Enter the name and mob no. of the contact you want to edit:\n");
          scanf("%s",name);
          scanf("%s",mob);
          sc = Edit_per_Contact(p1,name,mob);
          if (sc == SUCCESS)
          {
            printf("Contact Edited.\n");
          }
        }
        else if(op3 == 2)
        {
          printf("Enter the name and mob no. of the contact you want to edit:\n");
          scanf("%s",name);
          scanf("%s",mob);
          sc = Edit_prof_Contact(pr1,name,mob);
          if (sc == SUCCESS)
          {
            printf("Contact Edited.\n");
          }
        }
      }
      else if (op2 == 2)
      {
        printf("Press 1 to edit in Personal Contact.\nPress 2 to edit in Proffessional Contact.\n");
        int op3;
        scanf("%d",&op3);
        if (op3 == 1)
        {
          printf("Enter the name and mob no. of the contact you want to edit:\n");
          scanf("%s",name);
          scanf("%s",mob);
          sc = Edit_per_Contact_completely(&p1,name,mob);
          if (sc == SUCCESS)
          {
            printf("Contact Edited.\n");
          }
        }
        else if(op3 == 2)
        {
          printf("Enter the name and mob no. of the contact you want to edit:\n");
          scanf("%s",name);
          scanf("%s",mob);
          sc = Edit_prof_Contact_completely(&pr1,name,mob);
          if (sc == SUCCESS)
          {
            printf("Contact Edited.\n");
          }
        }  
      }
      else
      {
        printf("Invalid Option\n");
      }
      break;
    case 3:
      printf("Press 1 to delete particular personal contact.\nPress 2 to delete particular professional contact.\nPress 3 to delete entire personal contact list.\nPress 4 to delete entire proffessional Contact list.\n");
      scanf("%d", &op2);
      if (op2 == 1)
      {
        printf("Enter the name and mob no. of the contact you want to delete :");
        scanf("%s",name);
        scanf("%s",mob);
        sc = Delete_per_Contact(&p1,name,mob);
        if (sc == SUCCESS)
        {
          printf("Personal Contact deleted.\n");
        }
      }
      else if (op2 == 2)
      {
        printf("Enter the name and mob no. of the contact you want to delete :");
        scanf("%s",name);
        scanf("%s",mob);
        sc = Delete_prof_Contact(&pr1,name,mob);
        if (sc == SUCCESS)
        {
          printf("Personal Contact deleted.\n");
        }
      }
      else if (op2 == 3)
      {
        printf("Deleting entire personal contact list.\n");
        Delete_per_entire(&p1);
      }
      else if (op2 == 4)
      {
        printf("Deleting entire proffessional contact list.\n");
        Delete_prof_entire(&pr1);  
      }
      else
      {
        printf("Invalid option choosen.\n");
      }      
      break;
    case 4:
      printf("Press 1 to search personal contact or 2 to search professional contact \n");
      scanf("%d", &op2);
      if (op2 == 1)
      {
        printf("Enter the name and mob no of the contact you want to search.\n");
        scanf("%s",name);
        scanf("%s",mob);
        p2 = Search_for_contact(p1, name, mob);
        Print_Personal_Data(p2);
      }
      else if (op2 == 2)
      {
        printf("Enter the name and mob no of the contact you want to search.\n");
        scanf("%s",name);
        scanf("%s",mob);
        pr2 = Search_for_prof_contact(pr1, name, mob);
        Print_Prof_Data(pr2);  
      }
      else
      {
        printf("Invalid Option.\n");
      }
      break;
    case 5:
      printf("Press 1 to sort same personal contact list or 2 to sort same professional contact list\nPress 3 to create a new unsorted list and sort it.");
      scanf("%d",&op2);
      if (op2 == 1)
      {
        int op3;
        printf("Enter 1 to sort in ascending.\nEnter 2 to sort in descending.");
        scanf("%d",&op3);
        if (op3 == 1)
        {
          Print_All_Personal_Contact(p1);
        }
        else if (op3 == 2)
        {
          Print_Personal_in_reverse(p1);
        }
      }
      else if (op2 == 2)
      {
        int op3;
        printf("Enter 1 to sort in ascending.\nEnter 2 to sort in descending.");
        scanf("%d",&op3);
        if (op3 == 1)
        {
          Print_All_Prof_Contact(pr1);
        }
        else if (op3 == 2)
        {
          Print_Prof_in_reverse(pr1);
        }  
      }
      else if (op2 == 3)
      {
        int op3;
        printf("Press 1 to create new unsorted personal list.\nPress 2 to create new unsorted professiomal list.\n");
        scanf("%d",&op3);
        if (op3 == 1)
        {
          int num_node;
          printf("Enter the number of contacts you want to create :\n");
          scanf("%d",&num_node);
          p2 = Create_Unsorted_Personal(num_node, 0);
          int sort;
          printf("Enter 1 to sort in ascending.\nEnter 2 to sort in descending.");
          scanf("%d",&sort);
          if (sort == 1)
          {
            merge_sort_for_Personal(&p2);
            Print_All_Personal_Contact(p2);
          }
          else if (sort == 2)
          {
            merge_sort_for_Personal(&p2);
            Reverse_Personal_List(&p2);
            Print_All_Personal_Contact(p2);
          }
          else
          {
            printf("Invalid option.\n");
          }
        }
        else if (op3 == 2)
        {
          int num_node;
          printf("Enter the number of contacts you want to create :\n");
          scanf("%d",&num_node);
          pr2 = Create_Unsorted_Prof(num_node, 0);
          int sort;
          printf("Enter 1 to sort in ascending.\nEnter 2 to sort in descending.");
          scanf("%d",&sort);
          if (sort == 1)
          {
            merge_sort_for_Prof(&pr2);
            Print_All_Prof_Contact(pr2);
          }
          else if (sort == 2)
          {
            merge_sort_for_Prof(&pr2);
            Reverse_Prof_List(&pr2);
            Print_All_Prof_Contact(pr2);
          }
          else
          {
            printf("Invalid Option.\n");
          }  
        }
      }
      break;        
    case 6:
      printf("Press 1 to display personal contact list or 2 to display professional contact list\n");
      scanf("%d", &op2);
      if (op2 == 1)
      {
        Print_All_Personal_Contact(p1);
      }
      else if (op2 == 2)
      {
        Print_All_Prof_Contact(pr1);
      }
      else
        printf("Invalid option\n");
      break;
    case 7:
      printf("Press 1 to remove duplicates from personal contact list or 2 to remove duplicates from professional contact list\n");
      scanf("%d", &op2);
      if (op2 == 1)
      {
        Remove_duplicates_in_per(p1);
        printf("Duplicates have been removed\n");
      }
      else if(op2 == 2)
      {
        Remove_duplicates_in_prof(pr1);
        printf("Duplicates have been removed\n");
      }
      else
        printf("Invalid option\n");
      break;
    case 8:
      printf("Enter 1 to merge two personal list.\nEnter 2 to merge two professional list.");
      scanf("%d",&op2);
      if (op2 == 1)
      {
        printf("Now we have to create 2 sorted personal list.\n");
        printf("Enter the number of contacts in first list.\n");
        int num_nodes;
        scanf("%d",&num_nodes);
        for (int i = 0; i < num_nodes; i++)
        {
          Insert_a_per_con(&p3);
        }
        printf("Enter the number of contacts in second list.\n");
        scanf("%d",&num_nodes);
        for (int i = 0; i < num_nodes; i++)
        {
          Insert_a_per_con(&p4);
        }
        printf("Merging these 2 list.\n");
        final = Merge_of_Per(p3, p4);
        Print_All_Personal_Contact(final);
      }
      else if (op2 == 2)
      {
        printf("Now we have to create 2 unsorted professional list.\n");
        printf("Enter the number of contacts in first list.\n");
        int num_nodes;
        scanf("%d",&num_nodes);
        for (int i = 0; i < num_nodes; i++)
        {
          Insert_a_prof_con(&pr3);
        }
        printf("Enter the number of contacts in second list.\n");
        scanf("%d",&num_nodes);
        for (int i = 0; i < num_nodes; i++)
        {
          Insert_a_prof_con(&pr4);
        }
        printf("Merging these 2 list.\n");
        res = Merge_of_Prof(pr3, pr4);
        Print_All_Prof_Contact(res);  
      }
      else
      {
        printf("Invalid Option.\n");
      }
      break;
    case 9:
      printf("Enter the number of people who owns phonebook :");
      int num;
      scanf("%d",&num);
      for (int i = 0; i < num; i++)
      {
        sc = Insert_At_start_in_Phonebook(&ph);
      }
      print_phonebook(ph);
      break;
    default:
      printf("Invalid Option.\n");
      break;
    }
    printf("Do you want to quit ? 1 for no / 0 for yes:");
    scanf("%d", &op);
  } while (op != 0);
  // union_pers();
  if (p1 != NULL)
    Delete_per_entire(&p1);
  if (p2 != NULL)
    Delete_per_entire(&p2);
  if (p3 != NULL)
    Delete_per_entire(&p3);
  if (p4 != NULL)
    Delete_per_entire(&p4);
  if (final != NULL)
    Delete_per_entire(&final);
  if (pr1 != NULL)
    Delete_prof_entire(&pr1);
  if (pr2 != NULL)
    Delete_prof_entire(&pr2);
  if (pr3 != NULL)
    Delete_prof_entire(&pr3);
  if (pr4 != NULL)
    Delete_prof_entire(&pr4);
  if (ph != NULL)
    Delete_Entire_Phonebook(&ph);

  printf("...................THANK YOU....................");
  return 0;
  }