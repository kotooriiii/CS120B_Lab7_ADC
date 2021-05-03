/*	Author: Carlos Miranda cmira039@ucr.edu
 *  Partner(s) Name: n/a
 *	Lab Section: 23
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: 
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
	
	unsigned char counter = 0;
	for(unsigned short i = 0; i < MAX; i += MAX/8)
	{
		if(digitalValue <= i)
		{
			switch(counter)
			{
				case 0x00:
				PORTB = 0x00;
				break;

				case 0x01:
				PORTB = 0x01;
				break;

				case 0x02:
				PORTB = 0x03;
				break;

				case 0x03:
				PORTB = 0x07;
				break;

				case 0x04:
				PORTB = 0x0F;
				break;

				case 0x05:
				PORTB = 0x1F;
				break;

				case 0x06:
				PORTB = 0x3F;
				break;

				case 0x07:
				PORTB = 0x7F;
				break;

				case 0x08:
				PORTB = 0xFF;
				break;

				default:
				PORTB = counter; //error case
				break;
			}
		
			break;
		}
		counter++;
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
	



