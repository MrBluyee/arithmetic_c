/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LINEAR_LIST_H
#define __LINEAR_LIST_H
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef int ElemType;      //数据元素的类型，假设是int型的

typedef struct{
	ElemType *elem;  //存储空间的基地址
	int length;      //当前线性表的长度
	int listsize;    //当前分配的存储容量
}LinearList;
/* Exported define -----------------------------------------------------------*/
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量(当存储空间不够时要用到)
/* Exported macro ------------------------------------------------------------*/

//线性表

int init_list(LinearList* list);

void clear_list(LinearList* list);

void destroy_list(LinearList* list);

int list_empty(LinearList* list);

int list_length(LinearList* list);

void print_list(LinearList* list);

int locate_elem(LinearList* list, ElemType* x);

int prior_elem(LinearList* list, ElemType* cur_elem, ElemType* pre_elem);

int get_elem(LinearList* list, int index, ElemType* e);

int next_elem(LinearList* list, ElemType* cur_elem, ElemType* next_elem);

int insert_elem(LinearList* list, int index, ElemType* e);;

int delete_elem(LinearList* list, int index, ElemType* e);

int append_elem(LinearList* list,ElemType* e);

int pop_elem(LinearList* list, ElemType* e);

void union_list(LinearList* list_a, LinearList* list_b, LinearList* list_c); //并集,C=A∪B

void intersect_list(LinearList* list_a, LinearList* list_b, LinearList* list_c); //交集,C=A∩B

void except_list(LinearList* list_a,LinearList* list_b, LinearList* list_c); //差集,C=A-B(属于A而不属于B)

#endif
