#define sol1 13
#define sol2 12
#define sol3 11
// #define inpin 2

// unsigned int delaystarttime = 20000; // THIS IS WHERE YOU ADJUST THE DELAY

int datanum=0;

boolean innew;
boolean inold;

unsigned int data[2][36] = {
  {76, 56, 101, 40, 107, 40, 108, 40, 108, 40, 113, 40, 118, 40, 122, 40, 120, 40, 123, 40, 128, 40, 137, 40, 144, 40, 227, 40, 131, 40, 136, 40, 0, 0, 0, 0}, 
  {77, 57, 103, 41, 103, 40, 108, 40, 108, 40, 115, 40, 113, 40, 116, 40, 121, 40, 122, 40, 124, 40, 127, 40, 132, 40, 135, 40, 148, 40, 269, 40, 133, 40, 149, 40}
};

int dataLength[2] = {
  32, 36
};

byte dataPosition = 0;

byte solnum = 13;

void pulse(unsigned int delaytime) {
  digitalWrite(solnum, HIGH);
  delay(40);
  digitalWrite(solnum, LOW);
  delay(delaytime-20);
  solnum--;
  if (solnum < 11){
    solnum=13;
  }

}


void setup() {
  pinMode (sol1, OUTPUT);
  pinMode (sol2, OUTPUT);
  pinMode (sol3, OUTPUT);
  // pinMode (inpin, INPUT);
  // Serial.begin(9600);
  // Serial.print("Reset. Data length:");
  // Serial.println(sizeof(data));
}

void loop() {
  // inold = innew;
  innew = (Serial.available());

  if (innew == true) {
    while (innew == true)
    {
      innew = (Serial.available());
    }

    // if (inold == false && innew == true) { // Checks to see if input has gone from low to high
    //   Serial.print(innew);
    //   Serial.println("  ");
    //   // delay(delaystarttime); // Delay time before start
    // }

    for (int i = 0; i < dataLength[dataPosition]; i++) {
      pulse(data[dataPosition][i]);
      // Serial.print(i);
      // Serial.print(": ");
      // Serial.print(data[i]);
      // Serial.print("    Next: ");
      // Serial.println(data[i+1]);
    }

    dataPosition = 1 - dataPosition;

    // Serial.println("datanum reset");
  }
}
