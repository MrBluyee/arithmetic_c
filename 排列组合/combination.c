#include <stdio.h>
#include "combination.h"

//组合,C(num,m)
void combination(int *array,int start,int num,int m){
	static int queue[N];
	static int top;
	int i;
	if(start>num)
		return;
	if(top==m){
		for(i=0;i<m;i++){
			printf("%d ",queue[i]);
		}
		printf("\n");
		return;
	}
	queue[top++] = array[start];
	combination(array,start+1,num,m);
	top--;
	combination(array,start+1,num,m);
}
