#include <Servo.h>
#include <CapacitiveSensor.h>
#include "herobo.h"


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

Sensors sensor;
Servo larm;
Servo rarm;

CapacitiveSensor belly_cap = CapacitiveSensor(2,13);       
// CapacitiveSensor cs_2_4 = CapacitiveSensor(2,4);        
// CapacitiveSensor cs_2_5 = CapacitiveSensor(2,5);

///////////////////////////////////////////////////
//           ARDUINO MAIN                        //
///////////////////////////////////////////////////

void setup() {
  belly_cap.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  // cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
  // cs_2_5.set_CS_AutocaL_Millis(0xFFFFFFFF);

  // Motor controller related outputs
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(INDICATOR_LED, OUTPUT);

  // initialize servos
  larm.attach(LARM_PIN);
  rarm.attach(RARM_PIN);

  Serial.begin(9600);
}

void loop() {
  poll_sensors(&sensor);

  if(sensor.belly){

  }

  if(sensor.left_arm){

  }

  if(sensor.right_arm){
  }
}

void poll_sensors(Sensors *sensor)
{
  long start = millis();
  long belly = belly_cap.capacitiveSensor(30);
  // long left_arm = cs_2_4.capacitiveSensor(30);
  // long right_arm = cs_2_5.capacitiveSensor(30);

  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing
  Serial.println(belly);                  // print sensor output 1
  // Serial.print("\t");
  // Serial.print(left_arm);                  // print sensor output 2
  // Serial.print("\t");
  // Serial.println(right_arm);                // print sensor output 3

  sensor->left_arm = false;
  sensor->right_arm = false;
  sensor->belly = false;
}


