/* 
 * File:   List.h
 * Author: Marco Túlio Londe Silva
 */
#ifndef LIST_H
#define LIST_H

typedef struct H* List;
typedef struct N* List_Node;

/*The positions in the list start at 1*/


List New_List(); 
/*This function creates a new list in memory, this function must be used before the other 
* manipulations in the list. Returns an empty list if there is memory,if there 
* is none, returns NULL, and a message about the lack of memory, in the standard output.*/

int get_size(List l);
/*This function returns the number of nodes present in a list if it exists,
*if there is no return -1 */

List_Node get_head(List l);
/*This function returns the first node of a list if it exists,
*if there is no return NULL.This function is commonly used to do this:
*               List_Node N;
*               for(N = get_head(L);N!=NULL;N = get_next(N))
*These commands are used to scroll through the list from the lowest to the highest position.*/

List_Node get_tail(List l);
/*This function returns the last node of a list if it exists,
*if there is no return NULL.This function is commonly used to do this:
*               List_Node N;
*               for(N = get_tail(L);N!=NULL;N = get_before(N))
*These commands are used to scroll through the list from the highest to the lowest position.*/

List_Node get_next(List_Node n);
/*This function returns a node next to the passed node if it exists,
*if there is no return NULL.*/

List_Node get_before(List_Node n);
/*This function returns a node before to the passed node if it exists,
*if there is no return NULL*/

void* get_node_content(List_Node n);
/*This function returns a pointer from the content of a node passed if it exists,
*if there is no return NULL.To use the content, you need a pointer to the 
* correct type of data used to create this node. Example: 
*               float* pf;
*               for(N = get_tail(L);N!=NULL;N = get_before(N)){                   
*                   pf=get_node_content(N); 
*                   printf("\n\t%d %.2f",get_position(N),*pf);
*               }
* By changing the information pointed to by the pointer, which receives information from this function, 
* the information in the list is changed as well.*/

char* get_node_type(List_Node n);
/*This function returns a string with the type saved at the time of insertion of a node if it exists,
*if there is no return NULL.*/

void* get_content(List l,int position);
/*This function returns a pointer from the content of a node in the position passed if it exists,
*if there is no or the list is invalid return NULL.To use the content, you need a pointer to the 
* correct type of data used to create this node. As explained in the get_node_content function.*/

int get_position(List_Node n);
/*This function returns the position of a node if it exists,
*if there is no return -1*/

int Insert_List(List l,void* content,int position, char* type);
/*This function inserts a new node in the list, 
* receives as parameters a created list, 
* a pointer to any data type (this pointer must be allocated in 
* memory and should not be reused to not change the information pointed out by it), 
* the position where the node should be inserted and a string with a maximum 
* length of 19 characters with data type of that node(this field is used to remember what type of data 
* was entered on that node by the programmer).
* Your returns are 0 for wrong passed information such as, invalid positions (example: try to
*  insert in position 10 in a list of 4 members), very 
* long type (example: string type has size 22) and list not created (example: pass as 
* parameter a List type without first using the New_List () function), returns -1 when there 
* is no memory to allocate the node and returns 1 when the insertion was successful. Example:
*               List L = New_List();
*               i=(int*)malloc(sizeof(int)); 
*               *i = 30;
*               Insert_List(L,i,1,"int*\0");
*In this example it is recommended, to avoid changing the contents of the list, to allocate 
* another memory space for variable i using the malloc function, before reusing this variable.*/

int Delete_List(List l,int position);
/*This function delete a node in the list, 
* receives as parameters a created list, 
* the position where the node should be deleted.
* Your returns are 0 for wrong passed information such as, invalid positions (example: try to
*  delete position 10 in a list of 4 members), and list not created (example: pass as 
* parameter a List type without first using the New_List () function),returns 1 when 
* the deletion was successful.*/


int Destroy_List(List l);
/*This function deallocates the list from memory, returns 1 when the dealocation was successful and
*returns 0 when the list passed was not created.*/

#endif