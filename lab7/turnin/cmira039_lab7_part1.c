/*	Author: Carlos Miranda cmira039@ucr.edu
 *  Partner(s) Name: n/a
 *	Lab Section: 23
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://youtu.be/ik9TRfr6o0U
 */
 
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

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
	
	unsigned char tempB = (char) digitalValue;
	unsigned char tempD = (char) (digitalValue >> 8);
	tempD = tempD & 0x03;
	
	PORTB = tempB;
	PORTD = tempD;
	
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
	



