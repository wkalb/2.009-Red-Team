#include <Servo.h> 

// Pololu motor controller pins
int MOTOR = 3;
int INB = 4;
int INA = 7;

// Pins for motor controls
int BWD = 11;
int FWD = 12;
int MOTOR_SPEED_POT = A5;
int INDICATOR_LED = 13;

// Arm servos
int LARM_PIN = 6;
int RARM_PIN = 9;

int LARM_POT = A4;
int RARM_POT = A3;

Servo larm;
Servo rarm;

void setup() {
  // Motor controller related outputs
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(INDICATOR_LED, OUTPUT);

  // initialize servos
  larm.attach(LARM_PIN);
  rarm.attach(RARM_PIN);
}

void loop() {
  int motor_val = analogRead(MOTOR_SPEED_POT);
  analogWrite(MOTOR, map(motor_val, 0, 1023, 0, 180));

  // move left arm
  int larm_val = analogRead(LARM_POT);
  larm.write(map(larm_val, 0, 1023, 0, 180));

  // move right arm
  int rarm_val = analogRead(RARM_POT);
  rarm.write(map(rarm_val, 0, 1023, 0, 180));

  // if motor pushbuttons active, move motor
  if(digitalRead(FWD))
  {
   digitalWrite(INA, HIGH);
   digitalWrite(INB, LOW);
   digitalWrite(INDICATOR_LED, HIGH);
  } else if(digitalRead(BWD))
  {
   digitalWrite(INA, LOW);
   digitalWrite(INB, HIGH);
   digitalWrite(INDICATOR_LED, HIGH);
  } else
  {
   digitalWrite(INA, LOW);
   digitalWrite(INB, LOW);
   digitalWrite(INDICATOR_LED, LOW);
  }
 
}