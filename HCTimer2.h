/* FILE:    HCTimer2.h
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


#ifndef HCTimer2_h
#define HCTimer2_h

#include "Arduino.h"


/* Timer 2 clock prescalling values */
enum HCT2PreScaller
{
	T2_CLK_DIV_0    = 1,
	T2_CLK_DIV_8    = 2,
	T2_CLK_DIV_32   = 3,
	T2_CLK_DIV_64   = 4,
    T2_CLK_DIV_128  = 5,
    T2_CLK_DIV_256  = 6,
    T2_CLK_DIV_1024 = 7
};


/* Initialisation function which reprograms timer 2 */
void HCTimer2Init(byte prescaler, byte compare);

/* This function is called each time the timer 2 interrupt is triggered. Use this
  function within your own program and place any code within it that you require
  to be run each time the timer interrupt is triggered.*/
void HCTimer2(void);


#endif