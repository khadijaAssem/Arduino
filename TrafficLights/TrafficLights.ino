#define RED_LED 9
#define GREEN_LED 8
#define PUSH_BUTTON 2

volatile byte state = HIGH;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  pinMode(PUSH_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PUSH_BUTTON), INTERRUPT_HANDLER, CHANGE);
}

unsigned long timex = millis();

void loop() {
  timex = millis();
  while(millis() - timex <= 2000){
    digitalWrite(RED_LED, state);
    digitalWrite(GREEN_LED, !state);
  }
  state = !state;
}

void INTERRUPT_HANDLER(){
  state = !state;
  timex = millis();
}
