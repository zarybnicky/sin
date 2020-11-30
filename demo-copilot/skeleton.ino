void setup() {
  pinMode(8, OUTPUT);
}

void loop() {

  analogWrite(8, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}
