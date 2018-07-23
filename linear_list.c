#include <stdio.h>
#include <malloc.h>
#include "linear_list.h"
//线性表

int init_list(LinearList* list){
	list->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!list->elem){
		return -1; //空间分配失败
	}
	list->length = 0; //当前长度
	list->listsize = LIST_INIT_SIZE; //当前分配量
	return 0;
}

void clear_list(LinearList* list){
	list->length = 0; //当前长度
}

void destroy_list(LinearList* list){
	free(list);
}

int list_empty(LinearList* list){
	return (list->length == 0);
}

int list_length(LinearList* list){
	return list->length;
}

void print_list(LinearList* list){
	int i;
	for (i=0; i < list->length; i++){
		printf("%d ", list->elem[i]);
	}
	printf("\n");
}

int locate_elem(LinearList* list, ElemType* x){
	int pos = -1;
	for (int i = 0; i < list->length; i++){
		if (list->elem[i] == *x){
			pos = i;
		}
	}
	return pos;
}

int prior_elem(LinearList* list, ElemType* cur_elem, ElemType* pre_elem){
	int pos = -1;
	pos = locate_elem(list, cur_elem);
	if(pos <= 0) return -1;
	*pre_elem = list->elem[pos-1];
	return 0;
}

int get_elem(LinearList* list, int index, ElemType* e){
	if (index<0 || index >= list->length) return -1;
	*e = list->elem[index];
	return 0;
}

int next_elem(LinearList* list, ElemType* cur_elem, ElemType* next_elem){
	int pos = -1;
	pos = locate_elem(list, cur_elem);
	if(pos == -1 || pos == (list->length - 1)) return -1;
	*next_elem = list->elem[pos+1];
	return 0;
}

int insert_elem(LinearList* list, int index, ElemType* e){
	if (index<0 || index >= list->length) return -1;
	if (list->length >= list->listsize){ //判断存储空间是否够用
		ElemType *newbase = (ElemType *)realloc(list->elem, (list->listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) return -1;//存储空间分配失败
		list->elem = newbase;//新基址
		list->listsize += LISTINCREMENT;//增加存储容量
	}
	ElemType *q, *p;
	q = &(list->elem[index]); //q为插入位置
	for (p = &(list->elem[list->length - 1]); p >= q; --p){ //从ai到an-1依次后移，注意后移操作要从后往前进行
		*(p + 1) = *p;
	}
	*q = *e;
	++list->length;
	return 0;
}

int delete_elem(LinearList* list, int index, ElemType* e)
{
	if (index<1 || index > list->length) return -1;
	ElemType *q, *p;
	p = &(list->elem[index]);//p为被删除元素的位置
	*e = *p; //被删除的元素赋值给e
	q = list->elem + list->length - 1;//q指向表尾最后一个元素
	for (++p; p <= q; ++p){ //从p的下一个元素开始依次前移
		*(p - 1) = *p;
	}
	--list->length;
	return 0;
}

int append_elem(LinearList* list,ElemType* e){
	if (list->length >= list->listsize){ //判断存储空间是否够用
		ElemType *newbase = (ElemType *)realloc(list->elem, (list->listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) return -1;//存储空间分配失败
		list->elem = newbase;//新基址
		list->listsize += LISTINCREMENT;//增加存储容量
	}
	list->elem[list->length] = *e;
	++list->length;
	return 0;
}

int pop_elem(LinearList* list, ElemType* e){
	if (list_empty(list)) return -1;
	*e = list->elem[list->length - 1];
	--list->length;
	return 0;
}

void union_list(LinearList* list_a, LinearList* list_b, LinearList* list_c){ //并集,C=A∪B
	int i,a_length,b_length;
	ElemType elem;
	a_length = list_length(list_a);
	b_length = list_length(list_b);
	for(i=0;i<a_length;i++){
		get_elem(list_a, i, &elem);
		append_elem(list_c,&elem);
	}	
	for(i=0;i<b_length;i++){
		get_elem(list_b, i, &elem);
		if(locate_elem(list_a, &elem) == -1){
			append_elem(list_c,&elem);
		}
	}
}

void intersect_list(LinearList* list_a, LinearList* list_b, LinearList* list_c){ //交集,C=A∩B
	int i,a_length;
	ElemType elem;
	a_length = list_length(list_a);
	for(i=0;i<a_length;i++){
		get_elem(list_a, i, &elem);
		if(locate_elem(list_b, &elem) != -1){
			append_elem(list_c,&elem);
		}
	}
}

void except_list(LinearList* list_a,LinearList* list_b, LinearList* list_c){ //差集,C=A-B(属于A而不属于B)
	int i,a_length;
	ElemType elem;
	a_length = list_length(list_a);
	for(i=0;i<a_length;i++){
		get_elem(list_a, i, &elem);
		if(locate_elem(list_b, &elem) == -1){
			append_elem(list_c,&elem);
		}
	}
}
