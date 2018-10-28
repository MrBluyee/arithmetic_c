#include <stdio.h>
#include "bucket_sort.h"

//排序比较小的数值,复杂度O(M+N)
void bucket_sort(int *array,int start,int end){
	int book[100] = {0};
	int i=0,j=0;
	for(i=start;i<=end;i++){
		book[array[i]]++;
	}
	for(i=0;i<100;i++){
		for(j=1;j<=book[i];j++){
			printf("%d ",i);
		}
	}
}
