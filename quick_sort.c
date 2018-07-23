#include "quick_sort.h"
#include <stdio.h>
#include <string.h>
//快速排序基于二分思想,平均时间复杂度O(NlogN)
//数值排序
void quick_sort_int(int *array,int start,int end){
	int i,j,t,temp;
	if(start>end)
		return;
	temp=array[start];
	i=start;
	j=end;
	while(i!=j){
		while(array[j]>=temp && i<j){//先从右往左找
			j--;
		}
		while(array[i]<=temp && i<j){//再从左往右找
			i++;
		}
		if(i<j){
			t=array[i];
			array[i]=array[j];
			array[j]=t;
		}
	}
	array[start]=array[i];
	array[i]=temp;
	quick_sort_int(array,start,i-1);//继续处理左边的
	quick_sort_int(array,i+1,end);//继续处理右边的
}

//字符串内排序
void quick_sort_char(char *array,int start,int end){
	int i,j;
	char t,temp;
	if(start>end)
		return;
	temp=array[start];
	i=start;
	j=end;
	while(i!=j){
		while(array[j]>=temp && i<j){//先从右往左找
			j--;
		}
		while(array[i]<=temp && i<j){//再从左往右找
			i++;
		}
		if(i<j){
			t=array[i];
			array[i]=array[j];
			array[j]=t;
		}
	}
	array[start]=array[i];
	array[i]=temp;
	quick_sort_char(array,start,i-1);//继续处理左边的
	quick_sort_char(array,i+1,end);//继续处理右边的
}

//字符串间排序,首字母,默认长度为10
#define STRING_LEN 10
void quick_sort_string(char (*array)[STRING_LEN],int start,int end){
	int i,j;
	char t[STRING_LEN],temp[STRING_LEN];
	if(start>end)
		return;
	strncpy(temp,array[start],STRING_LEN);
	i=start;
	j=end;
	while(i!=j){
		while(array[j][0]>=temp[0] && i<j){//先从右往左找
			j--;
		}
		while(array[i][0]<=temp[0] && i<j){//再从左往右找
			i++;
		}
		if(i<j){
			strncpy(t,array[i],STRING_LEN);
			strncpy(array[i],array[j],STRING_LEN);
			strncpy(array[j],t,STRING_LEN);
		}
	}
	strncpy(array[start],array[i],STRING_LEN);
	strncpy(array[i],temp,STRING_LEN);
	quick_sort_string(array,start,i-1);//继续处理左边的
	quick_sort_string(array,i+1,end);//继续处理右边的
}
