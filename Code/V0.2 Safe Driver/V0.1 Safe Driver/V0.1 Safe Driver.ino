

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
int threshold = 0;
int GSRsensorValue;

//Analog Pins
const int PulseWire = A1;
const int GSR = A0;

//Digital Pins
int Injector1 = 9;   // 25% Power Reduction
//int Injector2 = ;   // 50% Power Reduction (When Both Relays Activate)
int Red_LED = 6;    // LED (Red)
int Yellow_LED = 7; // LED (Yellow)
int Green_LED = 8;   // LED (Green)
int Buzzer = 5;      // Buzzer 

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
	/*pinMode(Injector2, OUTPUT);
	digitalWrite(Injector2, HIGH);*/

	// Indicators (Led's,BBuzzers,etc.)
	pinMode(Buzzer, OUTPUT);
	digitalWrite(Buzzer, HIGH);
	digitalWrite(Buzzer, LOW);

	// GSR Sensor
	long sum = 0;

for (int i = 0; i < 500; i++)
{
	GSRsensorValue = analogRead(GSR);
	sum += GSRsensorValue;
	delay(5);
}
	threshold = sum / 500;
	


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

		GSRsensorValue = analogRead(GSR);
		Serial.print("sensorValue=");
		Serial.println(GSRsensorValue);

		digitalWrite(Green_LED, HIGH);
	}




	//=================================================================================================================================================================================================================================


	if (myBPM > 67 && myBPM < 100) // Normal Heart Rate (Green Led)
	{
		digitalWrite(Injector1, HIGH);
		//digitalWrite(Injector2, LOW); // Not Used
		digitalWrite(Green_LED, HIGH);
		digitalWrite(Yellow_LED, LOW);
		digitalWrite(Red_LED, LOW);
	}


	if (myBPM > 100) // Stressed Heart Rate (Red Led)
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

		if (GSRsensorValue < 80)
		{
			delay(500);
			digitalWrite(Injector1, LOW);
			//digitalWrite(Injector2, HIGH); // Not Used
			digitalWrite(Green_LED, LOW);
			digitalWrite(Yellow_LED, LOW);
			digitalWrite(Red_LED, HIGH);
		}

		else

			digitalWrite(Injector1, HIGH);

	}






}



