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
const int ledPin3 =  11;

// Variables will change:
long previousMillis1 = 0;        // will store last time LED was updated
long previousMillis2 = 0;        // will store last time LED was updated
long previousMillis3 = 0;

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.

/*long data1[] = {
  1024, 512, 512, 128, 128, 128, 128, 64,64,64,64,64,64,64,64 };

long data2[] = {
  400, 80, 90, 100, 110, 120, 130, 140,150,160,170,190,190,200 };
  
long data3[] = {
  400, 80, 90, 100, 110, 120, 130, 140,150,160,170,190,190,200 };*/
  
  
long data1[] = {
  233, 184, 252, 179, 273, 186, 284, 205, 407, 203, 15172, 237, 182, 251, 182, 263, 188, 280, 193, 299, 216, 439, 220, 16000 };

long data2[] = {
  76, 197, 252, 178, 263, 188, 276, 194, 316, 300, 302, 15113, 201, 249, 176, 262, 183, 277, 191, 292, 199, 453, 204, 16186 };

long data3[] = {
  132, 248, 181, 255, 183, 275, 189, 298, 215, 395, 207, 15134, 247, 181, 256, 181, 270, 190, 284, 197, 315, 342, 316, 16037 };





int datanum1 = 0;
int datanum2 = 0;
int datanum3 = 0;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
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

  if(currentMillis - previousMillis1+40 > data1[datanum1 -1]) { 

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, HIGH);
  }

  if(currentMillis - previousMillis1 > data1[datanum1 -1] ) {
    // save the last time you blinked the LED 
    previousMillis1 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, LOW);
    datanum1++;
    //Serial.println(data1[datanum1 -1]);
  }
  if (datanum1 > 23) {
    datanum1 = 0;
  }
  
  
  
  
  
  if(currentMillis - previousMillis2+50 > data2[datanum2 -1]) { 

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin2, HIGH);
  }

  if(currentMillis - previousMillis2 > data2[datanum2 -1] ) {
    // save the last time you blinked the LED 
    previousMillis2 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin2, LOW);
    datanum2++;
    Serial.println(data2[datanum2 -1]);
  }
  if (datanum2 > 23) {
    datanum2 = 0;
  }
  
  
  
  if(currentMillis - previousMillis3+50 > data3[datanum3 -1]) { 

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin3, HIGH);
  }

  if(currentMillis - previousMillis3 > data3[datanum3 -1] ) {
    // save the last time you blinked the LED 
    previousMillis3 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin3, LOW);
    datanum3++;
    Serial.println(data3[datanum3 -1]);
  }
  if (datanum3 > 23) {
    datanum3 = 0;
  }
}







