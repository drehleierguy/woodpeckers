#include <DistanceGP2Y0A21YK.h>

DistanceGP2Y0A21YK Dist;


const int dirpin = 12;   // Tells the driver what direction to rotate.
const int steppin = 13;  // Tells the driver to step.
const int signalsign = 2;// Tells Arduino 2 (sign) to begin 

int steps[] = {756, 844};                             // Number of steps (one revolution = 1600 steps).

int rpm = 6;                                   // Speed at which motor turns.
long stepdelay = (60*1000000)/(rpm * 1600); // Microseconds per step.
int rampup = 10;                               // Number of steps to speed up and slow down at half speed.

void setup() 
{
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  pinMode(signalsign, OUTPUT);
  Serial.begin(9600);
  Dist.begin(A0);
}
void loop()
{
  if(Dist.getDistanceCentimeter() < 30) { // If [get distance in cm] is less than 30cm, then set begin motor sequence
    digitalWrite(signalsign, HIGH); // Turn signal pin on

    Serial.print( "Distance: ");
    Serial.println( Dist.getDistanceCentimeter() );
    int i;

    digitalWrite(dirpin, HIGH);     // Set the direction.
    Serial.println("Part 1");
    for (i = 0; i<rampup; i++) {      // Iterate for 'rampup' microsteps.
      digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(stepdelay * 2);      // This runs at half normal speed.
    }           

    for (i = 0; i<steps[0] - (2*rampup); i++) {      // Iterate for the number of microsteps minus the steps taken at half speed.
      digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(stepdelay);      // This delay time is close to top speed for this
    }                                    // particular motor. Any faster and the motor stalls.

    for (i = 0; i<rampup; i++) {   // Iterate for 'rampup' microsteps.
      digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(stepdelay * 2);      // This runs at half normal speed.
    }       

    delay(14000+random(2000));                   // Waits for between 14 and 16 seconds.

    Serial.println("Part 2");
    for (i = 0; i<rampup; i++) {      // Iterate for 'rampup' microsteps.
      digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(stepdelay * 2);      // This runs at half normal speed.
    }           

    for (i = 0; i<steps[1] - (2*rampup); i++) {      // Iterate for the number of microsteps minus the steps taken at half speed.
      digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(stepdelay);      // This delay time is close to top speed for this
    }                                    // particular motor. Any faster and the motor stalls.

    for (i = 0; i<rampup; i++) {   // Iterate for 'rampup' microsteps.
      digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(stepdelay * 2);      // This runs at half normal speed.
    }

    delay(14000+random(2000));                   // Waits for between 14 and 16 seconds.


  } 
  else {
    digitalWrite(signalsign, LOW); // Turn signal pin off
  }
}




