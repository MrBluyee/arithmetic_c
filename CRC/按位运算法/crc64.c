#include <stdio.h>
#include "crc64.h"

//                      POLY,INIT,XOROUT,REFIN,REFOUT
CRC64_TYPE crc_64 = {0x000000000000001B,0x0000000000000000,0x0000000000000000,0,0};
CRC64_TYPE crc_64_ECMA = {0x42F0E1EBA9EA3693,0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF,0,0};

uint64_t reflect_uint64_t_bits(uint64_t data){
	uint64_t result = 0,index = 0x01;
	uint8_t i;
	for (i = 0;i < 64;i++,index <<= 1){
		if(data & index){
			result |= 0x01 << (63 - i);
		}
	}
	return result;
}

uint64_t crc64(uint8_t *data, uint32_t length, uint64_t crc_reg,CRC64_TYPE crc_type){
	uint8_t i;
	while(length--){
		if(crc_type.refin){
			uint64_t poly_ref = reflect_uint64_t_bits(crc_type.poly);
			crc_reg ^= *data++;
			for (i=0;i<8;i++){
				if (crc_reg & 0x01){
					crc_reg = (crc_reg >> 1) ^ poly_ref;
				}else{
					crc_reg >>= 1;
				}
			}
		}else{
			crc_reg ^= ((uint64_t)(*data++) << 56);
			for (i=0;i<8;i++){
				if (crc_reg & 0x8000000000000000){
					crc_reg = (crc_reg << 1) ^ crc_type.poly;
				}else{
					crc_reg <<= 1;
				}
			}
		}
	}
	return crc_reg;
}

uint64_t crc64_final_process(uint64_t crc_reg,CRC64_TYPE crc_type){
	if(crc_type.refin ^ crc_type.refout){
		crc_reg = reflect_uint64_t_bits(crc_reg);
	}
	return crc_reg ^ crc_type.xorout;
}

int main(void){
	uint8_t data[] = {0X01,0X06,0X00,0X00,0X00,0X10};
	uint64_t crc_result = 0;
	crc_result = crc64(data,6,crc_64.init,crc_64);
	crc_result = crc64_final_process(crc_result,crc_64);
	printf("crc_64 result = %llx\n",crc_result);
	
	crc_result = crc64(data,6,crc_64_ECMA.init,crc_64_ECMA);
	crc_result = crc64_final_process(crc_result,crc_64_ECMA);
	printf("crc_64_ECMA result = %llx\n",crc_result);
	
	return 0;
}