#ifndef _CRC64_H
#define _CRC64_H

#include "type_define.h"

typedef struct CRC64_TYPE{
	uint64_t poly;   //多项式
	uint64_t init;   //reg初始值
	uint64_t xorout; //结果异或值
	uint8_t refin;   //输入数据反转
	uint8_t refout;  //输出数据反转
}CRC64_TYPE;

#endif