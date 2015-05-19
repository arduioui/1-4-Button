int pin = 13;
volatile int state = LOW; // declaration d'une variable volatile

void setup() {
  // setup code here, to run once:
  pinMode(pin, OUTPUT);
  attachInterrupt(0, blink, CHANGE); // attache l'interruption externe n0 a la fonction blink
}

void loop() {
  // main code here, to run repeatedly:
  digitalWrite(pin, state); // la LED reflete l'etat de la variable
  
  delay(1000);
}

void blink() // la fonction appelee par l'interruption externe n0
{
  state = !state; // inverse l'etat de la variable
}
