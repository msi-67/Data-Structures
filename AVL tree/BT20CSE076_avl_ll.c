#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl_ll.h"

void Get_Prof_Data(Professional_Contact *nptr, unsigned long int mob)
{
 //   getchar();
    nptr->mob = mob;
    printf("Enter the name to be stored :(Preferably full name)");
    scanf("%s",nptr->name);
    printf("Enter the email to be stored :");
    scanf("%s",nptr->email);
    printf("Enter the office address to be entered :");
    getchar();
    gets(nptr->Address);
    printf("Enter the office Number : ");
    scanf("%s",nptr->Office_Number);
}

void Get_Personal_Data(Personal_Contact *nptr, unsigned long int mob)
{
   // getchar();
    nptr->mob = mob;
    printf("Enter the name to be stored :(Preferably full name):");
    scanf("%s",nptr->name);
    //printf("Enter the last name to be stored :");
    //gets(nptr->last_name);
    printf("Enter the email to be stored :");
    scanf("%s",nptr->email);
}

void Print_Personal_Data(Personal_Contact *nptr)
{
    if (nptr != NULL)
    {
        printf("\n");
        puts(nptr->name);
        //puts(nptr->name);
        printf("%lu\n",nptr->mob);
        puts(nptr->email);
        printf("\n");
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
        printf("\n");
        puts(nptr->name);
        //puts(nptr->name);
        printf("%lu\n",nptr->mob);
        puts(nptr->email);
        puts(nptr->Office_Number);
        puts(nptr->Address);
        printf("\n");
    }
    else
    {
        printf("The node does not exist.");
    }
}

void assign_data(Personal_Contact* per, Personal_Contact* per2)
{
    strcpy(per2->email, per->email);
    per2->mob = per->mob;
    strcpy(per2->name, per->name);
}

void assign_prof_data(Professional_Contact* prof1, Professional_Contact* prof2)
{
    strcpy(prof2->email, prof1->email);
    prof2->mob = prof1->mob;
    strcpy(prof2->name, prof1->name);
    strcpy(prof2->Address, prof1->Address);
    strcpy(prof2->Office_Number,prof1->Office_Number);
}

AVL_Tree_per* create_node(unsigned long mob)
{
    AVL_Tree_per* tree;
    tree = (AVL_Tree_per*)malloc(sizeof(AVL_Tree_per));
    Get_Personal_Data(&tree->per, mob);
    tree->per.mob = mob;
    tree->left = NULL;
    tree->right = NULL;
    tree->bf = 0;
    return tree;
}

AVL_Tree_prof* create_node_prof(unsigned long int mob)
{
    AVL_Tree_prof* tree;
    tree = (AVL_Tree_prof*)malloc(sizeof(AVL_Tree_prof));
    Get_Prof_Data(&tree->prof, mob);
    tree->prof.mob = mob;
    tree->left = NULL;
    tree->right = NULL;
    tree->bf = 0;
    return tree;    
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

AVL_Tree_per *minValueNode(AVL_Tree_per* node)
{
    AVL_Tree_per* ptr = node;
 
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

AVL_Tree_prof *minValueNode_prof(AVL_Tree_prof *node)
{
    AVL_Tree_prof* ptr = node;
 
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;    
}

int height(AVL_Tree_per* node)
{
    int retval;
    if (node == NULL)
    {
        retval = 0;
    }
    else 
    {
        retval = 1+max(height(node->left), height(node->right));
    }
    //printf("Height for %lu value is %d.\n",node->per.mob, retval);
    return retval;
}

int height_prof(AVL_Tree_prof* node)
{
    int retval;
    if (node == NULL)
    {
        retval = 0;
    }
    else 
    {
        retval = 1+max(height_prof(node->left), height_prof(node->right));
    }
    //printf("Height for %lu value is %d.\n",node->per.mob, retval);
    return retval;
}

int getBalance(AVL_Tree_per* node)
{
    int retval;
    if (node == NULL)
    {
        retval = 0;
    }
    else
    {
        retval = height(node->left) - height(node->right);
    }
    return retval;
}

int getBalance_prof(AVL_Tree_prof* node)
{
    int retval;
    if (node == NULL)
    {
        retval = 0;
    }
    else
    {
        retval = height_prof(node->left) - height_prof(node->right);
    }
    return retval;
}

status_code Rotate_Left(AVL_Tree_per** tree)
{
    AVL_Tree_per* avl = *tree;
    AVL_Tree_per* avl2;
    status_code sc = SUCCESS;
    if (avl == NULL)
    {
        sc = FAILURE;
    }
    else if(avl->right == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        avl2 = avl->right;
        avl->right = avl2->left;
        avl2->left = avl;
    }
    avl2->bf = getBalance(avl2);
    //avl2->bf = -1*avl2->left->bf;
    *tree = avl2;
    return sc;
}

status_code Rotate_Left_prof(AVL_Tree_prof** tree)
{
    AVL_Tree_prof* avl = *tree;
    AVL_Tree_prof* avl2;
    status_code sc = SUCCESS;
    if (avl == NULL)
    {
        sc = FAILURE;
    }
    else if(avl->right == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        avl2 = avl->right;
        avl->right = avl2->left;
        avl2->left = avl;
    }
    avl2->bf = getBalance_prof(avl2);
    //avl2->bf = -1*avl2->left->bf;
    *tree = avl2;
    return sc;
}

status_code Rotate_right(AVL_Tree_per** tree)
{
    AVL_Tree_per* avl = *tree;
    AVL_Tree_per* avl2;
    status_code sc;
    if (avl == NULL)
    {
        sc = FAILURE;
    }
    else if (avl->left == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        avl2 = avl->left;
        avl->left = avl2->right;
        avl2->right = avl;
    }
    avl2->bf = getBalance(avl2);
    *tree = avl2;
    return sc;
    //avl2->bf = -1*avl2->right->bf;    
}

status_code Rotate_right_prof(AVL_Tree_prof** tree)
{
    AVL_Tree_prof* avl = *tree;
    AVL_Tree_prof* avl2;
    status_code sc;
    if (avl == NULL)
    {
        sc = FAILURE;
    }
    else if (avl->left == NULL)
    {
        sc = FAILURE;
    }
    else
    {
        avl2 = avl->left;
        avl->left = avl2->right;
        avl2->right = avl;
    }
    avl2->bf = getBalance_prof(avl2);
    *tree = avl2;
    return sc;
    //avl2->bf = -1*avl2->right->bf;    
}

AVL_Tree_per* Insert_Node(AVL_Tree_per* node, unsigned long int mob)
{
    status_code sc;
    if (node == NULL)
    {
        return create_node(mob);
    }
    else if (mob < node->per.mob)
    {
        node->left = Insert_Node(node->left, mob);
    }
    else if(mob > node->per.mob)
    {
        node->right = Insert_Node(node->right, mob);
    }
    else
    {
        printf("Same mobile numbers are not allowed.\n");
        return node;
    }
    node->bf = getBalance(node);
//    printf(" node with value %lu has balance %d\n",node->per.mob, node->bf);
    if (node->bf == RRH && mob < node->left->per.mob)
    {
        Rotate_right(&node);
    }
    else if (node->bf == RRH && mob > node->left->per.mob)
    {
        Rotate_Left(&node->left);
        Rotate_right(&node);
    }
    else if (node->bf == LLH && mob < node->right->per.mob)
    {
        Rotate_right(&node->right);
        Rotate_Left(&node);
    }
    else if (node->bf == LLH && mob > node->right->per.mob)
    {
        Rotate_Left(&node);
    }
    return node;
}

AVL_Tree_prof* Insert_Node_prof(AVL_Tree_prof* node, unsigned long int mob)
{
    status_code sc;
    if (node == NULL)
    {
        return create_node_prof(mob);
    }
    else if (mob < node->prof.mob)
    {
        node->left = Insert_Node_prof(node->left, mob);
    }
    else if(mob > node->prof.mob)
    {
        node->right = Insert_Node_prof(node->right, mob);
    }
    else
    {
        printf("Same mobile numbers are not allowed.\n");
        return node;
    }
    node->bf = getBalance_prof(node);
//    printf(" node with value %lu has balance %d\n",node->per.mob, node->bf);
    if (node->bf == RRH && mob < node->left->prof.mob)
    {
        Rotate_right_prof(&node);
    }
    else if (node->bf == RRH && mob > node->left->prof.mob)
    {
        Rotate_Left_prof(&node->left);
        Rotate_right_prof(&node);
    }
    else if (node->bf == LLH && mob < node->right->prof.mob)
    {
        Rotate_right_prof(&node->right);
        Rotate_Left_prof(&node);
    }
    else if (node->bf == LLH && mob > node->right->prof.mob)
    {
        Rotate_Left_prof(&node);
    }
    return node;
}

AVL_Tree_per* Delete_Node(AVL_Tree_per* root, unsigned long int mob)
{
    if (root == NULL)
    {
        printf("Cannot find the data.\n");
        return root;
    }
    else if (mob < root->per.mob)
    {
        root->left = Delete_Node(root->left, mob);
    }
    else if (mob > root->per.mob)
    {
        root->right = Delete_Node(root->right, mob);
    }
    else
    {
        if (root->left == NULL|| root->right == NULL)
        {
            AVL_Tree_per* temp;
            /*if (root->left)
            {
                temp = root->left;
            }
            else
            {
                temp = root->right;
            }*/
            temp = root->left?root->left:root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            AVL_Tree_per* temp = minValueNode(root->right);
            assign_data(&temp->per, &root->per);
            root->right = Delete_Node(root->right, temp->per.mob);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->bf = getBalance(root);
    
    if (root->bf == RRH && getBalance(root->left) >= 0)
    {
        Rotate_right(&root);
    }
    else if (root->bf == RRH && mob > getBalance(root->left) < 0)
    {
        Rotate_Left(&root->left);
        Rotate_right(&root);
    }
    else if (root->bf == LLH && getBalance(root->right) > 0)
    {
        Rotate_right(&root->right);
        Rotate_Left(&root);
    }
    else if (root->bf == LLH && getBalance(root->left) <= 0)
    {
        Rotate_Left(&root);
    }
    return root;
}

AVL_Tree_prof* Delete_Node_prof(AVL_Tree_prof* root, unsigned long int mob)
{
    if (root == NULL)
    {
        printf("Cannot find the data.\n");
        return root;
    }
    else if (mob < root->prof.mob)
    {
        root->left = Delete_Node_prof(root->left, mob);
    }
    else if (mob > root->prof.mob)
    {
        root->right = Delete_Node_prof(root->right, mob);
    }
    else
    {
        if (root->left == NULL|| root->right == NULL)
        {
            AVL_Tree_prof* temp;
            /*if (root->left)
            {
                temp = root->left;
            }
            else
            {
                temp = root->right;
            }*/
            temp = root->left?root->left:root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            AVL_Tree_prof* temp = minValueNode_prof(root->right);
            assign_prof_data(&temp->prof, &root->prof);
            root->right = Delete_Node_prof(root->right, temp->prof.mob);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->bf = getBalance_prof(root);
    
    if (root->bf == RRH && getBalance_prof(root->left) >= 0)
    {
        Rotate_right_prof(&root);
    }
    else if (root->bf == RRH && mob > getBalance_prof(root->left) < 0)
    {
        Rotate_Left_prof(&root->left);
        Rotate_right_prof(&root);
    }
    else if (root->bf == LLH && getBalance_prof(root->right) > 0)
    {
        Rotate_right_prof(&root->right);
        Rotate_Left_prof(&root);
    }
    else if (root->bf == LLH && getBalance_prof(root->left) <= 0)
    {
        Rotate_Left_prof(&root);
    }
    return root;
}

AVL_Tree_per* Search_node_with_mob(AVL_Tree_per* root, unsigned long int mob)
{
    AVL_Tree_per* retval;
    if (root == NULL)
    {
        printf("The contact could not be found.\n");
        retval = root;
    }
    else if (root->per.mob == mob)
    {
        retval = root;
    }
    else if (root->per.mob > mob)
    {
        retval = Search_node_with_mob(root->left, mob);
    }
    else if (root->per.mob < mob)
    {
        retval = Search_node_with_mob(root->right, mob);
    }
    return retval;
}

AVL_Tree_prof* Search_node_with_mob_prof(AVL_Tree_prof* root, unsigned long int mob)
{
    AVL_Tree_prof* retval;
    if (root == NULL)
    {
        printf("The contact could not be found.\n");
        retval = root;
    }
    else if (root->prof.mob == mob)
    {
        retval = root;
    }
    else if (root->prof.mob > mob)
    {
        retval = Search_node_with_mob_prof(root->left, mob);
    }
    else if (root->prof.mob < mob)
    {
        retval = Search_node_with_mob_prof(root->right, mob);
    }
    return retval;
}

void Edit_with_mob(AVL_Tree_per* root, unsigned long int mob)
{
    AVL_Tree_per* edit = Search_node_with_mob(root, mob);
    if (edit != NULL)
    {
        Get_Personal_Data(&edit->per, mob);
    }
    Print_Personal_Data(&edit->per);
}

void Edit_with_mob_prof(AVL_Tree_prof* root, unsigned long int mob)
{
    AVL_Tree_prof* edit = Search_node_with_mob_prof(root, mob);
    if (edit != NULL)
    {
        Get_Prof_Data(&edit->prof, mob);
    }
    Print_Prof_Data(&edit->prof);
}

void mirror_tree(AVL_Tree_per* node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        AVL_Tree_per* temp;
        mirror_tree(node->left);
        mirror_tree(node->right);
        temp = node->left;
        node->left  = node->right;
        node->right = temp;
    }
}

void mirror_tree_prof(AVL_Tree_prof* node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        AVL_Tree_prof* temp;
        mirror_tree_prof(node->left);
        mirror_tree_prof(node->right);
        temp = node->left;
        node->left  = node->right;
        node->right = temp;
    }
}

void preOrder(AVL_Tree_per *root)
{
    if(root != NULL)
    {
        Print_Personal_Data(&root->per);        
        preOrder(root->left);
        preOrder(root->right);
    }
}

void preOrder_prof(AVL_Tree_prof *root)
{
    if(root != NULL)
    {
        Print_Prof_Data(&root->prof);        
        preOrder_prof(root->left);
        preOrder_prof(root->right);
    }
}

void InOrder(AVL_Tree_per *root)
{
    if ( root != NULL)
    {
        InOrder(root->left);
        Print_Personal_Data(&root->per);
        InOrder(root->right);
    }
}

void InOrder_prof(AVL_Tree_prof *root)
{
    if ( root != NULL)
    {
        InOrder_prof(root->left);
        Print_Prof_Data(&root->prof);
        InOrder_prof(root->right);
    }
}

void Post_Order(AVL_Tree_per* root)
{
    if (root != NULL)
    {
        Post_Order(root->left);
        Post_Order(root->right);
        Print_Personal_Data(&root->per);
    }
}

void Post_Order_prof(AVL_Tree_prof* root)
{
    if (root != NULL)
    {
        Post_Order_prof(root->left);
        Post_Order_prof(root->right);
        Print_Prof_Data(&root->prof);
    }
}

void reverse_sorted_display(AVL_Tree_per* root)
{
    if (root != NULL)
    {
        reverse_sorted_display(root->right);
        Print_Personal_Data(&root->per);
        reverse_sorted_display(root->left);
    }
}

void reverse_sorted_display_prof(AVL_Tree_prof* root)
{
    if (root != NULL)
    {
        reverse_sorted_display_prof(root->right);
        Print_Prof_Data(&root->prof);
        reverse_sorted_display_prof(root->left);
    }
}

void Range_search(AVL_Tree_per* root, unsigned long int mob1, unsigned long int mob2)
{
    if (root == NULL)
    {
        return;
    }
    else if(root->per.mob > mob1)
    {
        Range_search(root->left, mob1, mob2);
    }
    if(root->per.mob >= mob1 && root->per.mob <= mob2)
    {
        Print_Personal_Data(&root->per);
    }
    Range_search(root->right, mob1, mob2);
}

void Range_search_prof(AVL_Tree_prof* root, unsigned long int mob1, unsigned long int mob2)
{
    if (root == NULL)
    {
        return;
    }
    else if(root->prof.mob > mob1)
    {
        Range_search_prof(root->left, mob1, mob2);
    }
    if(root->prof.mob >= mob1 && root->prof.mob <= mob2)
    {
        Print_Prof_Data(&root->prof);
    }
    Range_search_prof(root->right, mob1, mob2);
}

AVL_Tree_per* create_node_with_data(Personal_Contact* per)
{
    AVL_Tree_per* tree;
    tree = (AVL_Tree_per*)malloc(sizeof(AVL_Tree_per));
    //Get_Personal_Data(&tree->per, mob);
    strcpy(tree->per.name, per->name);
    strcpy(tree->per.email, per->email);
    tree->per.mob = per->mob;
    tree->left = NULL;
    tree->right = NULL;
    tree->bf = 0;
    return tree;
}

AVL_Tree_prof* create_node_with_data_prof(Professional_Contact* Prof)
{
    AVL_Tree_prof* tree;
    tree = (AVL_Tree_prof*)malloc(sizeof(AVL_Tree_prof));
    //Get_Personal_Data(&tree->per, mob);
    strcpy(tree->prof.name, Prof->name);
    strcpy(tree->prof.email, Prof->email);
    strcpy(tree->prof.Address, Prof->Address);
    strcpy(tree->prof.Office_Number, Prof->Office_Number);
    tree->prof.mob = Prof->mob;
    tree->left = NULL;
    tree->right = NULL;
    tree->bf = 0;
    return tree;
}

AVL_Tree_per* Insert_Node_by_name(AVL_Tree_per* node, Personal_Contact* per)
{
    status_code sc;
    if (node == NULL)
    {
        return create_node_with_data(per);
    }
    else if (strcasecmp(per->name, node->per.name) < 0)
    {
        node->left = Insert_Node_by_name(node->left, per);
    }
    else if(strcasecmp(per->name, node->per.name) > 0)
    {
        node->right = Insert_Node_by_name(node->right, per);
    }
    else if (strcasecmp(per->name, node->per.name) == 0 && per->mob > node->per.mob)
    {
        node->right = Insert_Node_by_name(node->right, per);
    }
    else if (strcasecmp(per->name, node->per.name) == 0 && per->mob < node->per.mob)
    {
        node->left = Insert_Node_by_name(node->left, per);
    }
    
    else
    {
        printf("Same mobile numbers are not allowed.\n");
        return node;
    }
    node->bf = getBalance(node);
//    printf(" node with value %lu has balance %d\n",node->per.mob, node->bf);
    if (node->bf == RRH && strcasecmp(per->name, node->left->per.name) < 0)
    {
        Rotate_right(&node);
    }
    else if (node->bf == RRH && strcasecmp(per->name, node->left->per.name) > 0)
    {
        Rotate_Left(&node->left);
        Rotate_right(&node);
    }
    else if (node->bf == LLH && strcasecmp(per->name, node->right->per.name) < 0)
    {
        Rotate_right(&node->right);
        Rotate_Left(&node);
    }
    else if (node->bf == LLH && strcasecmp(per->name, node->right->per.name) > 0)
    {
        Rotate_Left(&node);
    }
    else if (node->bf == LLH && strcasecmp(per->name, node->right->per.name) == 0 && per->mob < node->right->per.mob)
    {
        Rotate_right(&node->right);
        Rotate_Left(&node);
    }
    else if (node->bf == LLH && strcasecmp(per->name, node->right->per.name) == 0 && per->mob > node->right->per.mob)
    {
        Rotate_Left(&node);
    }
    else if (node->bf == RRH && strcasecmp(per->name, node->right->per.name) == 0 && per->mob < node->left->per.mob)
    {
        Rotate_right(&node);
    }
    else if (node->bf == RRH && strcasecmp(per->name, node->right->per.name) == 0 && per->mob > node->left->per.mob)
    {
        Rotate_Left(&node->left);
        Rotate_right(&node);
    }
    return node;
}

AVL_Tree_prof* Insert_Node_by_name_prof(AVL_Tree_prof* node, Professional_Contact* prof)
{
    status_code sc;
    if (node == NULL)
    {
        return create_node_with_data_prof(prof);
    }
    else if (strcasecmp(prof->name, node->prof.name) < 0)
    {
        node->left = Insert_Node_by_name_prof(node->left, prof);
    }
    else if(strcasecmp(prof->name, node->prof.name) > 0)
    {
        node->right = Insert_Node_by_name_prof(node->right, prof);
    }
    else if (strcasecmp(prof->name, node->prof.name) == 0 && prof->mob > node->prof.mob)
    {
        node->right = Insert_Node_by_name_prof(node->right, prof);
    }
    else if (strcasecmp(prof->name, node->prof.name) == 0 && prof->mob < node->prof.mob)
    {
        node->left = Insert_Node_by_name_prof(node->left, prof);
    }
    
    else
    {
        printf("Same mobile numbers are not allowed.\n");
        return node;
    }
    node->bf = getBalance_prof(node);
//    printf(" node with value %lu has balance %d\n",node->per.mob, node->bf);
    if (node->bf == RRH && strcasecmp(prof->name, node->left->prof.name) < 0)
    {
        Rotate_right_prof(&node);
    }
    else if (node->bf == RRH && strcasecmp(prof->name, node->left->prof.name) > 0)
    {
        Rotate_Left_prof(&node->left);
        Rotate_right_prof(&node);
    }
    else if (node->bf == LLH && strcasecmp(prof->name, node->right->prof.name) < 0)
    {
        Rotate_right_prof(&node->right);
        Rotate_Left_prof(&node);
    }
    else if (node->bf == LLH && strcasecmp(prof->name, node->right->prof.name) > 0)
    {
        Rotate_Left_prof(&node);
    }
    else if (node->bf == LLH && strcasecmp(prof->name, node->right->prof.name) == 0 && prof->mob < node->right->prof.mob)
    {
        Rotate_right_prof(&node->right);
        Rotate_Left_prof(&node);
    }
    else if (node->bf == LLH && strcasecmp(prof->name, node->right->prof.name) == 0 && prof->mob > node->right->prof.mob)
    {
        Rotate_Left_prof(&node);
    }
    else if (node->bf == RRH && strcasecmp(prof->name, node->right->prof.name) == 0 && prof->mob < node->left->prof.mob)
    {
        Rotate_right_prof(&node);
    }
    else if (node->bf == RRH && strcasecmp(prof->name, node->right->prof.name) == 0 && prof->mob > node->left->prof.mob)
    {
        Rotate_Left_prof(&node->left);
        Rotate_right_prof(&node);
    }
    return node;
}

AVL_Tree_per* Create_sorted_by_name_tree(AVL_Tree_per* root, AVL_Tree_per* root2)
{
    if (root!=NULL)
    {
        root2 = Insert_Node_by_name(root2,&root->per);
        root2 = Create_sorted_by_name_tree(root->left,root2);
        root2 = Create_sorted_by_name_tree(root->right,root2);
    }
    else
    {
        return root2;
    }
    return root2;
}

AVL_Tree_prof* Create_sorted_by_name_tree_prof(AVL_Tree_prof* root, AVL_Tree_prof* root2)
{
    if (root!=NULL)
    {
        root2 = Insert_Node_by_name_prof(root2,&root->prof);
        root2 = Create_sorted_by_name_tree_prof(root->left,root2);
        root2 = Create_sorted_by_name_tree_prof(root->right,root2);
    }
    else
    {
        return root2;
    }
    return root2;
}

void Delete_tree(AVL_Tree_per** root)
{
    if ((*root) == NULL)
    {
        return;
    }
    Delete_tree(&(*root)->left);
    Delete_tree(&(*root)->right);
    free(*root);
}

void Delete_Tree_prof(AVL_Tree_prof** root)
{
    if ((*root) == NULL)
    {
        return;
    }
    Delete_Tree_prof(&(*root)->left);
    Delete_Tree_prof(&(*root)->right);
    free(*root);
}