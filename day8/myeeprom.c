/*
 * myeeprom.c
 *
 *  Created on: Apr 2, 2024
 *      Author: sanket
 */
#include "myeeprom.h"

void EEPROM_Init(void)
{
	int ret;
	I2CInit();
	I2CStart();
	ret = I2CIsDeviceReady(EEPROM_W);
	I2CStop();
}

void EEPROM_Write(uint16_t addr, uint8_t byte[], uint8_t n)
{
	uint8_t high = addr >> 8, low = addr & 0xFF;

	I2CStart();
	I2CSendSlaveAddress(EEPROM_W);
	I2CSendData(high);
	I2CSendData(low);
	for(int i=0; i<n; i++)
		I2CSendData(byte[i]);
	I2CStop();
}

void EEPROM_Read(uint16_t addr, uint8_t byte[], uint8_t n)
{
	uint8_t high = addr >> 8, low = addr & 0xFF;
	I2CStart();
	I2CSendSlaveAddress(EEPROM_W);
	I2CSendData(high);
	I2CSendData(low);
	I2CRepeatStart();
	I2CSendSlaveAddress(EEPROM_R);
	for(int i=0; i<n; i++)
		byte[i] = I2CRecvData();
	I2CStop();
}

