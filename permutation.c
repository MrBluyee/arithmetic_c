#include <stdio.h>

//全排列
void permutation(int *array,int start,int end){
	int temp;
	int i=0;
	if(start>end)
		return;
	if(start<end){
		permutation(array, start+1, end);
		for(i=start+1;i<=end;i++){
			temp=array[start];
			array[start]=array[i];
			array[i]=temp;
			permutation(array, start+1, end);
			temp=array[start];
			array[start]=array[i];
			array[i]=temp;
		}
	}else{
		for(i=0;i<=end;i++){
			printf("%d ",array[i]);
		}
		printf("\n");
	}
}

int main(void){
	int i[5]={1,3,4,2,5};
	permutation(i,0,4);
	return 0;
}