#include <stdio.h>
#include <string.h>
#include "avl_ll.h"
int main()
{
    AVL_Tree_prof *node_prof = NULL, *root1_prof = NULL, *root2_prof = NULL;
    AVL_Tree_per *node_per = NULL, *root1_per = NULL, *root2_per = NULL;
    int op, ch, op2;
    unsigned long int mob, mob2;
    do
    {
        printf("\n-------Welcome--------\n ");
        printf("\n1.Create or Insert\n2.Edit\n3.Delete\n4.Search\n5.Sort\n6.Display\n7.Range Search\n8.Sort based on first name.");
        printf("\nEnter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nPress 1 to insert or create personal contact.\nPress 2 to insert or create professional contact\n");
            scanf("%d", &op2);
            switch (op2)
            {
            case 1:
                printf("Enter the mobile numbr of the contact to be inserted : ");
                scanf("%lu",&mob);
                root1_per = Insert_Node(root1_per, mob);
                printf("Contact Inserted.\n");
                break;
            case 2:
                printf("Enter the mobile numbr of the contact to be inserted : ");
                scanf("%lu",&mob);
                root1_prof = Insert_Node_prof(root1_prof, mob);
                printf("Contact Inserted.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
            }
            break;
        case 2:
            printf("\nPress 1 to edit all fields except mob no.\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                printf("\nPress 1 to edit in Personal Contact.\nPress 2 to edit in Proffessional Contact.\n");
                int op3;
                scanf("%d", &op3);
                if (op3 == 1)
                {
                    printf("Enter the mob no. of the contact you want to edit:\n");
                    scanf("%lu",&mob);
                    Edit_with_mob(root1_per, mob);
                }
                else if (op3 == 2)
                {
                    printf("Enter the mob no. of the contact you want to edit:\n");
                    scanf("%lu", &mob);
                    Edit_with_mob_prof(root1_prof, mob);
                }
            }
            else
            {
                printf("Invalid Option\n");
            }
            break;
        case 3:
            printf("Press 1 to delete particular personal contact.\nPress 2 to delete particular professional contact.\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                printf("Enter the mob no. of the contact you want to delete :");
                scanf("%lu",&mob);
                root1_per = Delete_Node(root1_per,mob);
            }
            else if (op2 == 2)
            {
                printf("Enter the mob no. of the contact you want to delete :");
                scanf("%lu",&mob);
                root1_prof = Delete_Node_prof(root1_prof, mob);
            }
            else
            {
                printf("Invalid option choosen.\n");
            }
            break;
        case 4:
            printf("Press 1 to search personal contact list.\nPress 2 to search professional contact \n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                printf("Enter the mob no of the contact you want to search: ");
                scanf("%lu",&mob);
                node_per = Search_node_with_mob(root1_per,mob);
                Print_Personal_Data(&node_per->per);

            }
            else if (op2 == 2)
            {
                printf("Enter the mob no of the contact you want to search: ");
                scanf("%lu", &mob);
                node_prof = Search_node_with_mob_prof(root1_prof, mob);
                Print_Prof_Data(&node_prof->prof);
            }
            else
            {
                printf("Invalid Option.\n");
            }
            break;
        case 5:
            printf("Press 1 to sort personal list.\nPress 2 to sort Proffessional list.\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                int op3;
                printf("Enter 1 to sort in ascending.\nEnter 2 to sort in descending.");
                scanf("%d", &op3);
                if (op3 == 1)
                {
                    InOrder(root1_per);
                }
                else if (op3 == 2)
                {
                    mirror_tree(root1_per);
                    InOrder(root1_per);
                    mirror_tree(root1_per); // The orginal tree was change so getting the og tree back
                }
            }
            else if (op2 == 2)
            {
                int op3;
                printf("Enter 1 to sort in ascending.\nEnter 2 to sort in descending.");
                scanf("%d", &op3);
                if (op3 == 1)
                {
                    InOrder_prof(root1_prof);
                }
                else if (op3 == 2)
                {
                    mirror_tree_prof(root1_prof);
                    InOrder_prof(root1_prof);
                    mirror_tree_prof(root1_prof);
                }
            }
            else
            {
                printf("Invalid Option.\n");
            }
            break;
        case 6:
            printf("Press 1 to display personal contact list.\nPress 2 to display professional contact list\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                int in;
                printf("Press 1 for inorder display.\nPress 2 for preorder display.\nPres 3 for postorder display.\n");
                scanf("%d",&in);
                if (in == 1)
                {
                    InOrder(root1_per);
                }
                else if(in == 2)
                {
                    preOrder(root1_per);
                }
                else if (in == 3)
                {
                    Post_Order(root1_per);
                }
                else
                {
                    printf("Invalid Option.");
                }
            }
            else if (op2 == 2)
            {
                int in;
                printf("Press 1 for inorder display.\nPress 2 for preorder display.\nPress 3 for postorder display.\n");
                scanf("%d",&in);
                if (in == 1)
                {
                    InOrder_prof(root1_prof);
                }
                else if(in == 2)
                {
                    preOrder_prof(root1_prof);
                }
                else if (in == 3)
                {
                    Post_Order_prof(root1_prof);
                }
                else
                {
                    printf("Invalid Option.");
                }
            }
            else
                printf("Invalid option\n");
            break;
        case 7:
            printf("Press 1 to range search in personal contacts.\nPress 2 to range search in professional contacts.\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                unsigned long int mob1, mob2;
                printf("Enter the From-Mobile-Number :");
                scanf("%lu",&mob1);
                printf("Enter the To-Mobile-Number:");
                scanf("%lu",&mob2);
                Range_search(root1_per,mob1,mob2);
            }
            else if (op2 == 2)
            {
                unsigned long int mob1, mob2;
                printf("Enter the From-Mobile-Number :");
                scanf("%lu",&mob1);
                printf("Enter the To-Mobile-Number:");
                scanf("%lu",&mob2);
                Range_search_prof(root1_prof,mob1,mob2);
            }
            else
                printf("Invalid option\n");
            break;
        case 8:
            printf("Enter 1 to sort personal contacts based on name.\nEnter 2 to sort professional contacts based on name.\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                root2_per = NULL;
                root2_per = Create_sorted_by_name_tree(root1_per,root2_per);
                InOrder(root2_per);
            }
            else if (op2 == 2)
            {
                root2_prof = NULL;
                root2_prof = Create_sorted_by_name_tree_prof(root1_prof,root2_prof);
                InOrder_prof(root2_prof);
            }
            else
            {
                printf("Invalid Option.\n");
            }
            break;
        default:
            printf("Invalid Option.\n");
            break;
        }
        printf("\nDo you want to quit ? 1 for no / 0 for yes:");
        scanf("%d", &op);
    } while (op != 0);
    if (node_per != NULL)
    {
        Delete_tree(&node_per);
    }
    if (root1_per != NULL)
    {
        Delete_tree(&root1_per);
    }
    if (root2_per != NULL)
    {
        Delete_tree(&root2_per);
    }
    if (node_prof != NULL)
    {
        Delete_Tree_prof(&node_prof);
    }
    if (root1_prof != NULL)
    {
        Delete_Tree_prof(&root1_prof);
    }
    if (root2_prof != NULL)
    {
        Delete_Tree_prof(&root2_prof);
    }
    printf("\n.....................THANK YOU........................\n");
    return 0;   
}