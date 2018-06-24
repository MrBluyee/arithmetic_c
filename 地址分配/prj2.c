/*********************************************************
地址池标记地址、分配地址、打印地址分配情况、地址池同步。
地址：0~255
按位存储地址，节省空间。
*********************************************************/
#include <stdio.h>

int addrpool[32]={0};
int addrpool_sync[32]={0};

void addr_mark(int addr)
{
	int byte_index = addr / 8;
	int bit_index = addr % 8;
	addrpool[byte_index] |= (0x01<<bit_index);
}

void addr_demark(int addr)
{
	int byte_index = addr / 8;
	int bit_index = addr % 8;
	addrpool[byte_index] &= ~(0x01<<bit_index);
}

int is_addr_online(int addr)
{
	int byte_index = addr / 8;
	int bit_index = addr % 8;
	return addrpool[byte_index] & (0x01<<bit_index);
}

void addr_sync(int *sync_addrdata)
{
	int i,j;
	for(i=0;i<32;i++)
	{
		for(j=0;j<8;j++)
		{
			if((sync_addrdata[i] & (0x01<<j)) != 0)
			{
				addrpool[i] |= (0x01<<j);
			}
		}
	}	
}

int allocate_addr()
{
	int i,j,temp=0;
	for(i=0;i<32;i++)
	{
		for(j=0;j<8;j++)
		{
			if((addrpool[i] & (0x01<<j)) == 0)
			{
				temp = i*8 + j;
				addrpool[i] |= (0x01<<j);
				break;
			}
		}
		if(temp != 0)
		{
			break;
		}
	}
	return temp;
}

void print_addrpool()
{
	int i,j,temp;
	for(i=0;i<32;i++)
	{
		for(j=0;j<8;j++)
		{
			temp = i*8 + j;
			if((addrpool[i] & (0x01<<j)) == 0)
			{
				printf("addr:%d,used:%d\r\n",temp,0);
			}
			else
			{
				printf("addr:%d,used:%d\r\n",temp,1);
			}
		}
	}	
}

void print_addr_online(void)
{
	int i,status;
	for(i=0;i<255;i++)
	{
		status = is_addr_online(i);
		if(status == 0) 
		{
			printf("addr:%d is offline\r\n",i);
		}
		else
		{
			printf("addr:%d is online\r\n",i);
		}
	}
}

int main(void)
{
	int i,j;
	for(i=0;i<122;i++)
	{
		addr_mark(i);
	}
	print_addrpool();
	j = allocate_addr();
	printf("allocate addr:%d\r\n",j);
	addr_sync(addrpool_sync);
	for(i=5;i<60;i++)
	{
		addr_demark(i);
	}
	print_addrpool();
	print_addr_online();
	return 0;
}