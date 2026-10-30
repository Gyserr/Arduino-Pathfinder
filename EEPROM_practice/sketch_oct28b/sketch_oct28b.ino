#include <EEPROM.h>
#define POTENTIOMETER_PIN A2
#define LED_PIN 10

int max_brightness;
int brightness;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  max_brightness = EEPROM.read(3);
  Serial.println(max_brightness);
}

void loop() {
  // put your main code here, to run repeatedly:
  // LED on PIN 10 - fade in/out from potenitiometer
  // max intensity from serial input
  // Save max intensity to EEPROM
  if (Serial.available()> 0){
     max_brightness = Serial.parseInt();
     EEPROM.update(3, max_brightness);
  }
  brightness = (analogRead(POTENTIOMETER_PIN)) / 4;
  if (brightness <= max_brightness){
    analogWrite(LED_PIN, brightness);
    Serial.println(analogRead(POTENTIOMETER_PIN) / 4);
  }
  else{
    Serial.print("Maximum Brightness reached of: ");
    Serial.println(max_brightness);
  }
}
