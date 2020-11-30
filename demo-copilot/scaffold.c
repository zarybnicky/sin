void writeOut(uint32_t d) {
  Serial.println(d);
}

void play(uint32_t note, uint32_t duration) {
  tone(8, note, duration);
  delay(duration * 1.2);
  noTone(8);
}

void setup(void) {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop(void) {
  step();
}
