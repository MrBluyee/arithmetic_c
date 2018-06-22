#include <stdio.h>

//每次比较两个相邻的元素，如果它们的顺序错误就把它们交换过来,复杂度O(N^2)
void bubble_sort(int *array,int start,int end){
	int temp;
	int i=0,j=0;
	for(i=start;i<=end-1;i++){
		for(j=start;j<=end-i;j++){
			if(array[j]<array[j+1]){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}

int main(void){
	int j=0;
	int i[5]={1,3,4,2,5};
	bubble_sort(i,0,4);
	for(j=0;j<5;j++){
		printf("%d ",i[j]);
	}
	return 0;
}