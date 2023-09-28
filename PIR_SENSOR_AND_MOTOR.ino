
 const int  pirpin =9;  
 const int  motorpin =11;
int switchotate =0;


void setup() {

pinMode (pirpin , OUTPUT);
pinMode (motorpin ,OUTPUT );

 
}

void loop() {
 switchotate = digitalRead(pirpin );
 if (switchotate == HIGH ) {
  // High means there is  a motion detected by the PIR sensor

   digitalWrite(motorpin ,HIGH );

 }

 
  else {

    //low means no motion detected by the PIR sensor

    digitalWrite ( motorpin ,LOW );





    
  
 }
  
  
  
  
  
  
  
  

}
