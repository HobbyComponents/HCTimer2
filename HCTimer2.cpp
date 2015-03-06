/* FILE:    HCTimer2.cpp
   DATE:    14/03/13
   VERSION: 0.1

This library reprograms timer 2 for use as a timer interrupt for executing code
at regular intervals. Please see the included example program for information on
how to use this library.

This library has been written as a set of function calls rather than the standard
way of using a class because the initialisation function needs to be executed after
or within the setup() function, not before.


You may copy, alter and reuse this code in any way you like but please leave
reference to hobbycomponents.com in your comments. This software may not be
used directly for the purpose of selling products that directly compete with
Hobby Components Ltd's own range of products.


THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS LTD MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS LTD SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.
*/


#include "Arduino.h"
#include "HCTimer2.h"

#include <avr/io.h>
#include <avr/interrupt.h>


void HCTimer2Init(byte prescaler, byte compare)
{
	/* Turn off interrupts whilst we setup the timer */
	cli();
	/* Set timer mode to clear timer on compare match (mode 2)*/
	TCCR2A = (1<<WGM21);

	/* Set the prescaler */
	TCCR2B = prescaler;

	/* Clear timer 2 counter */
	TCNT2 = 0;

	/* Set the compare match register */
	OCR2A = compare;

	/* Enable timer 2 interrupt on compare match */
	TIMSK2 = (1<<OCIE2A);

  	/* Turn interrupts back on */
  	sei();


}


/* Interrupt service routine for Timer 2 compare match */
ISR(TIMER2_COMPA_vect)
{

   HCTimer2();

}

