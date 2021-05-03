/*	Author: Carlos Miranda cmira039@ucr.edu
 *  Partner(s) Name: n/a
 *	Lab Section: 23
 *	Assignment: Lab #7  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://youtu.be/f6SeNDOnru0
 */
 
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

const unsigned short MAX = 0x013F; //319

/*
	ADC start
*/

void ADC_init()
{
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

/*
	ADC end
*/

void tickCounter()
{
	unsigned short digitalValue = ADC;
	
	if(ADC >= MAX/2)
	{
		PORTB = 0x01;

	}
	else
	{
		PORTB = 0x00;

	}
}

int main(void) 
{
	
	//Inputs
	DDRA = 0x00; PORTA = 0xFF; 
	
	//Outputs
	DDRB = 0xFF; PORTB = 0x00; 
	DDRD = 0xFF; PORTD = 0x00; 
	
	ADC_init();
	
	while(1) 
	{
		tickCounter();
	}
	return 1;
}
	



