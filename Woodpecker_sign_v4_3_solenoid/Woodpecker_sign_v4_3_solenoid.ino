// sketch that runs the solenoids on the sign



// constants won't change. Used here to 
// set pin numbers:
const int sol1 =  13;      // the number of the output pin which triggers the solenoid
const int sol2 =  12;
//const int sol3 =  11;

// Variables will change:
long previousMillis1 = 0;        // will store last time LED was updated
long previousMillis2 = 0;        // will store last time LED was updated
//long previousMillis3 = 0;

// initial delay
int initdelay = 0*1000;

long data1[] = {
  233, 184, 252, 179, 273, 186, 284, 204.5, 407, 203, 15172, 237, 182, 251, 182, 263, 188, 280, 193, 299, 216, 439, 220, 16000 };

long data2[] = {
  76, 197, 252, 178, 263, 188, 276, 194, 315.5, 300, 302, 15113, 201, 249, 176, 262, 183, 277, 191, 292, 199, 453, 204, 16186 };

long data3[] = {
  132, 248, 181, 255, 183, 275, 189, 298, 214.5, 395, 207, 15134, 247, 181, 256, 181, 270, 190, 284, 197, 315, 342, 316, 16037 };

int datanum1 = 0;
int datanum2 = 0;
//int datanum3 = 0;

void setup() {
  // set the digital pin as output:
  pinMode(sol1, OUTPUT);
  pinMode(sol2, OUTPUT);
  //  pinMode(sol2, OUTPUT);
  Serial.begin(9600);
  Serial.println("beginning...");
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
    Serial.print(data1[datanum1 -1]);
    Serial.print(", ");
  }
  if (datanum1 > sizeof(data1)) {
    datanum1 = 0;
  }





  if(currentMillis - previousMillis2+50 > data2[datanum2 -1]) { 

    // set the LED with the ledState of the variable:
    digitalWrite(sol2, HIGH);
  }

  if(currentMillis - previousMillis2 > data2[datanum2 -1] ) {
    // save the last time you blinked the LED 
    previousMillis2 = currentMillis;   

    // set the LED with the ledState of the variable:
    digitalWrite(sol2, LOW);
    datanum2++;
    Serial.print(data2[datanum2 -1]);
    Serial.print("--- ");
  }
  if (datanum2 > sizeof(data2)) {
    datanum2 = 0;
  }


  /*

   if(currentMillis - previousMillis3+50 > data3[datanum3 -1]) { 
   
   // set the LED with the ledState of the variable:
   digitalWrite(sol3, HIGH);
   }
   
   if(currentMillis - previousMillis3 > data3[datanum3 -1] ) {
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
   */
}









