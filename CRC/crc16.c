#include <stdio.h>
#include "crc16.h"

//                      POLY,INIT,XOROUT,REFIN,REFOUT
CRC16_TYPE crc_16_IBM = {0x8005,0x0000,0x0000,1,1};
CRC16_TYPE crc_16_MAXIM = {0x8005,0x0000,0xFFFF,1,1};
CRC16_TYPE crc_16_USB = {0x8005,0xFFFF,0xFFFF,1,1};
CRC16_TYPE crc_16_MODBUS = {0x8005,0xFFFF,0x0000,1,1};
CRC16_TYPE crc_16_CCITT = {0x1021,0x0000,0x0000,1,1};
CRC16_TYPE crc_16_CCITT_FALSE = {0x1021,0xFFFF,0x0000,0,0};
CRC16_TYPE crc_16_X25 = {0x1021,0xFFFF,0xFFFF,1,1};
CRC16_TYPE crc_16_XMODEM = {0x1021,0x0000,0x0000,0,0};
CRC16_TYPE crc_16_DNP = {0x3D65,0x0000,0xFFFF,1,1};

uint16_t reflect_uint16_t_bits(uint16_t data){
	uint16_t result = 0,index = 0x01;
	uint8_t i;
	for (i = 0;i < 16;i++,index <<= 1){
		if(data & index){
			result |= 0x01 << (15 - i);
		}
	}
	return result;
}

uint16_t crc16(uint8_t *data, uint32_t length, uint16_t crc_reg,CRC16_TYPE crc_type){
	uint8_t i;
	while(length--){
		if(crc_type.refin){
			uint16_t poly_ref = reflect_uint16_t_bits(crc_type.poly);
			crc_reg ^= *data++;
			for (i=0;i<8;i++){
				if (crc_reg & 0x01){
					crc_reg = (crc_reg >> 1) ^ poly_ref;
				}else{
					crc_reg >>= 1;
				}
			}
		}else{
			crc_reg ^= (*data++ << 8);
			for (i=0;i<8;i++){
				if (crc_reg & 0x8000){
					crc_reg = (crc_reg << 1) ^ crc_type.poly;
				}else{
					crc_reg <<= 1;
				}
			}
		}
	}
	return crc_reg;
}

uint16_t crc16_final_process(uint16_t crc_reg,CRC16_TYPE crc_type){
	if(crc_type.refin ^ crc_type.refout){
		crc_reg = reflect_uint16_t_bits(crc_reg);
	}
	return crc_reg ^ crc_type.xorout;
}

int main(void){
	uint8_t data[] = {0X01,0X06,0X00,0X00,0X00,0X10};
	uint16_t crc_result = 0;
	crc_result = crc16(data,6,crc_16_IBM.init,crc_16_IBM);
	crc_result = crc16_final_process(crc_result,crc_16_IBM);
	printf("crc_16_IBM result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_MAXIM.init,crc_16_MAXIM);
	crc_result = crc16_final_process(crc_result,crc_16_MAXIM);
	printf("crc_16_MAXIM result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_USB.init,crc_16_USB);
	crc_result = crc16_final_process(crc_result,crc_16_USB);
	printf("crc_16_USB result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_MODBUS.init,crc_16_MODBUS);
	crc_result = crc16_final_process(crc_result,crc_16_MODBUS);
	printf("crc_16_MODBUS result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_CCITT.init,crc_16_CCITT);
	crc_result = crc16_final_process(crc_result,crc_16_CCITT);
	printf("crc_16_CCITT result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_CCITT_FALSE.init,crc_16_CCITT_FALSE);
	crc_result = crc16_final_process(crc_result,crc_16_CCITT_FALSE);
	printf("crc_16_CCITT_FALSE result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_X25.init,crc_16_X25);
	crc_result = crc16_final_process(crc_result,crc_16_X25);
	printf("crc_16_X25 result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_XMODEM.init,crc_16_XMODEM);
	crc_result = crc16_final_process(crc_result,crc_16_XMODEM);
	printf("crc_16_XMODEM result = %x\n",crc_result);
	
	crc_result = crc16(data,6,crc_16_DNP.init,crc_16_DNP);
	crc_result = crc16_final_process(crc_result,crc_16_DNP);
	printf("crc_16_DNP result = %x\n",crc_result);
	return 0;
}