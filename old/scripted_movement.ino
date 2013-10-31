#include <Servo.h>

///////////////////////////////////////////////////
//                PINS                           //
///////////////////////////////////////////////////

// Pololu Pins
int MOTOR = 3;
int INB = 4;
int INA = 7;
int BWD = 11;
int FWD = 12;
int INDICATOR_LED = 13;
int MOTOR_SPEED_POT = A5;

// Arm Servos
int LARM_PIN = 6;
int RARM_PIN = 9;
int LARM_POT = A4;
int RARM_POT = A3;

///////////////////////////////////////////////////
//               GLOBALS                         //
///////////////////////////////////////////////////

Servo larm;
Servo rarm;

void move_left_arm(int angle){
  larm.write(angle);
}

void move_right_arm(int angle){
  rarm.write(angle);
}

void close_both_arms(void){
  move_left_arm(0);
  move_right_arm(0);
}

void open_both_arms(void){
  move_left_arm(180);
  move_right_arm(180);
}

void open_body(int delay_time){
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  delay(delay_time);
}

void close_body(int delay_time){
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  delay(delay_time);
}

///////////////////////////////////////////////////
//           ARDUINO MAIN                        //
///////////////////////////////////////////////////

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

int angle = 90;

void loop() {
  int delta_left = random(-90, 90);
  int delta_right = random(-90, 90);

  move_left_arm(angle + delta_left);
  move_right_arm(angle + delta_right);

  delay(500);
}