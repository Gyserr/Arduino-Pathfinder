#define LED_PIN 12
#define GREEN_LED_PIN 11
#define YELLOW_LED_PIN 10
#define POTENTIOMETER A2
#define push_button 2
unsigned long previousTime = 0;

int LEDState = LOW;
int data;
int LED_brightness;
bool Button_state;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER, INPUT);
  pinMode(push_button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Button_state = digitalRead(push_button);
  if(Button_state){
    digitalWrite(GREEN_LED_PIN, Button_state);
  }
  else{
   digitalWrite(GREEN_LED_PIN, LOW);
  } 
  LED_brightness = analogRead(A2) / 4;
  analogWrite(YELLOW_LED_PIN, LED_brightness);
  unsigned long timeNow = millis();
  if (Serial.available() > 0){
    data = Serial.parseInt();
  }
  if((data >= 100) && (data <= 4000)){
    if ((timeNow - previousTime) >= data){
      if (LEDState == HIGH){
          LEDState = LOW;
          }
      else{
          LEDState = HIGH;
        }
        digitalWrite(LED_PIN, LEDState);
        previousTime = timeNow;
      }
      
    }
  } 
// Set LED2 (pin 11) brightness from potentiometer
// Power on led 3 when button is press pressed