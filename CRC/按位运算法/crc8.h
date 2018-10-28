#ifndef _CRC8_H
#define _CRC8_H

#include "type_define.h"

typedef struct CRC8_TYPE{
	uint8_t poly;   //多项式
	uint8_t init;   //reg初始值
	uint8_t xorout; //结果异或值
	uint8_t refin;   //输入数据反转
	uint8_t refout;  //输出数据反转
}CRC8_TYPE;

#endif