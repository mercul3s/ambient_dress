// ambient_dress.ino
int ledArray[]  = {5, 6, 9, 10, 11}; // all of our analog LED pins
int arrayLength = 5;    // length of our array of LED pins for counting
int lightSensor = 0;    // the pin our light sensor is connected to
int sensorValue, high = 0, low = 1023;         // placeholder variable for our sensor value, light min max

void setup(){
  
    Serial.begin(9600);              // initialize the serial port for debugging
    // initialize our LED pin variables to be output pins. This might not be super necessary or even work but I'm trying it anyway.
    for(int count = 0; count < arrayLength; count ++) {
        pinMode(ledArray[count], OUTPUT);
    }
}

void loop() {
    sensorValue = analogRead(lightSensor);   // get the light reading from the sensor
    int randIndex = random(0, arrayLength);  // get a random index for an LED to light up
    Serial.print(sensorValue);               // output that value to console for debugging
    autoTune();                              // tune our min and max values
    twinkle(ledArray[randIndex], 255-sensorValue);  // twinkle our random LED
}

void autoTune() {
  if (sensorValue < low) {
    low = sensorValue;
  }

  if (sensorValue > high) {
    high = sensorValue;
  }
  
  sensorValue = map(sensorValue, low, high, 0, 255);
  sensorValue = constrain(sensorValue, 0, 255);
}

int twinkle(int led, int brightness) {
  int randTime = random(0, 50);      // generate a random fade out time
  analogWrite(led, brightness);      // output to LED
  delay(randTime);                   // wait some milliseconds
  
  // loop over our values to fade out
  for(int fadeValue = brightness ; fadeValue >= 0; fadeValue -=10) {
    analogWrite(led, fadeValue);
    delay(randTime);
  }
}
