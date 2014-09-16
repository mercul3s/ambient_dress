// ambient_dress.ino
int ledArray[]  = {5, 6, 9, 10, 11}; // all of our analog LED pins
int arrayLength = 5;    // length of our array of LED pins for counting
int lightSensor = 13;   // the pin our light sensor is connected to
int lightValue;

void setup(){
    Serial.begin(9600);              // initialize the serial port for debugging

    // initialize our LED pin variables to be output pins. This might not be super necessary or even work but I'm trying it anyway.
    for(int count = 0; count < arrayLength; count ++) {
        pinMode(ledArray[count], OUTPUT);
    }
}

void loop() {
    lightValue = digitalRead(lightSensor); // get the light reading from the sensor
    
    Serial.print(lightValue);                  // output that value to console for debugging
}
