/*
 * myeeprom.h
 *
 *  Created on: Apr 2, 2024
 *      Author: sanket
 */

#ifndef MYEEPROM_H_
#define MYEEPROM_H_

#include "myi2c.h"

#define EEPROM_W		0xA0
#define EEPROM_R		0xA1

void EEPROM_Init(void);
void EEPROM_Write(uint16_t addr, uint8_t byte[], uint8_t n);
void EEPROM_Read(uint16_t addr, uint8_t byte[], uint8_t n);

#endif /* MYEEPROM_H_ */
