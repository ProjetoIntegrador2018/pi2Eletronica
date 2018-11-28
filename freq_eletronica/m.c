#include<stdio.h>
#include<time.h>
#include<wiringPi.h>


#define READY_FREQ 0
#define DIR_CAR 28
#define STEP_CAR 29
#define DIR_MI 27
#define STEP_MI 11
#define DIR_SI 5
#define STEP_SI 4
#define DIR_SOL 1
#define STEP_SOL 24
#define DIR_RE 23
#define STEP_RE 22
#define DIR_LA 21
#define STEP_LA 3
#define DIR_MIZ 2
#define STEP_MIZ 0
#define CW 1
#define CCW 0
#define SPR 200

int veq_aux_dir[6] = [1,2,3,4,5,6];
// [DIR_MIZ, DIR_SI, DIR_SOL, DIR_RE, DIR_LA, DIR_MI];
//int veq_aux_step[6]= [STEP_MIZ, STEP_SI, STEP_SOL, STEP_RE, STEP_LA, STEP_MI];


void tensionar_corda(){
  int i,j, atraso;
  atraso = 30;
  for(j = 0; j < 6;j++){
    for(i = 0; i < 400; i++){
      digitalWrite(veq_aux_dir[j], CCW);
      digitalWrite(0, HIGH);
      delay(atraso);
      digitalWrite(0, LOW);
      delay(atraso);
    }
  }
};
/*
void afrouxar_corda(){

  int i,j, dir;
  for(j = 0; j < 6;j++){
    for(i = 0; i < 400; i++){
      digitalWrite(veq_aux[j], CW);
      digitalWrite(STEP, HIGH);
      delay(atraso);
      digitalWrite(STEP, LOW);
      delay(atraso);
    }
  }
}
void afrouxar_corda_esp(int dir, int step){

  int  dir, step;
  dir = DIR_SI;
  step = STEP_SI;
    for(i = 0; i < 51; i++){
      digitalWrite(step, HIGH);
      delay(atraso);
      digitalWrite(step, LOW);
      delay(atraso);
    }
}
*/
int main(void){

        int i,j;
        wiringPiSetup();
        for(j = 0; j < 6; j++){
          pinMode(veq_aux_dir[j], OUTPUT);
          //pinMode(veq_aux_step[j], OUTPUT);

        }


        int step_count = SPR;
        double atraso_carro = 1;

//      digitalWrite(DIR, CCW);
        //tensionar_corda();
        tensionar_corda();
/*
        for(i = 0; i < qtde; i++){
        digitalWrite(STEP, HIGH);
        delay(atraso);
        digitalWrite(STEP, LOW);
        delay(atraso);

        }
*/
        return 0;
}

