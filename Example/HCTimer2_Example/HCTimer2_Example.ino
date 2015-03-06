/*  FILE:    HCTimer2_Example
    DATE:    14/03/13
    VERSION: 0.1
  
    
This is an example of how to use the Hobby Components timer 2 interrupt library. This 
library reprograms timer 2 for use as a timer interrupt for executing code at regular 
intervals. 
  
To initlalise this libray you will need call HCTimer2Init(prescaler, compare) once with 
the following parameters:
      
The prescaller parameter sets the timer 2 clock prescaler. Valid values are     

     T2_CLK_DIV_0
     T2_CLK_DIV_8
     T2_CLK_DIV_32
     T2_CLK_DIV_64
     T2_CLK_DIV_128
     T2_CLK_DIV_256
     T2_CLK_DIV_1024
     
The compare parameter sets the value timer 2 compares its counter to before triggereing 
an interrupt. This is a 8 bit value from 0 to 255.
     
The two parameters can be used to alter the frequency of how often the timer interrupt
triggers and therefore runs your code. The formula to calculate the timer interrupt time
in seconds is: ((compare + 1) * prescaler) / 16000000MHz

To execute code each time the interrupt triggers, add the function HCTimer2() to your
program and place any code you wish to execute when the interrupt triggers within it. 
Make sure that any code you place within this function is executed before the next 
interrupt is due to be triggered. You must also not place any code inside this function 
that requres the use of other interrupts such as the serial print functions.



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

/* Include the HCTimer2 library */
#include <HCTimer2.h>

int Counter = 0;

void setup()
{
  /* Set the DIO for pin 13 (LED L) to an output */
  pinMode(13, OUTPUT);
  
  /* Initiliase the HCTimer2 library with a 15.616mS interval */  
  HCTimer2Init(T2_CLK_DIV_1024, 243);
}


void loop()
{
  /* Place your normal code in here */
}


/* Place code inside this fuction that you would like to be executed 
   whenever the timer interrupt is triggered */
void HCTimer2()
{
  Counter++;

  /* Toggle DIO 13 (LED L) once every 64 * 15.616mS = approx 1 second */
  if (Counter == 64)
    {
      digitalWrite(13,!digitalRead(13));
      Counter = 0;
    }
}
