#include <stdio.h>
#include <string.h>
#include "quick_sort.h"

int main(void){
	int j=0;
	int i[5]={1,3,4,2,5};
	char array1[20] = "mrbluyee";
	char array2[20][STRING_LEN] = {"7","13","4","246","35"};
	
	quick_sort_int(i,0,4);
	for(j=0;j<5;j++){
		printf("%d ",i[j]);
	}
	printf("\n");
	
	quick_sort_char(array1,0,strlen(array1)-1);
	printf("%s",array1);
	printf("\n");
	
	quick_sort_string(array2,0,4);
	for(j=0;j<5;j++){
		printf("%s",array2[j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}