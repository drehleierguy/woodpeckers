#define sol1 13
#define sol2 12
#define sol3 11
#define inpin 2

unsigned int delaystarttime = 20000; // THIS IS WHERE YOU ADJUST THE DELAY

int datanum=0;

boolean innew;
boolean inold;

unsigned int data[] = {
  76, 56, 101, 40, 107, 40, 108, 40, 108, 40, 113, 40, 118, 40, 122, 40, 120, 40, 123, 40, 128, 40, 137, 40, 144, 40, 227, 40, 131, 40, 136, 40, 15000, 77, 57, 103, 41, 103, 40, 108, 40, 108, 40, 115, 40, 113, 40, 116, 40, 121, 40, 122, 40, 124, 40, 127, 40, 132, 40, 135, 40, 148, 40, 269, 40, 133, 40, 149, 40, 16000};


byte solnum = 13;

int pulse(unsigned int delaytime) {
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
  pinMode (inpin, INPUT);
  Serial.begin(9600);
  Serial.print("Reset. Data length:");
  Serial.println(sizeof(data));
}

void loop() {
  inold = innew;
  innew = digitalRead(inpin);
  if (innew == true) {

    if (inold == false && innew == true) { // Checks to see if input has gone from low to high
      Serial.print(innew);
      Serial.println("  ");
      delay(delaystarttime); // Delay time before start
    }

    for(int blah = 0; blah < 69; blah++) {
      pulse(data[blah]);
      Serial.print(blah);
      Serial.print(": ");
      Serial.print(data[blah]);
      Serial.print("    Next: ");
      Serial.println(data[blah+1]);
    }
    Serial.println("datanum reset");
  }
}
