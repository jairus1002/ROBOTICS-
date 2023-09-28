
 #include <Servo.h>
 
Servo base ,  shoulder  ,elbow, head, wrist,gripper;


int basepin =A1;
int shoulderpin =A2;
int elbowpin =A3;
int headpin =A4;
int wristpin =A5;
int gripperpin =A6;


int baseValue =0;
int shoulderValue=0;
int elbowValue =0;
int headValue =0;
int wristValue =0;
int gripperValue =0;



void setup() {
  // put your setup code here, to run once:
  Serial.print(9600);
base.attach(22);
shoulder.attach(24);
elbow.attach(26);
head.attach(28);
wrist.attach(30);
gripper.attach(32);
}

void loop() {
  // put your main code here, to run repeatedly:
baseValue =   map(analogRead(basepin),0, 1023, 0, 180);
shoulderValue=map(analogRead(shoulderpin ),0, 1023,0,180);
elbowValue=   map(analogRead(elbowpin),0, 1023,0,180);
headValue=    map(analogRead(headpin),0, 1023,0,180);
wristValue=   map(analogRead(wristpin),0, 1023,0,180);
gripperValue= map(analogRead(gripperpin),0, 1023,0,180);

Serial.print("position of the base=");
Serial.println(baseValue);
Serial.print("position of the base=");
Serial.println(shoulderValue);
Serial.print("position of the base=");
Serial.println(elbowValue);
Serial.print("position of the base=");
Serial.println(headValue);
Serial.print("position of the base=");
Serial.println(wristValue);
Serial.print("position of the base=");
Serial.println(gripperValue);
delay(1000);

base.write(baseValue);
shoulder.write(shoulderValue);
elbow.write(elbowValue);
head.write(headValue);
wrist.write(wristValue);
gripper.write(gripperValue);
delay(50);
}
