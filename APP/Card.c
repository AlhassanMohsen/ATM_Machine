/*
 * Card.c
 *
 * Created: 1/28/2022 2:29:22 PM
 *  Author: Khaled Ali
 */ 

#include "Card.h"

STATE u8State;
Card card;
void Card_App(void){
	
	EEPROM_Init();
	uint8_t pattern;
	uint8_t status = EEPROM_u8RandonReadFrom(0, 0, &pattern);
	if(pattern != UNIQUE_PATTERN){
		u8State = PROGRAMMING;
	}
	else{
		u8State = USER;
		EEPROM_u8ReadStringFrom(0, 1, card.NAME);
		EEPROM_u8ReadStringFrom(0, 11, card.PAN);
		EEPROM_u8ReadStringFrom(0, 21, card.PIN);
	}
	while(1){
		switch(u8State){
			case PROGRAMMING:
			//Enter Programming mode
			//UART_u8SendString("Enter Card Holder Name: ");
			//UART_u8RecieveString(card.NAME, 9);
			//UART_u8SendString("Enter Primary Account Number: ");
			//UART_u8RecieveString(card.PAN, 9);
			//UART_u8SendString("Enter PIN: ");
			//UART_u8RecieveString(card.PIN, 4);
			EEPROM_u8WriteStringTo(0, 1, card.NAME);
			EEPROM_u8WriteStringTo(0, 11, card.PAN);
			EEPROM_u8WriteStringTo(0, 21, card.PIN);
			u8State = USER;
			break;
			case USER:
			//Check if user Entered ADMIN word
			//If it was entered go to PROGRAMMING Mode
			//if not check if Slave is selected
			//if slave selected
			//SPI_u8SendString(card.PAN);
			//SPI_u8SendString(card.PIN);
			break;
			default:
			break;
		}	
	}
}