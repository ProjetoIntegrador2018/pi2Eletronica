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
int start, end, tempo;


PI_THREAD (blinky)
{
  int i = 0, state =0, ultimo;
  count  = 0;
  for (;;)
  {
    start =  millis();
    //ti = clock();
    i = digitalRead (READY) ;	
      if(i == 1){
        delay(60);
	i = 0;
 	count++;
        end = millis(); 
      }if(count >= 30){
        tempo =  start - end;
	printf("tempo = %d\n", tempo);
        freq = count/tempo;
        count = 0;
      }
   }
}

int main (void)
{
  printf ("Raspberry Pi blink\n") ;

  wiringPiSetup () ;
  pinMode (LED, OUTPUT) ;
  pinMode(READY, INPUT);
  piThreadCreate (blinky) ;

  for (;;)
  {
   
    printf("Count = %d\n",count);
    //printf("timesecond = %.2f\n", timesecond);
    printf("Frequencia de %.2f HZ\n", freq);
    delay(1000);
  }

  return 0 ;
}
