#include<Servo.h>
Servo myservo;
int i;
//declaration of motor pin1
int EN1=5;
int IN1=4;
//declaration of motor pin2
int EN2=6;
int IN3=7;
//declaration of IR pins.
int R;
int C;
int L;
//declaration of the speed of motors keeping them constants 
int a=175;
int b=0;
//ultrasonic sensor set up
int trigpin=6;
int echopin=4;
float duration ,distance;
int count=0;

 
void setup() {
                       //servo attahing
  myservo.attach(9);
                       //servo writting position 
  myservo.write(90);
                       //baud rate
Serial.begin(9600);
                       //motor1
pinMode(EN1,OUTPUT);
pinMode(IN1,OUTPUT);

                      //motor2
pinMode(EN2,OUTPUT);
pinMode(IN3,OUTPUT);

                     //ultrasonic
pinMode (trigpin ,OUTPUT );
pinMode (echopin ,INPUT );
Serial .println ("the setup is complete ");

}
                    // moving forward
void moveforward(){
 analogWrite(EN1,a);
digitalWrite(IN1,HIGH);
analogWrite (EN2,a);
digitalWrite(IN3,HIGH);
}
                     //stopping
void stopp(){
analogWrite(EN1,b);
digitalWrite(IN1,LOW);
analogWrite (EN2,b);
digitalWrite(IN3,LOW);
}
                   // moving left 
int moveleft(){
analogWrite(EN1,b);
digitalWrite(IN1,LOW);
analogWrite (EN2,a);
digitalWrite(IN3,HIGH);
}
                  //moving forward 
int moverigth(){
analogWrite(EN1,a);
digitalWrite(IN1,HIGH);
analogWrite (EN2,b);
digitalWrite(IN3,LOW);
}
                 //reverse 
void reverse() {
  analogWrite(EN1,a);
digitalWrite(IN1,LOW);
analogWrite (EN2,a);
digitalWrite(IN3,LOW);
}
               //ir sensor
void counter() {
 C = digitalRead(11);
  R = digitalRead(12);
  L = digitalRead(8);
  Serial.print("Right - ");
  Serial.println(R);
  Serial.print("Center - ");
  Serial.println(C);
  Serial.print("Left - ");
  Serial.println(L);
  Serial.println();

  if(L==1&&C==0&&R==1){
    moveforward();
    
  }
   else if (L==0&&C==1&&R==1) {
    moverigth();
  }
   else if (L==1&&C==1&&R==0) {
    moveleft();
  }
   else if(L==0&&C==0&&R==0) {
    count++;
  }
  
}
               //servo looking rigth 
  int lookrigth(){
myservo.write(10);
delay(1000);
digitalWrite (trigpin ,LOW );
delayMicroseconds(4);
digitalWrite (trigpin ,HIGH );
delayMicroseconds(100);

digitalWrite (trigpin,HIGH);

duration=pulseIn (echopin ,HIGH );

distance =(duration *.0343)/2;

Serial .println(distance);
delay (1000);
 myservo.write(90);
}
                 //servo looking left
int lookleft(){
  myservo.write(180);
  delay(1000);
   digitalWrite (trigpin ,LOW );
delayMicroseconds(4);
digitalWrite (trigpin ,HIGH );
delayMicroseconds(100);

digitalWrite (trigpin,HIGH);

duration=pulseIn (echopin ,HIGH );

distance =(duration *.0343)/2;

Serial .println(distance);
delay (100);
  myservo.write(90);
}


//ultrasonic sensor code 1
void ultrasonic1(){
  digitalWrite (trigpin ,LOW );
delayMicroseconds(4);
digitalWrite (trigpin ,HIGH );
delayMicroseconds(100);

digitalWrite (trigpin,HIGH);

duration=pulseIn (echopin ,HIGH );

distance =(duration *.0343)/2;

Serial .println(distance);
delay (1000);

}
                             //ultrasonic sensor code number 2
  int distance_test(){
  digitalWrite (trigpin ,LOW );
delayMicroseconds(4);
digitalWrite (trigpin ,HIGH );
delayMicroseconds(100);

digitalWrite (trigpin,HIGH);

duration=pulseIn (echopin ,HIGH );

distance =(duration *.0343)/2;

Serial .println(distance);
delay (1000);
}

                         //task two in action 
void task2(){
int distanceL=0;
int distanceR=0;
  Serial.println(distance_test());

     if(distance_test() < 20)
  {   
  
      stopp();
       delay(1000);
      distanceR = lookrigth();
      delay(500);
      distanceL = lookleft();
      delay(300);

      if(distanceR >= distanceL)
      {
        Serial.println("turn right");
        delay(100);
moverigth();
counter();
        delay(500);
      }
            else
      {
       Serial.println("turn left"); 
       delay(100);
 moveleft();
 counter();
        delay(500);
      }
      }
      else{
        counter();
        moveforward();
      }
  }

void loop() {
  //delay(100);
  counter();
// moveforward();
            /*moveforward();
 if(distance_test() < 20)
  {

                 stopp();
                    delay(200);
                  moveleft(); 
                     delay(100);
                  counter();
                     delay(1000);
      moveforward();
     
      delay(500);
    
  

delay(1000);
task2();

  }*/
 

}
