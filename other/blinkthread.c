/*
 * blink-thread.c:
 *	Standard "blink" program in wiringPi. Blinks an LED connected
 *	to the first GPIO pin.
 *
 * Copyright (c) 2012-2013 Gordon Henderson. <projects@drogon.net>
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define	LED	1
#define READY   0

clock_t ti,tf;

int count = 0;
double freq = 0, timesecond;



PI_THREAD (blinky)
{
  int i = 0, state = 0;
  count  = 0;
  for (;;)
  {
    ti = clock();
    i = digitalRead (READY) ;	
      if(i != state){
	state = i;
	i = 0;
 	count++;
	if(count >= 12){
	  tf = clock();
	  timesecond = (double) (tf - ti)/ CLOCKS_PER_SEC;
	  freq = ((double)count/(double)(timesecond))/(2.00 * 1000000);  //MULTIPLICAR POR 2 CASO O CROSSING  SEJA NA DESCIDA E NA SUBIDA
	  count = 0;
        }
      }
   }
}

int main (void)
{
  printf ("Raspberry Pi blink\n") ;

  wiringPiSetup () ;
  pinMode (LED, OUTPUT) ;
  piThreadCreate (blinky) ;

  for (;;)
  {
    printf ("Hello, world\n") ;
    //delay (600) ;
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
    printf("Count = %d\n",count);
    printf("timesecond = %.2f\n", timesecond);
    printf("Frequencia de %.2f HZ\n", freq);
  }

  return 0 ;
}
