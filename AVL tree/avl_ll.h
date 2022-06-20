typedef enum {LH = -1, EQ = 0, RH = 1, LLH = -2, RRH = 2} Balance_faactor;
typedef enum {Personal, Proffesional} type;
typedef enum {FAILURE, SUCCESS} status_code;
typedef enum {TRUE, FALSE} boolean;
#define MAX 4
#define MIN 2
#define SIZE 100
typedef struct Node_tag_per
{
    char name[SIZE];
//    char last_name[SIZE];
    unsigned long int mob;
    char email[SIZE];
}Personal_Contact;


typedef struct Node_tag_prof
{
    char name[SIZE];
    //char last_name[SIZE];
    unsigned long int mob;
    char email[SIZE];
    char Office_Number[SIZE];
    char Address[SIZE];
}Professional_Contact;

typedef struct Node_tag
{
    Personal_Contact per;
    Balance_faactor bf;
    struct Node_tag *right;
    struct Node_tag *left;
}AVL_Tree_per;

typedef struct Node_tag_proff
{
    Professional_Contact prof;
    Balance_faactor bf;
    struct Node_tag_proff *right;
    struct Node_tag_proff *left;
}AVL_Tree_prof;

void Get_Prof_Data(Professional_Contact *nptr, unsigned long int mob);
void Get_Personal_Data(Personal_Contact *nptr, unsigned long int mob);
void Print_Personal_Data(Personal_Contact *nptr);
void Print_Prof_Data(Professional_Contact *nptr);
void assign_data(Personal_Contact* per, Personal_Contact* per2);
void assign_prof_data(Professional_Contact* prof1, Professional_Contact* prof2);
AVL_Tree_per* create_node(unsigned long mob);
AVL_Tree_prof* create_node_prof(unsigned long int mob);
int max(int a, int b);
AVL_Tree_per *minValueNode(AVL_Tree_per* node);
AVL_Tree_prof *minValueNode_prof(AVL_Tree_prof* node);
int height(AVL_Tree_per* node);
int height_prof(AVL_Tree_prof* node);
int getBalance(AVL_Tree_per* node);
int getBalance_prof(AVL_Tree_prof* node);
status_code Rotate_Left(AVL_Tree_per** tree);
status_code Rotate_Left_prof(AVL_Tree_prof** tree);
status_code Rotate_right(AVL_Tree_per** tree);
status_code Rotate_right_prof(AVL_Tree_prof** tree);
AVL_Tree_per* Insert_Node(AVL_Tree_per* node, unsigned long int mob);
AVL_Tree_prof* Insert_Node_prof(AVL_Tree_prof* node, unsigned long int mob);
AVL_Tree_per* Delete_Node(AVL_Tree_per* root, unsigned long int mob);
AVL_Tree_prof* Delete_Node_prof(AVL_Tree_prof* root, unsigned long int mob);
AVL_Tree_per* Search_node_with_mob(AVL_Tree_per* root, unsigned long int mob);
AVL_Tree_prof* Search_node_with_mob_prof(AVL_Tree_prof* root, unsigned long int mob);
void Edit_with_mob(AVL_Tree_per* root, unsigned long int mob);
void Edit_with_mob_prof(AVL_Tree_prof* root, unsigned long int mob);
void mirror_tree(AVL_Tree_per* node);
void mirror_tree_prof(AVL_Tree_prof* node);
void preOrder(AVL_Tree_per *root);
void preOrder_prof(AVL_Tree_prof *root);
void InOrder(AVL_Tree_per *root);
void InOrder_prof(AVL_Tree_prof *root);
void Post_Order(AVL_Tree_per* root);
void Post_Order_prof(AVL_Tree_prof* root);
void reverse_sorted_display(AVL_Tree_per* root);
void reverse_sorted_display_prof(AVL_Tree_prof* root);
void Range_search(AVL_Tree_per* root, unsigned long int mob1, unsigned long int mob2);
void Range_search_prof(AVL_Tree_prof* root, unsigned long int mob1, unsigned long int mob2);
AVL_Tree_per* create_node_with_data(Personal_Contact* per);
AVL_Tree_prof* create_node_with_data_prof(Professional_Contact* Prof);
AVL_Tree_per* Insert_Node_by_name(AVL_Tree_per* node, Personal_Contact* per);
AVL_Tree_prof* Insert_Node_by_name_prof(AVL_Tree_prof* node, Professional_Contact* prof);
AVL_Tree_per* Create_sorted_by_name_tree(AVL_Tree_per* root, AVL_Tree_per* root2);
AVL_Tree_prof* Create_sorted_by_name_tree_prof(AVL_Tree_prof* root, AVL_Tree_prof* root2);
void Delete_tree(AVL_Tree_per** root);
void Delete_Tree_prof(AVL_Tree_prof** root);