#include <stdio.h>
#include "crc32.h"

//                      POLY,INIT,XOROUT,REFIN,REFOUT
CRC32_TYPE crc_32 = {0x04C11DB7,0xFFFFFFFF,0xFFFFFFFF,1,1};
CRC32_TYPE crc_32_MPEG_2 = {0x04C11DB7,0xFFFFFFFF,0x00000000,0,0};
CRC32_TYPE crc_32_BZIP_2 = {0x04C11DB7,0xFFFFFFFF,0xFFFFFFFF,0,0};
CRC32_TYPE crc_32_SCTP = {0x1EDC6F41,0xFFFFFFFF,0xFFFFFFFF,0,0};
CRC32_TYPE crc_32_JAMCRC = {0x04C11DB7,0xFFFFFFFF,0x00000000,1,1};

uint32_t reflect_uint32_t_bits(uint32_t data){
	uint32_t result = 0,index = 0x01;
	uint8_t i;
	for (i = 0;i < 32;i++,index <<= 1){
		if(data & index){
			result |= 0x01 << (31 - i);
		}
	}
	return result;
}

uint32_t crc32(uint8_t *data, uint32_t length, uint32_t crc_reg,CRC32_TYPE crc_type){
	uint8_t i;
	while(length--){
		if(crc_type.refin){
			uint32_t poly_ref = reflect_uint32_t_bits(crc_type.poly);
			crc_reg ^= *data++;
			for (i=0;i<8;i++){
				if (crc_reg & 0x01){
					crc_reg = (crc_reg >> 1) ^ poly_ref;
				}else{
					crc_reg >>= 1;
				}
			}
		}else{
			crc_reg ^= (*data++ << 24);
			for (i=0;i<8;i++){
				if (crc_reg & 0x80000000){
					crc_reg = (crc_reg << 1) ^ crc_type.poly;
				}else{
					crc_reg <<= 1;
				}
			}
		}
	}
	return crc_reg;
}

uint32_t crc32_final_process(uint32_t crc_reg,CRC32_TYPE crc_type){
	if(crc_type.refin ^ crc_type.refout){
		crc_reg = reflect_uint32_t_bits(crc_reg);
	}
	return crc_reg ^ crc_type.xorout;
}

int main(void){
	uint8_t data[] = {0X01,0X06,0X00,0X00,0X00,0X10};
	uint32_t crc_result = 0;
	crc_result = crc32(data,6,crc_32.init,crc_32);
	crc_result = crc32_final_process(crc_result,crc_32);
	printf("crc_32 result = %x\n",crc_result);

	crc_result = crc32(data,6,crc_32_MPEG_2.init,crc_32_MPEG_2);
	crc_result = crc32_final_process(crc_result,crc_32_MPEG_2);
	printf("crc_32_MPEG_2 result = %x\n",crc_result);
	
	crc_result = crc32(data,6,crc_32_BZIP_2.init,crc_32_BZIP_2);
	crc_result = crc32_final_process(crc_result,crc_32_BZIP_2);
	printf("crc_32_BZIP_2 result = %x\n",crc_result);

	crc_result = crc32(data,6,crc_32_SCTP.init,crc_32_SCTP);
	crc_result = crc32_final_process(crc_result,crc_32_SCTP);
	printf("crc_32_SCTP result = %x\n",crc_result);
	
	crc_result = crc32(data,6,crc_32_JAMCRC.init,crc_32_JAMCRC);
	crc_result = crc32_final_process(crc_result,crc_32_JAMCRC);
	printf("crc_32_JAMCRC result = %x\n",crc_result);
	return 0;
}