#include <string.h>
#include <stdio.h>
#include <Servo.h>
#include <Arduino.h>

// Pin definitions
#define STEPPIN 2 // Stepper Step Pin
#define DIRPIN 5  // Stepper Direction Pin
#define enA 6 // enable pin for arming motor
//#define enB 11 // enable pin for latch motor
#define in1 8 // arming motor
#define in2 7 // arming motor
//#define in3 12 // latch motor
//#define in4 13 // latch motor

// Variable definitions
String data;
String xStr;
String yStr;
Servo myServo;

int xCoord;
int yCoord;
int pwmOutput;
int pos;
int onTime;

int state;

// Function declarations
void CoordExtract();
void rotationCalc(int x, String dir);
void powerCalc(int y);
void motorOn(int pin1, int pin2, String dir);
void motorOff(int pin1, int pin2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(1);

  pinMode(STEPPIN, OUTPUT);
  pinMode(DIRPIN, OUTPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  /*pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);*/

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  /*digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);*/

  pwmOutput = 125;
  analogWrite(enA, 150); // Send PWM signal to L298N Enable pin
  //analogWrite(enB, 175);

  myServo.attach(10);
  myServo.write(45);

  state = 0; // Begin FSM at state 0
}

void loop() {
  // put your main code here, to run repeatedly:
  
  switch(state) {
    case 0: // Serial Communication with Python Program
      while(!Serial.available());
      CoordExtract();
        
      state = 1;
    break;

    case 1: // Stepper Motor Rotation
      rotationCalc(xCoord, "ccw");
      delay(500);

      state = 2;
    break;

    case 2: // Arming Motor Operation
      pinMode(STEPPIN, INPUT);
      pinMode(DIRPIN, INPUT);
      powerCalc(yCoord);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      delay(20);
      delay(onTime);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      delay(500);
      pinMode(STEPPIN, OUTPUT);
      pinMode(DIRPIN, OUTPUT);  
      delay(50);

      state = 3;
    break;

    case 3: // Launch Operation
      // Servo Reset
      for(pos = 40; pos >= 0; pos -= 1){
        myServo.write(pos);
        delay(15);
      }
      delay(1000);

      // Latch Motor Pull
      /*motorOn(in3, in4, "ccw");
      delay(4000);
      motorOff(in3, in4);
      delay(500);*/

      state = 4;
    break;

    case 4: // Reset Operation
      // Servo Reset
      for(pos = 0; pos <= 40; pos += 1){
        myServo.write(pos);
        delay(15);
      }
      delay(500);

      // Latch Motor Reset
      /*motorOn(in3, in4, "cw");
      delay(200);
      motorOff(in3, in4);
      delay(500);*/

      // Stepper Reset
      rotationCalc(xCoord, "cw");
      delay(500);

      state = 0;
    break;

    default: 0;
  }
  
}

void CoordExtract(){
  data = Serial.readString(); // Reads data from Serial Comms

  xStr = data[0]; // Extracts x coordinate
  xCoord = xStr.toInt();  // Converts into integer

  yStr = data[2]; // Extracts y coordinate
  yCoord = yStr.toInt(); // Converts into integer
}

void rotationCalc(int x, String dir){
  // 5 zones within 90 degrees
  // 1:2 gear ratio
  // each level is 18 degrees of rotation of big gear
  // 36 degrees of small gear per level
  //int steps = 50 + x*35;

  /*if (dir == "cw"){
    digitalWrite(DIRPIN, HIGH);
    steps = steps - 65;
  }
  else if (dir == "ccw"){
    digitalWrite(DIRPIN, LOW);
  }
  // xCoord multiplied with 36 degrees // x bcs xCoord starts at 0

  for(int i = 0; i <= steps; i++){
    digitalWrite(STEPPIN, HIGH);
    delayMicroseconds(3500);
    digitalWrite(STEPPIN, LOW);
    delayMicroseconds(3500);
  }
  delay(1000);*/

  int steps;
  if (dir == "cw"){
    digitalWrite(DIRPIN, HIGH);
    if(xCoord == 0){
      steps = 18;
    }
    else if (xCoord == 1){
      steps = 47;
    }
    else if (xCoord == 2){
      steps = 105;
    }
    else if (xCoord == 3){
      steps = 130;
    }
    else if (xCoord == 4){
      steps = 158;
    }
  }
  else if (dir == "ccw"){
    digitalWrite(DIRPIN, LOW);
    if(xCoord == 0){
      steps = 27;
    }
    else if (xCoord == 1){
      steps = 63;
    }
    else if (xCoord == 2){
      steps = 158;
    }
    else if (xCoord == 3){
      steps = 220;
    }
    else if (xCoord == 4){
      steps = 280;
    }
  }

  for(int i = 0; i <= steps; i++){
    digitalWrite(STEPPIN, HIGH);
    delayMicroseconds(3500);
    digitalWrite(STEPPIN, LOW);
    delayMicroseconds(3500);
  }
  delay(1000);
}

void motorOn(int pin1, int pin2, String dir){
  if (dir == "cw"){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }
  else if (dir == "ccw"){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  }
}

void motorOff(int pin1, int pin2){
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void powerCalc(int y){
  // 3 different power levels
  // 500 ms delay for each power level
  if(yCoord == 0){
    onTime = 1000 + 3800;
  }
  else if(yCoord == 1){
    onTime = 1000 + 2800;
  }
  else if(yCoord == 2){
    onTime = 1000 + 1800;
  }
}
