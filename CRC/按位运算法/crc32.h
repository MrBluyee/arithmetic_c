#ifndef _CRC32_H
#define _CRC32_H

#include "type_define.h"

typedef struct CRC32_TYPE{
	uint32_t poly;   //多项式
	uint32_t init;   //reg初始值
	uint32_t xorout; //结果异或值
	uint8_t refin;   //输入数据反转
	uint8_t refout;  //输出数据反转
}CRC32_TYPE;

#endif