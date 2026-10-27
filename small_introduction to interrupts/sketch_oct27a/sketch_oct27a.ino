#define PB1 2

volatile unsigned long lastTimeButtonPressed = millis();
unsigned long debounceDelay = 60;
volatile bool PB1pressed = false;  // interrupt flag
int buttonCounter = 0;


void buttonPressedInterrupt(){
  unsigned long timeNow = millis();
  if (timeNow - lastTimeButtonPressed > debounceDelay){
    lastTimeButtonPressed = timeNow;
    PB1pressed = true;
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PB1, INPUT);
  // set interrupt rising
  attachInterrupt(digitalPinToInterrupt(PB1),
                  buttonPressedInterrupt,
                  RISING);
  

}

void loop() {
  // put your main code here, to run repeatedly
  // button pressed -> increase counter + print on Serial
  if(PB1pressed){
    buttonCounter += 1;
    PB1pressed = false;
    Serial.println(buttonCounter);
  }
}
