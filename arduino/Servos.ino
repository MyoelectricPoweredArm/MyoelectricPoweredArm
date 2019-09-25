#include <Servo.h>

// create servo object to control a servo
Servo servoI; //Index finger  
Servo servoM; //Middle finger 
Servo servoR; //Ring finger 
Servo servoP; //Pinky finger 
Servo servoT; //Thumb 
// twelve servo objects can be created on most boards

bool isTest = false; //boolean to determine if test functionality should be enabled

void setup() {
  Serial.begin(9600);
  
  servoI.attach(11);
  servoM.attach(10);
  servoR.attach(9);
  servoP.attach(6);
  servoT.attach(5); // attaches the servo on pin _ to the servo object

  Serial.print("Would you like to enable testing functionality? (enter 'y' or 'n')");
    while (Serial.available()== 0){
      }
    char testInput = Serial.read();
    if(testInput == 'y' || testInput == 'Y'){
      isTest = true;
      Serial.print("\nTest functionality enabled");
    }
    else if(testInput == 'n' || testInput == 'N'){
      isTest = false;
      Serial.print("\nTest functionality disabled");
    }
  
}

void loop() {
    //No testing functionality. Opening and closing hand only
    if(!isTest){ 
      Serial.print("\nenter 'o' to open hand or 'c' to close hand");
      while (Serial.available()== 0)//wait for user to enter any value to run servo
      {
      }

      char input = Serial.read();
      if(input =='o' || input == 'O'){
        Serial.print("\nOpening hand");
        servoI.write(0);
        servoM.write(0);
        servoR.write(0);
        servoP.write(0);
        servoT.write(0);
      }else if(input == 'c' || input == 'C'){
        Serial.print("\nClosing hand");
        servoI.write(90);
        servoM.write(90);
        servoR.write(90);
        servoP.write(90);
        servoT.write(90);
      }
     }
     //Testing functionality. Opening and closing hand, as well as individual fingers
     else if(isTest){ 
      Serial.print("\nenter 'o' to open hand, 'c' to close hand, or 'i', 'm', 'r', 'p', or 't' to move individual fingers");
      //wait for user to enter any value to run servo
      while (Serial.available()== 0){}
      char input = Serial.read();
      if(input =='o' || input == 'O'){
        Serial.print("\nOpening hand");
        servoI.write(0);
        servoM.write(0);
        servoR.write(0);
        servoP.write(0);
        servoT.write(0);
      }else if(input == 'c' || input == 'C'){
        Serial.print("\nClosing hand");
        servoI.write(90);
        servoM.write(90);
        servoR.write(90);
        servoP.write(90);
        servoT.write(90);
      }else if(input == 'i' || input == 'I'){
        if(servoI.read() > 45){
          Serial.print("\nOpening index finger");
          servoI.write(0);
        }else{
          Serial.print("\nClosing index finger");
          servoI.write(90);
        }
      }
      else if(input == 'm' || input == 'M'){
        if(servoM.read() > 45){
          Serial.print("\nOpening middle finger");
          servoM.write(0);
        }else{
          Serial.print("\nClosing middle finger");
          servoM.write(90);
        }
      }
      else if(input == 'r' || input == 'R'){
        if(servoR.read() > 45){
          Serial.print("\nOpening ring finger");
          servoR.write(0);
        }else{
          Serial.print("\nClosing ring finger");
          servoR.write(90);
        }
      }
      else if(input == 'p' || input == 'P'){
        if(servoP.read() > 45){
          Serial.print("\nOpening pinky finger");
          servoP.write(0);
        }else{
          Serial.print("\nClosing pinky finger");
          servoP.write(90);
        }
      }
      else if(input == 't' || input == 'T'){
        if(servoT.read() > 45){
          Serial.print("\nOpening thumb");
          servoT.write(0);
        }else{
          Serial.print("\nClosing thumb");
          servoT.write(90);
        }
      }
     }

    delay(1000);
    while (Serial.available() > 0) Serial.read();
}
