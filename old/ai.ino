///////////////////////////////////////////////////
//  			        PINS                     //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
////			       STRUCTS                   //
///////////////////////////////////////////////////

// expandable sensor structure
struct Sensors {
	boolean left_arm;
	boolean right_arm;
	boolean belly;
	// add integer, char, and other values
};

struct Action {
	boolean (*listener)(void *self, Sensors *sensor);
	void (*perform)(void);
};

///////////////////////////////////////////////////
//  			     LISTENERS                   //
///////////////////////////////////////////////////

boolean belly_listener(void *self, Sensors *sensor)
{
	return true;
}

boolean left_arm_listener(void *self, Sensors *sensor){
	return true;
}

boolean right_arm_listener(void *self, Sensors *sensor){
	return true;
}

///////////////////////////////////////////////////
//  			      ACTIONS                    //
///////////////////////////////////////////////////

// open/close arms
void open_left_arm(void){

}

void close_left_arm(void){

}

void open_right_arm(void){

}

void close_right_arm(void){

}

void open_both_arms(void){

}

void close_both_arms(void){
	
}

void wave_left_arm(void){

}

void wave_right_arm(void){

}

void wave_both_arms(void){

}

// move body
void open_body(void){

}

void close_body(void){

}

///////////////////////////////////////////////////
//  			   ARDUINO MAIN                  //
///////////////////////////////////////////////////

// Initialize body sensors
Sensors sensor;

void poll_sensors(Sensors *sensor)
{
	sensor->left_arm = true;
	sensor->right_arm = true;
	sensor->belly = true;
}

void setup() 
{
	Serial.begin(9600);
}

void loop() 
{
	poll_sensors(&sensor);
}


