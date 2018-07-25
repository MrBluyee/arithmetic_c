/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LINEAR_LIST_H
#define __LINEAR_LIST_H
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef int LinearListElemType;      //数据元素的类型，假设是int型的

typedef struct{
	LinearListElemType *elem;  //存储空间的基地址
	int length;      //当前线性表的长度
	int listsize;    //当前分配的存储容量
}LinearList;
/* Exported define -----------------------------------------------------------*/
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量(当存储空间不够时要用到)
/* Exported macro ------------------------------------------------------------*/

//线性表

int init_linear_list(LinearList* list);

void clear_linear_list(LinearList* list);

void destroy_linear_list(LinearList* list);

int linear_list_empty(LinearList* list);

int linear_list_length(LinearList* list);

void print_linear_list(LinearList* list);

int linear_list_locate_elem(LinearList* list, LinearListElemType* x);

int linear_list_prior_elem(LinearList* list, LinearListElemType* cur_elem, LinearListElemType* pre_elem);

int linear_list_get_elem(LinearList* list, int index, LinearListElemType* e);

int linear_list_modify_elem(LinearList* list, int index, LinearListElemType* e);

int linear_list_next_elem(LinearList* list, LinearListElemType* cur_elem, LinearListElemType* next_elem);

int linear_list_insert_elem(LinearList* list, int index, LinearListElemType* e);

int linear_list_delete_elem(LinearList* list, int index, LinearListElemType* e);

int linear_list_append_elem(LinearList* list,LinearListElemType* e);

int linear_list_pop_elem(LinearList* list, LinearListElemType* e);

void union_linear_list(LinearList* list_a, LinearList* list_b, LinearList* list_c); //并集,C=A∪B

void intersect_linear_list(LinearList* list_a, LinearList* list_b, LinearList* list_c); //交集,C=A∩B

void except_linear_list(LinearList* list_a,LinearList* list_b, LinearList* list_c); //差集,C=A-B(属于A而不属于B)

#endif
