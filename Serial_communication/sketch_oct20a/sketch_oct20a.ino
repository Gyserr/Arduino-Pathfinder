#define RED_PIN 12
#define YELLOW_PIN 10
#define GREEN_PIN 11


int LED_ARRAY[] = {RED_PIN, YELLOW_PIN, GREEN_PIN};
int arraySize = sizeof(LED_ARRAY) / sizeof(LED_ARRAY[0]);
void set_LED_pin(int pin_number){
  pinMode(pin_number, OUTPUT);
}
int blink_rate = 99;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < arraySize; i++){
    set_LED_pin(LED_ARRAY[i]);
  }
  for (int i = 0; i < arraySize; i++){
    digitalWrite(LED_ARRAY[i], LOW);
  }
}

void loop() {
  if(Serial.available() > 0){
    Serial.println("Please input a blink rate betweem 100ms and 1000ms : ");
    blink_rate = Serial.parseInt();
    while (!((blink_rate >= 100) and (blink_rate <= 1000))){
      Serial.println("Please input a blink rate betweem 100ms and 1000ms : ");
      blink_rate = Serial.parseInt();
    }
  }
  for (int i = 0; i < arraySize; i++){
    digitalWrite(LED_ARRAY[i], HIGH);
  }
  delay(blink_rate);

  for (int i = 0; i < arraySize; i++){
    digitalWrite(LED_ARRAY[i], LOW);
  }
  delay(blink_rate);

}
