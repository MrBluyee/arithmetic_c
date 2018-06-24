/*********************************************************
给定一个数字，不超过10位，如9876730，
先从左向右，删除相同数字，则变为987630
然后删掉后的数字从右向左组成新的数字输出，即36789
*********************************************************/
#include <stdio.h>

int transfer(int num);
int mypow10(int count);

int main()
{
	int a,b;
	scanf("%d",&b);
    a = transfer(b);
	printf("%d\n",a);
    return 0;
}

int transfer(int num)
{
	int i = 0,j = 0;
	int num_s[10] = {0};
	int num_num[10] = {0};
	int new_num[10] = {0};
	int new_number = 0;
	for(i=0;i<9;i++)
	{
		num_s[i] = num / (1000000000/mypow10(i));
		num = num % (1000000000/mypow10(i));
		num_num[num_s[i]] ++ ;
		if(num_num[num_s[i]] <= 1)
		{
			new_num[j++] = num_s[i];
		}
	}
	num_s[9] = num;
	num_num[num_s[9]] ++ ;
	if(num_num[num_s[9]] <= 1)
	{
		new_num[j++] = num_s[9];
	}
	for(i=j;i>1;i--)
	{
		new_number += (new_num[i-1] * mypow10(i-2));
	}
	return new_number;
}

int mypow10(int count)
{
	int i = 0;
	int temp = 1;
	for(i=0;i<count;i++)
	{
		temp *= 10;
	}
	return temp;
}