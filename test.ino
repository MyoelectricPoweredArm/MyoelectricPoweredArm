#include <Servo.h>
Servo servoQ;  // create servo object to control a servo
Servo servoW;
Servo servoE;
Servo servoR;
Servo servoT;
// twelve servo objects can be created on most boards
int posQ = 0, posW = 0, posE = 0, posR = 0, posT = 0;    // variable to store the servo position
void setup() {
  Serial.begin(9600);
  
  servoQ.attach(11);
  servoW.attach(10);
  servoE.attach(9);
  servoR.attach(6);
  servoT.attach(5); // attaches the servo on pin _ to the servo object
}
void loop() {
  
    while (Serial.available()== 0)//wait for user to enter any value to run servo
    {
    }
    char input = Serial.read();
    if(input == 'q')
    {
      Serial.print("HI");
      if(posQ <= 30){
        Serial.print("POS 0");
        for(posQ = 0; posQ <= 60; posQ += 1){
          servoQ.write(posQ);
          delay(15);
        }
      }else{
        for(posQ = 60; posQ >= 0; posQ -= 1){
          servoQ.write(posQ);
          delay(15);
        }
      }
      
    }else if(input == 'w'){
      if(posW <= 20){
        for(posW = 0; posW <= 40; posW += 1){
          servoW.write(posW);
          delay(15);
        }
      }else{
        for(posW = 40; posW >= 0; posW -= 1){
          servoW.write(posW);
          delay(15);
        }
      }
      
    }else if(input == 'e'){
      if(posE <= 30){
        for(posE = 0; posE <= 60; posE += 1){
          servoE.write(posE);
          delay(15);
        }
      }else{
        for(posE = 60; posE >= 0; posE -= 1){
          servoE.write(posE); 
          delay(15);
        }
      }
      
    }else if(input == 'r'){
      if(posR <= 47.5){
        for(posR = 30; posR <= 65; posR += 1){
          servoR.write(posR);
          delay(15);
        }
      }else{
        for(posR = 65; posR >= 30; posR -= 1){
          servoR.write(posR); 
          delay(15);
        }
      }
    }else if(input == 't'){
      if(posT <= 30){
        for(posT = 0; posT <= 60; posT += 1){
          servoT.write(posT);
          delay(15);
        }
      }else{
        for(posT = 60; posT >= 0; posT -= 1){
          servoT.write(posT);
          delay(15); 
        }
      }
     
    }else{
      
    }
    delay(1000);
    while (Serial.available() > 0) Serial.read();
}