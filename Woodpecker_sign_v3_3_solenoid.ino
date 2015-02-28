// sketch that runs the solenoids on the sign
 


// constants won't change. Used here to 
// set pin numbers:
const int sol1 =  13;      // the number of the output pin which triggers the solenoid
const int sol2 =  12;
const int sol3 =  11;

// Variables will change:
long previousMillis1 = 0;        // will store last time LED was updated
long previousMillis2 = 0;        // will store last time LED was updated
long previousMillis3 = 0;


long data1[] = {
  1024, 512, 512, 128, 128, 128, 128, 64,64,64,64,64,64,64,64 };

long data2[] = {
  400, 80, 90, 100, 110, 120, 130, 140,150,160,170,190,190,200 };
  
long data3[] = {};

int datanum1 = 0;
int datanum2 = 0;
int datanum3 = 0;

void setup() {
  // set the digital pin as output:
  pinMode(sol1, OUTPUT);
  pinMode(sol2, OUTPUT);
  pinMode(sol2, OUTPUT);
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
    digitalWrite(sol1, HIGH);
  }

  if(currentMillis - previousMillis1 > data1[datanum1 -1] ) {
    // save the last time you blinked the LED 
    previousMillis1 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(sol1, LOW);
    datanum1++;
    //Serial.println(data1[datanum1 -1]);
  }
  if (datanum1 > sizeof(data1)) {
    datanum1 = 0;
  }
  
  
  
  
  
  if(currentMillis - previousMillis2 > data1[datanum2 -1]) { 

    // set the LED with the ledState of the variable:
    digitalWrite(sol2, HIGH);
  }

  if(currentMillis - previousMillis2+50 > data2[datanum2 -1] ) {
    // save the last time you blinked the LED 
    previousMillis2 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(sol2, LOW);
    datanum2++;
    Serial.println(data2[datanum2 -1]);
  }
  if (datanum2 > sizeof(data2)) {
    datanum2 = 0;
  }
  
  
  
  
   if(currentMillis - previousMillis3 > data1[datanum3 -1]) { 

    // set the LED with the ledState of the variable:
    digitalWrite(sol3, HIGH);
  }

  if(currentMillis - previousMillis3+50 > data2[datanum3 -1] ) {
    // save the last time you blinked the LED 
    previousMillis3 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(sol3, LOW);
    datanum3++;
    Serial.println(data3[datanum3 -1]);
  }
  if (datanum3 > sizeof(data3)) {
    datanum3 = 0;
  }
}







