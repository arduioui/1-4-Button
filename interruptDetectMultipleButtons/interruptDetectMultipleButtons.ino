#define inter 2 // pull-up IN
#define buttonA 3 // pull-up IN
#define buttonB 4 // pull-up IN
#define buttonC 5 // pull-up IN
#define buttonD 6 // pull-up IN

int countA = 0;
int countB = 0;
int countC = 0;
int countD = 0;
boolean state=false;
void setup() {
  // setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonC, INPUT);
  pinMode(buttonD, INPUT);
  pinMode(inter, INPUT);
  
  // to avoid using Resistor
  digitalWrite(buttonA, HIGH);
  digitalWrite(buttonB, HIGH);
  digitalWrite(buttonC, HIGH);
  digitalWrite(buttonD, HIGH);  
  digitalWrite(inter, HIGH);

  attachInterrupt(0, detect, FALLING);  
}

void loop() {
  // main code here, to run repeatedly:
  Serial.print("A >");
  Serial.println(countA);
  Serial.print("B >");
  Serial.println(countB);
  Serial.print("C >");
  Serial.println(countC);
  Serial.print("D >");
  Serial.println(countD);
  delay(1000);
}

void detect() {
  state = !state;
  if (digitalRead(buttonA) == LOW) countA++;
  if (digitalRead(buttonB) == LOW) countB++;
  if (digitalRead(buttonC) == LOW) countC++;
  if (digitalRead(buttonD) == LOW) countD++;
}
