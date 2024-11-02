/* Change these values based on your calibration values */
int lowerThreshold = 300;
int middleThreshold = 450;
int upperThreshold = 550;

// Sensor pins
#define sensorPower 7
#define sensorPin A0

// Value for storing water level
int val = 0;

// Declare pins to which LEDs are connected
int redLED = 5;
int yellowLED = 4;
int greenLED = 3;
int whiteLED = 2;

void setup() {
	Serial.begin(9600);
	pinMode(sensorPower, OUTPUT);
	digitalWrite(sensorPower, LOW);
	
	// Set LED pins as an OUTPUT
	pinMode(redLED, OUTPUT);
	pinMode(yellowLED, OUTPUT);
	pinMode(greenLED, OUTPUT);
  pinMode(whiteLED,OUTPUT);

	// Initially turn off all LEDs
	digitalWrite(redLED, LOW);
	digitalWrite(yellowLED, LOW);
	digitalWrite(greenLED, LOW);
  digitalWrite(whiteLED,LOW);
}

void loop() {
	int level = readSensor();

	if (level == 0) {
		Serial.println("Water Level: Empty");
    Serial.print(level);
		digitalWrite(redLED, LOW);
		digitalWrite(yellowLED, LOW);
		digitalWrite(greenLED, LOW);
    digitalWrite(whiteLED,LOW);
	}
	else if (level > 0 && level < lowerThreshold) {
		Serial.println("Water Level: Low\n");
    Serial.print(level);
		digitalWrite(redLED, HIGH);
		digitalWrite(yellowLED, LOW);
		digitalWrite(greenLED, LOW);
    digitalWrite(whiteLED,LOW);
	}
	else if (level >= lowerThreshold && level < middleThreshold) {
		Serial.println("Water Level: Medium\n");
    Serial.print(level);
		digitalWrite(redLED, LOW);
		digitalWrite(yellowLED, HIGH);
		digitalWrite(greenLED, LOW);
    digitalWrite(whiteLED,LOW);
	}
	else if (level >= middleThreshold && level < upperThreshold) {
		Serial.println("Water Level: High\n");
    Serial.print(level);
		digitalWrite(redLED, LOW);
		digitalWrite(yellowLED, LOW);
		digitalWrite(greenLED, HIGH);
    digitalWrite(whiteLED, LOW);
	}
  else if (level >= upperThreshold) {
    Serial.println("Water Level: High + \n");
    Serial.print(level);
		digitalWrite(redLED, LOW);
		digitalWrite(yellowLED, LOW);
		digitalWrite(greenLED, LOW);
    digitalWrite(whiteLED, HIGH);

  }
	delay(1000);
}

//This is a function used to get the reading
int readSensor() {
	digitalWrite(sensorPower, HIGH);
	delay(10);
	val = analogRead(sensorPin);
	digitalWrite(sensorPower, LOW);
	return val;
}