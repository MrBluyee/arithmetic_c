#include <stdio.h>
#include "crc8.h"

//               POLY,INIT,XOROUT,REFIN,REFOUT
CRC8_TYPE crc_8 = {0x07,0x00,0x00,0,0};
CRC8_TYPE crc_8_ITU = {0x07,0x00,0x55,0,0};
CRC8_TYPE crc_8_ROHC = {0x07,0xFF,0x00,1,1};
CRC8_TYPE crc_8_MAXIM = {0x31,0x00,0x00,1,1};

uint8_t reflect_uint8_t_bits(uint8_t data){
	uint8_t result = 0,i,index = 0x01;
	for (i = 0;i < 8;i++,index <<= 1){
		if(data & index){
			result |= 0x01 << (7 - i);
		}
	}
	return result;
}

uint8_t crc8(uint8_t *data, uint32_t length,uint8_t crc_reg,CRC8_TYPE crc_type){
	uint8_t i;
	while(length--){
		crc_reg ^= *data++;
		if(crc_type.refin){
			uint8_t poly_ref = reflect_uint8_t_bits(crc_type.poly);
			for (i=0;i<8;i++){
				if (crc_reg & 0x01){
					crc_reg = (crc_reg >> 1) ^ poly_ref;
				}else{
					crc_reg >>= 1;
				}
			}
		}else{
			for (i=0;i<8;i++){
				if (crc_reg & 0x80){
					crc_reg = (crc_reg << 1) ^ crc_type.poly;
				}else{
					crc_reg <<= 1;
				}
			}
		}
	}
	return crc_reg;
}

uint8_t crc8_final_process(uint8_t crc_reg,CRC8_TYPE crc_type){
	if(crc_type.refin ^ crc_type.refout){
		crc_reg = reflect_uint8_t_bits(crc_reg);
	}
	return crc_reg ^ crc_type.xorout;
}

int main(void){
	uint8_t data[] = {0X01,0X06,0X00,0X00,0X00,0X10};
	uint8_t crc_result = 0;
	crc_result = crc8(data,6,crc_8.init,crc_8);
	crc_result = crc8_final_process(crc_result,crc_8);
	printf("crc_8 result = %x\n",crc_result);
	
	crc_result = crc8(data,6,crc_8_ITU.init,crc_8_ITU);
	crc_result = crc8_final_process(crc_result,crc_8_ITU);
	printf("crc_8_ITU result = %x\n",crc_result);
	
	crc_result = crc8(data,6,crc_8_ROHC.init,crc_8_ROHC);
	crc_result = crc8_final_process(crc_result,crc_8_ROHC);
	printf("crc_8_ROHC result = %x\n",crc_result);
	
	crc_result = crc8(data,6,crc_8_MAXIM.init,crc_8_MAXIM);
	crc_result = crc8_final_process(crc_result,crc_8_MAXIM);
	printf("crc_8_MAXIM result = %x\n",crc_result);	
	return 0;
}