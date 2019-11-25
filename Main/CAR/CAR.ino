/**********************************************************
* UNIVERSIDADE FEDERAL DE PERNAMBUCO - UFPE
* CENTRO DE INFORMARICA - CIN
* INTRODUCAO A PROGRAMACAO COM GALILEO - IF668 EC
********************************************************/

#include "Ultrasonic.h"
#define echoPin 10 //Pino 10 recebe o pulso do echo
#define trigPin 8 //Pino 9 envia o pulso para gerar o echo

//ULTRASONIC
//iniciando a função e passando os pinos
  Ultrasonic ultrasonic(trigPin,echoPin);
  int parou = 0;

//OPTICO
 int inPin = 2; //pino de entrada no sensor
 int valor = 0; //Inteiro que armazena o valor lido

//MOTOR
//Definicoes pinos ligados a entrada da Ponte H
  int Motor_E1 = 6;
  int Motor_E2 = 7;
  int Motor_EV = 9;
  int Motor_DV = 3;
  int Motor_D2 = 4;
  int Motor_D1 = 5;
  

void setup()
{
  /*//ULTRASONIC
   pinMode(echoPin, INPUT); // define o pino 10 como entrada (recebe)
   pinMode(trigPin, OUTPUT); // define o pino 9 como saida (envia)
   Serial.begin(9600);
   //OPTICO
   Serial.begin(9600); //inicializando a porta serial
   pinMode(inPin, INPUT); //colocando a porta 2 como entrada*/

   //MOTOR
   //Define os pinos como saida
   pinMode(Motor_E1, OUTPUT);//ESQUERDDA
   pinMode(Motor_E2, OUTPUT);
   pinMode(Motor_EV, OUTPUT);//VELOCIDADE E
   pinMode(Motor_DV, OUTPUT);//VELOCIDADE D
   pinMode(Motor_D2, OUTPUT);//DIREITA
   pinMode(Motor_D1, OUTPUT);
}
 
void loop()
{
    //Colocando o motor na velocidade máxima.
     digitalWrite(Motor_DV, HIGH);
     digitalWrite(Motor_EV, HIGH);
     /*// int distancia = (ultrasonic.Ranging(CM)); 
    // Serial.println(distancia);
      digitalWrite(Motor_E1, HIGH);
     // digitalWrite(Motor_E2, LOW);
      digitalWrite(Motor_D1, HIGH);
      //digitalWrite(Motor_E2, HIGH);*/
 //OPTICO
  valor = digitalRead(inPin);//realizando a leitura no sensor optico
    if (valor == HIGH)
    {
       Serial.println("Branco"); //caso o valor seja alto - cor branca
        analogWrite(Motor_E1, 100);
        analogWrite(Motor_D1, 0);

    } 
    else
    {
       Serial.println("Preto"); //caso o valor lido seja baixo - cor preta
        analogWrite(Motor_E1, 100);
        analogWrite(Motor_D1, 100);

    }
  
  /*  digitalWrite(trigPin, HIGH);
    valor = digitalRead(inPin); //LEITURA OPTICO
   
     if(distancia<10){
     digitalWrite(Motor_E1, HIGH);
     digitalWrite(Motor_D1, HIGH);
     }
    if(distancia>10){
      digitalWrite(Motor_E1, HIGH);
      digitalWrite(Motor_E2, HIGH);
      digitalWrite(Motor_D1, HIGH);
      digitalWrite(Motor_D2, HIGH);
      }
     
     
      */

}
