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
  // account for how servo is installed in otter
  larm.write(angle);
}

void open_left_arm(void){
	move_left_arm(180);
}

void close_left_arm(void){
	move_left_arm(0);
}

void move_right_arm(int angle){
  rarm.write(map(angle, 0, 180, 180, 0));
}

void open_right_arm(void){
	move_right_arm(180);
}

void close_right_arm(void){
	move_right_arm(0);
}

void close_both_arms(void){
	close_left_arm();
	close_right_arm();
}

void open_both_arms(void){
	open_left_arm();
	open_right_arm();
}

void point_left(){
	open_left_arm();
	close_right_arm();
}

void point_right(){
	close_left_arm();
	open_right_arm();
}

void open_body(int delay_time){
  // turn on motors
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  delay(delay_time);
  // turn off motors
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
}

void close_body(int delay_time){
  // turn on motors
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  delay(delay_time);
  // turn off motors
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
}

void left_wave(void){
	for(int i=0; i< 2; i++){
		open_left_arm();
		delay(500);
		close_left_arm();	
		delay(500);            
	}  
}

void right_wave(void){
	for(int i=0; i< 2; i++){
		open_right_arm();
		delay(500);
		close_right_arm();	
		delay(500);            
	}  
}

void hug(void){
	close_both_arms();
	close_body(1000);
	delay(random(750, 2500));
	open_both_arms();
	open_body(1000);
}

void jiggle(void){
	for(int i=0; i<4; i++){
		open_body(500);
		close_body(500);
	}  
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

void loop() {
	int motor_val = analogRead(MOTOR_SPEED_POT);
	analogWrite(MOTOR, map(motor_val, 0, 1023, 0, 180));

	// for(int i = 0; i < 2; i++){
	// 	close_body(1000);
	// 	open_body(1000);
	// }

	// for(int i = 0; i < 2; i++){
	// 	open_both_arms();
	// 	delay(1000);
	// 	close_both_arms();
	// 	delay(1000);
	// }

	// for(int i = 0; i < 2; i++){
	// 	point_right();
	// 	delay(1000);
	// 	point_left();
	// 	delay(1000);
	// }

	// close_both_arms();

	switch (random(0, 3)) {
		case 0:
			hug();
			break;
		case 1:
			left_wave();
			break;
		case 2:
			right_wave();
		case 3:
		case 4:
			jiggle();
			break;
		case 5:
		default: 
			delay(random(500, 2000));
			break;
	}
}