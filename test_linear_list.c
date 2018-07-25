#include <stdio.h>
#include <malloc.h>
#include "linear_list.h"

int main(void)
{
	int i;
	LinearListElemType elem;
	LinearList *list_a = (LinearList *)malloc(sizeof(LinearList));
	LinearList *list_b = (LinearList *)malloc(sizeof(LinearList));
	LinearList *list_c = (LinearList *)malloc(sizeof(LinearList));
	init_linear_list(list_a);
	init_linear_list(list_b);
	init_linear_list(list_c);
	
	for (i = 0; i < 10; i++){
		linear_list_append_elem(list_a,&i);
	}
	
	for (i = 0; i < 20; i+=2){
		linear_list_append_elem(list_b,&i);
	}	
	print_linear_list(list_a);
	print_linear_list(list_b);
	
	linear_list_pop_elem(list_a, &elem);
	print_linear_list(list_a);
	printf("pop: %d \n",elem);
	
	linear_list_delete_elem(list_a, 2, &elem);
	print_linear_list(list_a);
	printf("delete: %d \n",elem);
	
	linear_list_insert_elem(list_a, 2, &elem);
	printf("insert: %d \n",elem);
	print_linear_list(list_a);
	
	linear_list_get_elem(list_a, 5, &elem);
	printf("get elem at 5: %d \n",elem);
	
	printf("locate : elem %d at %d \n",elem,linear_list_locate_elem(list_a,&elem));
	
	printf("list_a length : %d \n",linear_list_length(list_a));
	
	print_linear_list(list_a);
	print_linear_list(list_b);
	
	union_linear_list(list_a,list_b,list_c);
	print_linear_list(list_c);
	clear_linear_list(list_c);
	
	intersect_linear_list(list_a,list_b,list_c);
	print_linear_list(list_c);
	clear_linear_list(list_c);
	
	except_linear_list(list_a,list_b,list_c);
	print_linear_list(list_c);
	
	destroy_linear_list(list_a);
	destroy_linear_list(list_b);
	destroy_linear_list(list_c);
	
	return 0;
}