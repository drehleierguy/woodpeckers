/* Blink without Delay
 
 Turns on and off a light emitting diode(LED) connected to a digital  
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 
 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 
 This example code is in the public domain.
 
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int ledPin1 =  13;      // the number of the LED pin
const int ledPin2 =  12;

// Variables will change:
long previousMillis1 = 0;        // will store last time LED was updated
long previousMillis2 = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval1 = 1000;           // interval at which to blink (milliseconds)
long interval2 = 1010;

long data1[] = {
  1000, 500, 500, 125, 125, 125, 125};
  
int datanum = 0;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);  
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis1+60 > data1[datanum-1]) { 

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, HIGH);
  }

  if(currentMillis - previousMillis1 > data1[datanum-1] ) {
    // save the last time you blinked the LED 
    previousMillis1 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, LOW);
    datanum++;
    Serial.println(data1[datanum-1]);
  }
  if (datanum > 6) {
    datanum = 0;
  }
}






