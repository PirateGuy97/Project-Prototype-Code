#include "Adafruit_DHT.h"


// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, modified by PirateGuy97

#define DHTPIN 7     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11 
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);
int cold = 10; //Minimum value of desired temperature range
int hot = 35; //Maximum value of desired temperature range
int ledCold = D3; //"Too Cold" light
int ledHot = D5; //"Too hot" light

void setup() {
	dht.begin();
	pinMode(ledCold, OUTPUT);
	pinMode(ledHot, OUTPUT);
}

void loop() {
    delay(5000);
    digitalWrite(ledCold, LOW);
    digitalWrite(ledHot, LOW);
	float temp = dht.getTempCelcius();
	if (temp < cold)
	{
	    digitalWrite(ledCold, HIGH);
	}
	else if (temp > hot)
	{
	    digitalWrite(ledHot, HIGH);
	}
	String temperature = String(temp);

    Particle.publish("temperature", temperature, PRIVATE);
}

