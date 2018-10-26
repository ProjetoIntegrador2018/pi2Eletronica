
#include<stdio.h>
#include<time.h>
#include<wiringPi.h>


#define DIR 28
#define STEP 29
#define CW 1
#define CCW 0
#define SPR 200

int main(void){
	wiringPiSetup();

	pinMode(DIR, OUTPUT);
	pinMode(STEP, OUTPUT);

	int step_count = SPR;
	double atraso = 1;

	int i = 0;
	digitalWrite(DIR, CCW);
	for(i = 0; i < 201; i++){
		digitalWrite(STEP, HIGH);
		delay(atraso);
		digitalWrite(STEP, LOW);
		delay(atraso);


	}


	return 0;
}
