#include "bubble_sort.h"
#include <stdio.h>

int main(void){
	int j=0;
	int i[5]={1,3,4,2,5};
	bubble_sort(i,0,4);
	for(j=0;j<5;j++){
		printf("%d ",i[j]);
	}
	return 0;
}