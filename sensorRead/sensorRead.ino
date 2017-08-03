//Show the value of a sensor
int ana_pin = 1;

void setup() {
  analogReference(DEFAULT); //Unnecessaty since it done by default
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(ana_pin));
  delay(500);
}
