// pins for MD01B
int MOTOR = 3;
int INA = 5;
int INB = 4;

// pins for button control
int BWD = 12;
int FWD = 13;
int MOTOR_SPEED_POT = A5;


void setup() {
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(MOTOR, OUTPUT);
}

void loop() {
   int sensor_val = analogRead(MOTOR_SPEED_POT);
   analogWrite(MOTOR, map(sensor_val, 0, 1023, 0, 255));
  
   if(digitalRead(FWD))
   {
     digitalWrite(INA, HIGH);
     digitalWrite(INB, LOW);
   } else if(digitalRead(BWD))
   {
     digitalWrite(INA, LOW);
     digitalWrite(INB, HIGH);
   } else
   {
     digitalWrite(INA, LOW);
     digitalWrite(INB, LOW);
   }
}