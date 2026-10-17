int bpm = 30;
int beatDuration = 60000 / bpm;
int lubDuration = 0.10 * beatDuration;
int dubDuration = 0.10 *  beatDuration;
int shortGap = 0.2 * beatDuration;
int longGap = 0.6 * beatDuration;

void setup() {
  pinMode(8, OUTPUT);
  
}

void loop() {
  digitalWrite(8, HIGH);
  delay(lubDuration);

  digitalWrite(8, LOW);
  delay(shortGap);

  digitalWrite(8, HIGH);
  delay(dubDuration);

  digitalWrite(8, LOW);
  delay(longGap);
}