int MOTOR = 3; // d3
int INB = 4; // d4
int INA = 7; // d7

// pins for button control
int BWD = 11; // d11
int FWD = 12; //d12
int MOTOR_SPEED_POT = A5;
int LED = 13;


void setup() {
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(LED, OUTPUT);

  pinMode(BWD, LOW);
  pinMode(FWD, LOW);
}

void loop() {
 int sensor_val = analogRead(MOTOR_SPEED_POT);
 analogWrite(MOTOR, map(sensor_val, 0, 1023, 0, 255));

 if(digitalRead(FWD))
 {
   digitalWrite(INA, HIGH);
   digitalWrite(INB, LOW);
   digitalWrite(LED, HIGH);
 } else if(digitalRead(BWD))
 {
   digitalWrite(INA, LOW);
   digitalWrite(INB, HIGH);
   digitalWrite(LED, HIGH);
 } else
 {
   digitalWrite(INA, LOW);
   digitalWrite(INB, LOW);
   digitalWrite(LED, LOW);
 }
 
}
