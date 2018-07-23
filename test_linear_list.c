#include <stdio.h>
#include <malloc.h>
#include "linear_list.h"

int main(void)
{
	int i;
	ElemType elem;
	LinearList *list_a = (LinearList *)malloc(sizeof(LinearList));
	LinearList *list_b = (LinearList *)malloc(sizeof(LinearList));
	LinearList *list_c = (LinearList *)malloc(sizeof(LinearList));
	init_list(list_a);
	init_list(list_b);
	init_list(list_c);
	
	for (i = 0; i < 10; i++){
		append_elem(list_a,&i);
	}
	
	for (i = 0; i < 20; i+=2){
		append_elem(list_b,&i);
	}	
	print_list(list_a);
	print_list(list_b);
	
	pop_elem(list_a, &elem);
	print_list(list_a);
	printf("pop: %d \n",elem);
	
	delete_elem(list_a, 2, &elem);
	print_list(list_a);
	printf("delete: %d \n",elem);
	
	insert_elem(list_a, 2, &elem);
	printf("insert: %d \n",elem);
	print_list(list_a);
	
	get_elem(list_a, 5, &elem);
	printf("get elem at 5: %d \n",elem);
	
	printf("locate : elem %d at %d \n",elem,locate_elem(list_a,&elem));
	
	printf("list_a length : %d \n",list_length(list_a));
	
	print_list(list_a);
	print_list(list_b);
	
	union_list(list_a,list_b,list_c);
	print_list(list_c);
	clear_list(list_c);
	
	intersect_list(list_a,list_b,list_c);
	print_list(list_c);
	clear_list(list_c);
	
	except_list(list_a,list_b,list_c);
	print_list(list_c);
	
	destroy_list(list_a);
	destroy_list(list_b);
	destroy_list(list_c);
	
	return 0;
}