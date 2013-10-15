int LARM_PIN = 2;
int RARM_PIN = 3;

int LARM_POT = 4;
int RARM_POT = 5;

void setup() 
{
	pinMode(LARM_PIN, OUTPUT);
	pinMode(RARM_PIN, OUTPUT);
}

void loop() 
{
	int larm_val = analogRead(LARM_POT);
	analogWrite(LARM_PIN, map(larm_val, 0, 1023, 0, 255)); 

	int rarm_val = analogRead(RARM_POT);
	analogWrite(RARM_POT, map(rarm_val, 0, 1023, 0, 255)); 	
}