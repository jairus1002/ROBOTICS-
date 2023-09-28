                                     //settig up for the servos and photoresistors 
#include <Servo.h>

Servo myservo1, myservo2,myservo3;
int  LDR1=    A0;
int  LDR2 =   A1;
int  LDR3  =  A2 ; 
int  LDR4  =  A3;
          int  SENSOR1 = 0;  
          int  SENSOR2 = 0; 
          int  SENSOR3 = 0;
          int  SENSOR4 = 0;
int max1_2=0;  
int max3_4=0;    
int max_x1_x2=0;

int   SERVO1 = 80;
int   SERVO2 =  0;
 

                                  
                                
void setup() {
       //setting up for the servos 
                                   
  myservo1.attach(7);
  myservo2.attach(8);
                                  
                                  
                                  
  Serial.begin(9600);
                                   // Setting the initial positions of the  servos 
  myservo1.write(SERVO1);
  myservo2.write(130);                                                           
}


void loop() {
                                   //the set up for the ldrs 
  SENSOR1 = analogRead(LDR1) / 100;
  SENSOR2 = analogRead(LDR2) / 100;
  SENSOR3 = analogRead(LDR3) / 100;
  SENSOR4 = analogRead(LDR4) / 100;
  Serial.print("the value of SENSOR1 =");
         Serial.println(SENSOR1);
  Serial.print("the value of SENSOR2 =");
         Serial.println(SENSOR2);
  Serial.print("the value of SENSOR3 =");
         Serial.println(SENSOR3);
  Serial.print("the value of SENSOR4 =");
         Serial.println(SENSOR4);
   
                                    //Definition of variables 
  max1_2 = max(SENSOR1, SENSOR2);
  max3_4 = max(SENSOR3, SENSOR4);
  max_x1_x2 = max(max1_2, max3_4);
  Serial.print("value max_x1_x2=");
  Serial.println(max_x1_x2);
  
 delay(1000);
 
  if(SENSOR1<max_x1_x2 && SENSOR2<max_x1_x2)
  {
    if(SERVO1<140)
      SERVO1+1;
    myservo1.write(SERVO1);
    Serial.print("the SERVO1 POSITION =");
    Serial.println(SERVO1);
    delay(100);
    
  }
  if(SENSOR3<max_x1_x2 && SENSOR4<max_x1_x2)
  {
    if(SERVO1>0)
      SERVO1-=10;
    myservo1.write(SENSOR1);
    Serial.print("the SERVO1 POSITION =");
    Serial.println(SERVO1);
    delay(100);
  }

  if(SENSOR2<max_x1_x2 && SENSOR3<max_x1_x2)
  {
    if(SERVO2<180)
      SERVO2+=10;
    myservo2.write(SERVO2);
    Serial.print("the SERVO2 POSITION =");
    Serial.println(SERVO2);
  }
  if(SENSOR1<max_x1_x2&& SENSOR4<max_x1_x2)
  {
    if(SERVO2>0)
      SERVO2-=10;
    myservo2.write(SERVO2);
    Serial.print("the SERVO2 POSITION =");
    Serial.println(SERVO2);
  }
  delay(10);
}
 
