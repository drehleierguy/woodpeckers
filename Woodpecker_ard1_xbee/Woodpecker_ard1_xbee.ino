#include <DistanceGP2Y0A21YK.h>

DistanceGP2Y0A21YK Dist;

int distance = 20;        // THIS IS WHERE YOU ADJUST THE DISTANCE THRESHOLD - the higher the number, the farther away it will look for a trigger

const int dirpin = 12;    // Tells the driver what direction to rotate.
const int steppin = 13;   // Tells the driver to step.
// const int signalsign = Serial.println("1");  // Tells Arduino 2 (sign) to begin 

int steps[] = {756, 844};  // Number of steps (one revolution = 1600 steps).

int rpm = 6;  // Speed at which motor turns.
long stepdelay = (60*1000000)/(rpm * 1600); // Microseconds per step.
int rampup = 10;  // Number of steps to speed up and slow down at half speed.

int readDist = distance + 1;

bool nextRotation = false; // Which amount of steps to turn the disk (true is 756, false if 844 - see line 11)

void setup() {
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  // pinMode(signalsign, OUTPUT);
  Serial.begin(9600);
  Dist.begin(A0);
  digitalWrite(dirpin, HIGH);     // Set the direction.
}
void loop() {
  readDist = Dist.getDistanceCentimeter();
  if (readDist < distance) { // If [get distance in cm] is less than [distance variable], then set begin motor sequence

    spinDisk();
    delay(random(2000, 4000));
    spinDisk();
    delay(random(2000, 4000));

    while (readDist < distance) {

      readDist = Dist.getDistanceCentimeter();
      
      triggerSign();
      delay(random(2000, 4000));

      for (int i = 0; i < random(2, 3); i++) {   //  randomizes how many times the turntable turns between 1 and 2 times
        spinDisk();
        delay(random(2000, 4000));      //  random delay values - currenly between 2 - 4 seconds
      }
    }
  }
}

void spinDisk() {
  int i;
  if (nextRotation)
  {
    // Serial.println("Part 1");
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

    nextRotation = false;
  } 
  else {
    // Serial.println("Part 2");
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

    nextRotation = true;
  }
}

void triggerSign() {
  // digitalWrite(signalsign, HIGH);
  // delay(10);
  // digitalWrite(signalsign, LOW);
  Serial.print("1");
  delay(5000);                     // TO BE ADJUSTED based on time it takes for the second arduino (sign) to complete
}
