

/*
Name:		V0.1 ino
Created:	7/8/2019 6:05:42 PM
Author:	Fernando
*/

#define USE_ARDUINO_INTERRUPTS true


//Libraries
#include <PulseSensorPlayground.h>



//Variables       
int Threshold = 550;

//Analog Pins
const int PulseWire = A1;

//Digital Pins
int Injector1 = 2;   // 25% Power Reduction
int Injector2 = 3;   // 50% Power Reduction (When Both Relays Activate)

int Red_LED = 11;    // LED (Red)
int Yellow_LED = 10; // LED (Yellow)
int Green_LED = 9;   // LED (Green)

int Buzzer = 8;      // Buzzer 



//Instances
PulseSensorPlayground pulseSensor;

void setup() 
{
	
	Serial.begin(9600); // Debugging & Development
	delay(2000);

	// Initialize sensor
	pulseSensor.analogInput(PulseWire);
	pulseSensor.setThreshold(Threshold);
	
	// Injector Relays
	pinMode(Injector1, OUTPUT);
	digitalWrite(Injector1, HIGH);
	pinMode(Injector2, OUTPUT);
	digitalWrite(Injector2, HIGH);

	// Indicators (Led's,BBuzzers,etc.)
	pinMode(Buzzer, OUTPUT);
	digitalWrite(Buzzer, HIGH);
	digitalWrite(Buzzer, LOW);

	
	{
		// Loading.....(Indicating)
		digitalWrite(Green_LED, HIGH);
		delay(100);
		digitalWrite(Green_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Red_LED, HIGH);
		delay(100);
		digitalWrite(Red_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Green_LED, HIGH);
		delay(100);
		digitalWrite(Green_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Red_LED, HIGH);
		delay(100);
		digitalWrite(Red_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Green_LED, HIGH);
		delay(100);
		digitalWrite(Green_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Red_LED, HIGH);
		delay(100);
		digitalWrite(Red_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Green_LED, HIGH);
		delay(100);
		digitalWrite(Green_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Red_LED, HIGH);
		delay(100);
		digitalWrite(Red_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		
	}

	if (pulseSensor.begin())
	{
		
		delay(1000);

		// Turn Loading Indicators OFF
		digitalWrite(Red_LED, LOW);
		digitalWrite(Yellow_LED, LOW);
		digitalWrite(Green_LED, LOW);

		//Initialize Sensors, Buzz 3x Indicating, Ready To Go.
		Serial.println("Sensor Has Initialized");
		digitalWrite(Buzzer, HIGH);
		delay(100);
		digitalWrite(Buzzer, LOW);
		delay(100);
		digitalWrite(Buzzer, HIGH);
		delay(100);
		digitalWrite(Buzzer, LOW);
		delay(100);
		digitalWrite(Buzzer, HIGH);
		delay(100);
		digitalWrite(Buzzer, LOW);
	}

}

void loop()
{
	

	// Start Reading Average Heart Rate 
	//=================================================================================================================================================================================================================================

	int myBPM = pulseSensor.getBeatsPerMinute(); // Pulse Sensor
	

	if (pulseSensor.sawStartOfBeat())
	{
		Serial.print("-----BPM: ");
		Serial.println(myBPM);
		digitalWrite(Green_LED, HIGH);
	}

	if (myBPM > 250)
	{
		digitalWrite(Green_LED, LOW);
		digitalWrite(Yellow_LED, HIGH);
	}




	//=================================================================================================================================================================================================================================

	if (myBPM = 0) // No Heart Rate
	{
		digitalWrite(Injector1, LOW);
		digitalWrite(Injector2, LOW);
		digitalWrite(Yellow_LED, HIGH);
		digitalWrite(Red_LED, LOW);
		digitalWrite(Buzzer, LOW);
		delay(1000);
	}

	if (myBPM < 67 ) // Low Heart Rate (Yellow )
	{
		digitalWrite(Injector1, LOW);
		digitalWrite(Injector2, LOW);
		digitalWrite(Green_LED, LOW);
		digitalWrite(Yellow_LED, HIGH);
		digitalWrite(Red_LED, LOW);
		digitalWrite(Buzzer, LOW);
		delay(1000);
	}

	if (myBPM > 67 && myBPM < 160) // Normal Heart Rate (Green Led)
	{
		digitalWrite(Injector1, LOW);
		digitalWrite(Injector2, LOW);
		digitalWrite(Green_LED, HIGH);
		digitalWrite(Yellow_LED, LOW);
		digitalWrite(Red_LED, LOW);
	}

	if (myBPM > 160 ) // Stressed Heart Rate (Red Led)
	{
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);
		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);


		delay(5000);
		digitalWrite(Injector1, HIGH);
		digitalWrite(Injector2, HIGH);
		digitalWrite(Green_LED, LOW);
		digitalWrite(Yellow_LED, LOW);
		digitalWrite(Red_LED, HIGH);

	}

	//=================================================================================================================================================================================================================================

}