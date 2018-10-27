#ifndef _CRC16_H
#define _CRC16_H

#include "type_define.h"

typedef struct CRC16_TYPE{
	uint16_t poly;   //多项式
	uint16_t init;   //reg初始值
	uint16_t xorout; //结果异或值
	uint8_t refin;   //输入数据反转
	uint8_t refout;  //输出数据反转
}CRC16_TYPE;

#endif