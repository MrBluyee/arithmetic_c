#include <stdio.h>
#include "bucket_sort.h"

int main(void){
	int i[5]={1,3,4,2,5};
	bucket_sort(i,0,4);
	return 0;
}