#include <Arduino.h>

class TEMT6000 {
	int pinId = 0;

public:
	void Init (int inPinId)
	{
		pinId = inPinId;
		pinMode (pinId, INPUT);
	}

	int GetValue () const // 0..1023
	{
		analogReadResolution (10);
		return analogRead (pinId);
	}
} temt6000;


void setup () 
{
	Serial.begin (115200);
	temt6000.Init (15);
}


void loop () 
{
	Serial.println ("Value: " + String (temt6000.GetValue ()));
	delay (100);
}
