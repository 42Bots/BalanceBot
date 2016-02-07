/*  DC Motor Test 
 *  2 geared DC motors + L298N H-Bridge module
 *  42Bots.com
------------------------------------------------------------------------------------------------
*/

/* Define motor controll inputs */
const int motorRPin1 = 8; // signal pin 1 for the right motor, connect to IN1               
const int motorRPin2 = 7;  // signal pin 2 for the right motor, connect to IN2
const int motorREnable = 5; // enable pin for the right motor (needs to be PWM enabled)

const int motorLPin1 = 4; // signal pin 1 for the left motor, connect to IN3           
const int motorLPin2 = 6; // signal pin 2 for the left motor, connect to IN4
const int motorLEnable = 10; // enable pin for the left motor (needs to be PWM enabled)

// Coefficients to balance motors
const int motorLPower = 100;
const int motorRPower = 100;

// minimum and maximum PWM values for motors
const int motorMin = 60; // minum PWM value where motor has sufficient torque
const int motorMax = 255;

void setup() {
  /* Set up motor controll pins as output */
  pinMode(motorLPin1,OUTPUT);        
  pinMode(motorLPin2,OUTPUT);
  pinMode(motorLEnable,OUTPUT);
  
  pinMode(motorRPin1,OUTPUT);        
  pinMode(motorRPin2,OUTPUT);
  pinMode(motorREnable,OUTPUT);
}

void loop() {
  Drive(200,0);
}

void Drive(int motorRSpeed, int motorLSpeed) {
  if (motorRSpeed > motorMax) {motorRSpeed = motorMax;}
  else if (motorRSpeed < -motorMax) {motorRSpeed = -motorMax;}
  
  if (motorLSpeed > motorMax) {motorLSpeed = motorMax;}
  else if (motorLSpeed < -motorMax) {motorLSpeed = -motorMax;}
  
  if (motorRSpeed >= motorMin) { // right motor forward (using PWM)
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, HIGH);
  } 
  
  else if (motorRSpeed <= -motorMin) {// right motor reverse (using PWM)
     analogWrite(motorREnable, abs(motorRSpeed));
     digitalWrite(motorRPin1, HIGH);
     digitalWrite(motorRPin2, LOW);
  } 
  
  else if (motorRSpeed == 0) { // right motor fast stop
     digitalWrite(motorREnable, HIGH);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, LOW);
  }
  
  if (motorLSpeed >= motorMin) { // left motor forward (using PWM)
     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2, HIGH);
  } 
  
  else if (motorLSpeed <= -motorMin) { // left motor reverse (using PWM)
     analogWrite(motorLEnable, abs(motorLSpeed));
     digitalWrite(motorLPin1, HIGH);
     digitalWrite(motorLPin2, LOW);
  } 
  
    else if (motorLSpeed == 0) { // left motor fast stop
     digitalWrite(motorLEnable, HIGH);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2, LOW);
  }
}




