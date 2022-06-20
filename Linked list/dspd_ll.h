#include<stdio.h>
#include<stdlib.h>
typedef enum {Personal, Proffesional} type;
typedef enum {FAILURE, SUCCESS} status_code;
typedef enum {TRUE, FALSE} boolean;
#define SIZE 100
typedef struct Node_tag
{
    char name[SIZE];
//    char last_name[SIZE];
    char mob[SIZE];
    char email[SIZE];
    int duration;
    struct Node_tag *next;
}Personal_Contact;


typedef struct Node_tag_2
{
    char name[SIZE];
    //char last_name[SIZE];
    char mob[SIZE];
    char email[SIZE];
    char Office_Number[SIZE];
    char Address[SIZE];
    int duration;
    struct Node_tag_2 *next;
}Professional_Contact;


typedef struct Node_tag_3
{
    char name[SIZE];
    char add[SIZE];
    char mob[SIZE];
    struct Node_tag_3* next;
    Personal_Contact* left_per;
    Professional_Contact* right_prof;
}Phonebook;

void Get_Prof_Data(Professional_Contact *nptr);
void Get_Personal_Data(Personal_Contact *nptr);
Personal_Contact* Create_Per_Node();
Professional_Contact* Create_Prof_Node();
void Insert_in_Per_Con_sorted(Personal_Contact *nptr, Personal_Contact **pptr);
void Insert_in_Prof_Con_sorted(Professional_Contact *nptr, Professional_Contact **pptr);
status_code Insert_a_per_con(Personal_Contact **pptr);
status_code Insert_a_prof_con(Professional_Contact **pptr);
void Print_Personal_Data(Personal_Contact *nptr);
void Print_Prof_Data(Professional_Contact *nptr);
void Print_All_Personal_Contact(Personal_Contact* pptr);
void Print_All_Prof_Contact(Professional_Contact* pptr);
Personal_Contact* Search_for_contact(Personal_Contact* pptr,char name[SIZE], char mob[SIZE]);
Professional_Contact* Search_for_prof_contact(Professional_Contact* pptr,char name[SIZE], char mob[SIZE]);
status_code Delete_per_Contact(Personal_Contact **pptr, char name[SIZE], char mob[SIZE]);
status_code Delete_prof_Contact(Professional_Contact **pptr, char name[SIZE], char mob[SIZE]);
void Delete_per_entire(Personal_Contact **pptr);
void Delete_prof_entire(Professional_Contact **pptr);
status_code Edit_per_Contact_completely(Personal_Contact **pptr, char name[SIZE], char mob[SIZE]);
status_code Edit_prof_Contact_completely(Professional_Contact **pptr, char name[SIZE], char mob[SIZE]);
status_code Edit_per_Contact(Personal_Contact *pptr, char name[SIZE], char mob[SIZE]);
status_code Edit_prof_Contact(Professional_Contact *pptr, char name[SIZE], char mob[SIZE]);
void Remove_duplicates_in_per(Personal_Contact* pptr);
void Remove_duplicates_in_prof(Professional_Contact* pptr);
Personal_Contact* Merge_of_Per(Personal_Contact* pptr1, Personal_Contact* pptr2);
Professional_Contact* Merge_of_Prof(Professional_Contact* pptr1, Professional_Contact* pptr2);
void Reverse_Personal_List(Personal_Contact** pptr);
void Reverse_Prof_List(Professional_Contact** pptr);
void Print_Personal_in_reverse(Personal_Contact* pptr);
void Print_Prof_in_reverse(Professional_Contact* pptr);
void Split_Per_in_two(Personal_Contact* nptr ,Personal_Contact** front, Personal_Contact** back);
void Split_Prof_in_two(Professional_Contact* nptr ,Professional_Contact** front, Professional_Contact** back);
void merge_sort_for_Personal(Personal_Contact** pptr);
void merge_sort_for_Prof(Professional_Contact** pptr);
Personal_Contact* Create_Unsorted_Personal(int num_nodes, int dur);
Professional_Contact* Create_Unsorted_Prof(int num_nodes, int dur);
void Get_Phonebook_Data(Phonebook *nptr);
Phonebook* Create_Phone_Node();
status_code Insert_At_start_in_Phonebook(Phonebook** phtr);
void Print_data_of_Phonebook(Phonebook *ph);
void print_phonebook(Phonebook *ph);
Personal_Contact* Merge_of_Per_phbook(Personal_Contact* pptr1, Personal_Contact* pptr2);
void merge_sort_for_Personal_phbook(Personal_Contact** pptr);
Professional_Contact* Merge_of_Prof_phbook(Professional_Contact* pptr1, Professional_Contact* pptr2);
void merge_sort_for_Prof_phbook(Professional_Contact** pptr);
void Delete_Entire_Phonebook(Phonebook **ph);