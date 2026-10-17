#define POTENTIOMETER_PIN A2
#define RED_PIN 12
#define YELLOW_PIN 10
#define GREEN_PIN 11
void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RED_PIN, HIGH);
  delay(3000);
  digitalWrite(RED_PIN, LOW);
  delay(1);
  digitalWrite(GREEN_PIN, HIGH);
  delay(3000);
  digitalWrite(GREEN_PIN, LOW);
  delay(1);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(2000);
  digitalWrite(YELLOW_PIN, LOW);
  delay(1);
}