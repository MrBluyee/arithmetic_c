#include <stdio.h>

//获取整数
void get_int_numbers(int *array,int *num){
	int i=0;
	scanf("%d",num);
	for(i=0;i<*num;i++){
		scanf("%d",&array[i]);
	}
}
//获取整数的字符(int型最大字符长度为10)
void get_split_strings(char (*array)[10],int *num){
	int i=0;
	scanf("%d",num);
	for(i=0;i<*num;i++){
		scanf("%s",array[i]);
	}	
}

int main(void)
{
	int i=0;
	int num=0;
	int array1[100]={0};
	char array2[100][10]={0};
	
	get_int_numbers(array1,&num);
	for(i=0;i<num;i++)
	{
		printf("%d\n",array[i]);
	}
	
	get_split_strings(array2,&num);
	for(i=0;i<num;i++)
	{
		printf("%s\n",array2[i]);
	}
	
	return 0;
}