/*
 * Card.h
 *
 * Created: 1/28/2022 2:29:33 PM
 *  Author: Khaled Ali
 */ 


#ifndef CARD_H_
#define CARD_H_

#include "../ECUAL/EEPROM/EEPROM_interface.h"


#define  UNIQUE_PATTERN 0x10101010


typedef struct{
	uint8_t name[9];
	uint8_t PAN[9];
	uint8_t PIN[4];
	}Card;

typedef enum{
	PROGRAMMING,
	USER
	}STATE;
void Card_App(void);

#endif /* CARD_H_ */