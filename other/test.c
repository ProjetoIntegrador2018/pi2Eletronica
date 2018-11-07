#include <wiringPi.h>
#include <stdio.h>

int main(void){
	int count;
	count = 0;
	wiringPiSetup();
	pinMode(1, INPUT);
	printf("olaaaa!\n");
	while(TRUE){
		if(digitalRead(1) == LOW){
			count++;
			printf("%d\n", count);
			if(count >= 10){
				count = 0;
			}
		}else{
			printf("nao realizou-se a contagem\n");
		}
	}
	return 0;
}
